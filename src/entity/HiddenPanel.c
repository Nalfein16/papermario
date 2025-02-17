#include "common.h"
#include "ld_addrs.h"
#include "entity.h"

s32 entity_HiddenPanel_is_item_on_top(Entity*);
void entity_HiddenPanel_flip_over(Entity*);

void mdl_project_tex_coords(s32 modelID, Gfx* destGfx, Matrix4f destMtx, void* destVertices);
s32 npc_find_standing_on_entity(s32 entityIndex);

extern s32 Entity_HiddenPanel_RenderScript2[];

extern Gfx Entity_HiddenPanel_RenderTop[];
extern Gfx Entity_HiddenPanel_RenderTop2[];
extern Gfx Entity_HiddenPanel_RenderBottomDark[];
extern Gfx Entity_HiddenPanel_Render[];
extern Gfx Entity_HiddenPanel_Render2[];

void entity_HiddenPanel_setupGfx(s32 entityIndex) {
    Entity* entity = get_entity_by_index(entityIndex);
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    Matrix4f sp10;
    Matrix4f sp50;

    if (entity->position.y != data->initialY) {
        guMtxIdentF(sp10);
        guTranslateF(sp50, entity->position.x, data->initialY + 1.0f, entity->position.z);
        guMtxCatF(sp50, sp10, sp50);
        guMtxF2L(sp50, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gMasterGfxPos++, ENTITY_ADDR(entity, Gfx*, Entity_HiddenPanel_RenderBottomDark));
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }
    mdl_project_tex_coords(data->modelID, data->renderDList, data->entityMatrix, entity->gfxBaseAddr);
    mdl_draw_hidden_panel_surface(&gMasterGfxPos, data->modelID);
}

void entity_HiddenPanel_set_ispy_notification(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;

    if (is_ability_active(ABILITY_I_SPY) && !get_global_flag(data->pickupVar) && !D_8015A578.unk_02) {
        D_8015A578.unk_02 = TRUE;
    }
}

void entity_HiddenPanel_hide(Entity* entity) {
    entity->flags &= ~ENTITY_FLAGS_DISABLE_COLLISION;
    entity->flags |= ENTITY_FLAGS_HIDDEN;
}

void entity_HiddenPanel_idle(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    s32 distToPlayer;

    if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
        if (!data->unk_04) {
            data->unk_04 = TRUE;
            func_800EF3D4(1);
        }
    } else {
        data->unk_04 = FALSE;
    }

    data->standingNpcIndex = -1;
    data->npcFlags = 0;

    if (D_8015A578.unk_00 && fabs(D_8015A578.unk_08 - entity->position.y) <= 10.0) {
        data->state = 10;
        distToPlayer = get_xz_dist_to_player(entity->position.x, entity->position.z);
        if (distToPlayer <= 100) {
            if (entity->collisionFlags & ENTITY_COLLISION_PLAYER_TOUCH_FLOOR) {
                data->riseVelocity = 0.5f;
                exec_entity_commandlist(entity);
            } else if (entity_HiddenPanel_is_item_on_top(entity)) {
                data->riseVelocity = 0.5f;
                exec_entity_commandlist(entity);
            } else {
                s32 npcIndex = npc_find_standing_on_entity(entity->listIndex);
                if (npcIndex >= 0) {
                    Npc* npc = get_npc_by_index(npcIndex);
                    dist2D(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
                    data->standingNpcIndex = npcIndex;
                    data->npcFlags = npc->flags & (NPC_FLAG_GRAVITY | NPC_FLAG_ENABLE_HIT_SCRIPT);
                    npc->flags &= ~NPC_FLAG_ENABLE_HIT_SCRIPT;
                    npc->flags |= NPC_FLAG_GRAVITY;
                    data->riseVelocity = 0.5f;
                    exec_entity_commandlist(entity);
                } else {
                    entity->flags |= ENTITY_FLAGS_DISABLE_COLLISION;
                    if (distToPlayer > 60) {
                        data->riseVelocity = 0.5f;
                        exec_entity_commandlist(entity);
                    } else {
                        data->state = 0;
                        data->riseVelocity = 10.0f;
                        exec_entity_commandlist(entity);
                    }
                }
            }
        }
    }
}

void entity_HiddenPanel_flip_over(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    f32 yaw;
    f32 rotAngle;
    s32 flipAxis;

    yaw = clamp_angle(gCameras[CAM_DEFAULT].currentYaw + 45.0f);
    if (yaw < 90.0f || yaw >= 180.0f && yaw < 270.0f) {
        rotAngle = entity->rotation.z;
        flipAxis = 1;
    } else {
        rotAngle = entity->rotation.x;
        flipAxis = 0;
    }

    switch (data->state) {
        case 0:
            sfx_play_sound(SOUND_20AB);
            data->state = 1;
            data->unk_02 = TRUE;
            data->riseInterpPhase = 90.0f;
            data->rotationSpeed = 65.0f;
            set_time_freeze_mode(TIME_FREEZE_PARTIAL);
            disable_player_static_collisions();
            gPlayerStatusPtr->animFlags |= PLAYER_STATUS_ANIM_FLAGS_800;
            if (data->needSpawnItem) {
                data->needSpawnItem = FALSE;
                data->spawnedItemIndex = make_item_entity_nodelay(data->itemID, entity->position.x, entity->position.y + 2.0, entity->position.z, ITEM_SPAWN_MODE_TOSS_NEVER_VANISH, data->pickupVar);
            }
            entity->flags &= ~ENTITY_FLAGS_HIDDEN;
            break;
        case 1:
            entity->position.y += data->riseVelocity * sin_rad(data->riseInterpPhase * TAU / 360.0f);
            if (entity->position.y <= data->initialY) {
                entity->position.y = data->initialY;
                entity->rotation.x = 0.0f;
                entity->rotation.z = 0.0f;
                rotAngle = 0.0f;
                data->timer = 10;
            }

            data->riseInterpPhase += 10.0f;
            if (data->riseInterpPhase >= 180.0f) {
                data->riseInterpPhase = 180.0f;
                data->timer = 7;
                data->state++;
            }

            if (data->riseInterpPhase > 110.0f) {
                rotAngle += data->rotationSpeed;
                if (rotAngle >= 360.0f) {
                    rotAngle -= 360.0f;
                }
            }
            break;
        case 2:
            data->rotationSpeed -= 2.0f;
            if (data->rotationSpeed <= 0.0f) {
                data->rotationSpeed = 0.0f;
            }

            rotAngle += data->rotationSpeed;
            if (rotAngle >= 360.0f) {
                rotAngle -= 360.0f;
            }

            if (--data->timer <= 0) {
                data->state++;
            }
            break;
        case 3:
            data->rotationSpeed -= 5.0f;
            if (data->rotationSpeed <= 0.0f) {
                data->rotationSpeed = 0.0f;
            }

            rotAngle += data->rotationSpeed;
            if (rotAngle >= 360.0f) {
                rotAngle = 360.0f;
            }

            entity->position.y += data->riseVelocity * sin_rad(data->riseInterpPhase * TAU / 360.0f);
            data->riseInterpPhase += 10.0f;
            if (data->riseInterpPhase > 270.0f) {
                data->riseInterpPhase = 270.0f;
            }

            if (entity->position.y <= data->initialY) {
                data->state++;

                entity->position.y = data->initialY;
                entity->rotation.x = 0.0f;
                entity->rotation.z = 0.0f;
                rotAngle = 0.0f;
                data->timer = 10;
                exec_ShakeCamX(CAM_DEFAULT, CAM_SHAKE_DECAYING_VERTICAL, 1, 0.2f);
                sfx_play_sound(SOUND_20AC);
            }
            break;
        case 4:
            data->state++;
            break;
        case 5:
            data->state = 11;
            entity->position.y += 2.0f;
            break;
        case 10:
            entity->flags &= ~ENTITY_FLAGS_HIDDEN;
            data->unk_02 = FALSE;
            data->state++;
            entity->position.y += 6.0f;
            break;
        case 11:
            entity->position.y -= 1.0f;
            if (entity->position.y <= data->initialY) {
                entity->position.y = data->initialY;
                data->timer = 1;
                data->state++;
                entity->flags |= ENTITY_FLAGS_HIDDEN | ENTITY_FLAGS_DISABLE_COLLISION;
                if (data->unk_02) {
                    enable_player_static_collisions();
                }
            }
            break;
        case 12:
            data->timer--;
            if (data->timer < 0) {
                data->state = 0;
                exec_entity_commandlist(entity);
                if (data->unk_02) {
                    set_time_freeze_mode(TIME_FREEZE_NORMAL);
                    gPlayerStatusPtr->animFlags &= ~PLAYER_STATUS_ANIM_FLAGS_800;
                }
                entity->flags &= ~ENTITY_FLAGS_DISABLE_COLLISION;
                if (data->standingNpcIndex >= 0) {
                    Npc* npc = get_npc_by_index(data->standingNpcIndex);
                    npc->flags &= ~(NPC_FLAG_GRAVITY | NPC_FLAG_ENABLE_HIT_SCRIPT);
                    npc->flags |= data->npcFlags;
                }
            }
            break;
    }

    if (flipAxis == 0) {
        entity->rotation.x = rotAngle;
    } else {
        entity->rotation.z = rotAngle;
    }

    if (data->spawnedItemIndex >= 0) {
        ItemEntity* itemEntity = get_item_entity(data->spawnedItemIndex);
        if (itemEntity != NULL) {
            if (itemEntity->flags & ITEM_ENTITY_FLAGS_10) {
                data->spawnedItemPos.x = itemEntity->position.x;
                data->spawnedItemPos.y = itemEntity->position.y;
                data->spawnedItemPos.z = itemEntity->position.z;
            } else {
                data->spawnedItemPos.x = 0x8000;
                data->spawnedItemPos.y = 0x8000;
                data->spawnedItemPos.z = 0x8000;
            }
        } else {
            data->spawnedItemIndex = -1;
        }
    }
}

s32 entity_HiddenPanel_is_item_on_top(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;

    if (data->spawnedItemIndex >= 0) {
        ItemEntity* itemEntity = get_item_entity(data->spawnedItemIndex);
        if (itemEntity != NULL) {
            if (itemEntity->flags & ITEM_ENTITY_FLAGS_10) {
                if (fabs(entity->position.x - data->spawnedItemPos.x) <= 34.0)  {
                    if (fabs(entity->position.z - data->spawnedItemPos.z) <= 34.0) {
                        return TRUE;
                    }
                }
            }
        }
    }

    return FALSE;
}

void entity_HiddenPanel_init(Entity* entity) {
    HiddenPanelData* data = entity->dataBuf.hiddenPanel;
    Matrix4f sp18;
    Matrix4f sp58;
    Gfx* dlist;

    mem_clear(&D_8015A578, sizeof(D_8015A578));
    entity->renderSetupFunc = entity_HiddenPanel_setupGfx;
    data->pickupVar = 0xFFFF;
    data->initialY = entity->position.y;
    data->modelID = CreateEntityVarArgBuffer[0];
    data->itemID = CreateEntityVarArgBuffer[1];
    data->needSpawnItem = TRUE;
    data->spawnedItemIndex = -1;

    if (data->itemID == 0) {
        data->itemID = ITEM_STAR_PIECE;
    }

    guMtxIdentF(data->entityMatrix);
    guTranslateF(sp18, entity->position.x, entity->position.y, entity->position.z);
    guRotateF(sp58, entity->rotation.y, 0.0f, 1.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, entity->rotation.x, 1.0f, 0.0f, 0.0f);
    guMtxCatF(sp58, sp18, sp18);
    guRotateF(sp58, entity->rotation.z, 0.0f, 0.0f, 1.0f);
    guMtxCatF(sp58, sp18, sp18);
    guScaleF(sp58, entity->scale.x, entity->scale.y, entity->scale.z);
    guMtxCatF(sp58, sp18, data->entityMatrix);

    if (D_8015A578.unk_01 & 1) {
        dlist = Entity_HiddenPanel_RenderTop2;
        entity_set_render_script(entity, Entity_HiddenPanel_RenderScript2);
    } else {
        dlist = Entity_HiddenPanel_RenderTop;
    }
    data->renderDList = ENTITY_ADDR(entity, Gfx*, dlist);

    mdl_project_tex_coords(data->modelID, data->renderDList, data->entityMatrix, entity->gfxBaseAddr);
    D_8015A578.unk_01++;
}

EntityScript Entity_HiddenPanel_Script = {
    es_Call(entity_HiddenPanel_set_ispy_notification)
    es_Label(1)
        es_Call(entity_HiddenPanel_hide)
        es_SetCallback(entity_HiddenPanel_idle, 0)
        es_SetCallback(entity_HiddenPanel_flip_over, 0)
    es_Goto(1)
    es_End
};

EntityModelScript Entity_HiddenPanel_RenderScript = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_SetFlags(ENTITY_MODEL_FLAGS_10000)
    ems_Draw(Entity_HiddenPanel_Render, 60)
    ems_Restart
    ems_End
};

EntityModelScript Entity_HiddenPanel_RenderScript2 = {
    ems_SetRenderMode(RENDER_MODE_SURFACE_OPA)
    ems_SetFlags(ENTITY_MODEL_FLAGS_10000)
    ems_Draw(Entity_HiddenPanel_Render2, 60)
    ems_Restart
    ems_End
};

EntityBlueprint Entity_HiddenPanel = {
    .flags = ENTITY_FLAGS_HIDDEN,
    .typeDataSize = sizeof(HiddenPanelData),
    .renderCommandList = Entity_HiddenPanel_RenderScript,
    .modelAnimationNodes = 0,
    .fpInit = entity_HiddenPanel_init,
    .updateEntityScript = Entity_HiddenPanel_Script,
    .fpHandleCollision = NULL,
    { .dma = ENTITY_ROM(HiddenPanel) },
    .entityType = ENTITY_TYPE_HIDDEN_PANEL,
    .aabbSize = { 60, 0, 60 }
};

//TODO remove this
static const f32 rodata_alignment[] = {0.0f, 0.0f};

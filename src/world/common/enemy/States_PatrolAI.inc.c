#ifndef _AI_PATROL_INC_
#define _AI_PATROL_INC_ 0

#include "common.h"
#include "npc.h"
#include "effects.h"

// selects the next patrol point
void N(PatrolAI_MoveInit)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 ret;
    f32 max;
    f32 posX;
    f32 posZ;
    s32 i;
    s32 j;
    s32 x, z;

    script->functionTemp[1] = 0;
    max = 32767.0f;
    posX = npc->pos.x;
    posZ = npc->pos.z;
    script->AI_PATROL_GOAL_INDEX = 0;

    for (i = 0, j = 0; i < enemy->territory->patrol.numPoints; i++, j++) {
        //TODO strange match -- index and array are backwards!
        x = i[enemy->territory->patrol.points].x;
        z = i[enemy->territory->patrol.points].z;
        ret = dist2D(posX, posZ, x, z);
        if (ret < max) {
            max = ret;
            script->AI_PATROL_GOAL_INDEX = j;
        }
    }

    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_WALK];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }

    script->AI_TEMP_STATE = AI_STATE_PATROL;
}

void N(PatrolAI_Move)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 x, z;
    s32 emoteTemp;

    if (aiSettings->playerSearchInterval >= 0) {
        if (script->functionTemp[1] <= 0) {
            script->functionTemp[1] = aiSettings->playerSearchInterval;
            if (basic_ai_check_player_dist(territory, enemy, aiSettings->alertRadius, aiSettings->alertOffsetDist, 0)) {
                fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
                ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
                if (enemy->npcSettings->unk_2A & AI_ACTION_JUMP_WHEN_SEE_PLAYER) {
                    script->AI_TEMP_STATE = AI_STATE_ALERT_INIT;
                } else {
                    script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
                }
                return;
            }
        }
        script->functionTemp[1]--;
    }

    if (npc->turnAroundYawAdjustment == 0) {
        if (npc->moveSpeed < 4.0) {
            func_8003D660(npc, 0);
        } else {
            func_8003D660(npc, 1);
        }
        //TODO strange match -- index and array are backwards!
        x = script->AI_PATROL_GOAL_INDEX[enemy->territory->patrol.points].x;
        z = script->AI_PATROL_GOAL_INDEX[enemy->territory->patrol.points].z;
        npc->yaw = atan2(npc->pos.x, npc->pos.z, x, z);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (dist2D(npc->pos.x, npc->pos.z, x, z) <= npc->moveSpeed) {
            script->AI_TEMP_STATE = AI_STATE_LOITER_INIT;
            script->functionTemp[1] = (rand_int(1000) % 3) + 2;
            if ((aiSettings->unk_AI_2C <= 0) || (aiSettings->moveTime <= 0) ||
                (aiSettings->waitTime <= 0) || (script->functionTemp[1] == 0)) {
                script->AI_TEMP_STATE = AI_STATE_LOITER_POST;
            }
            if (rand_int(10000) % 100 < aiSettings->moveTime) {
                script->AI_TEMP_STATE = AI_STATE_LOITER_POST;
            }
        }
    }
}

// identical to basic_ai_loiter_init
void N(PatrolAI_LoiterInit)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration = (aiSettings->waitTime / 2) + rand_int((aiSettings->waitTime / 2) + 1);
    npc->yaw = clamp_angle(npc->yaw + rand_int(180) - 90.0f);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
    script->AI_TEMP_STATE = AI_STATE_LOITER;
}


void N(PatrolAI_Loiter)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 emoteTemp;

    if ((aiSettings->playerSearchInterval >= 0) && basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 0)) {
        fx_emote(EMOTE_EXCLAMATION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 0xF, &emoteTemp);
        npc->yaw = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
        ai_enemy_play_sound(npc, SOUND_2F4, 0x200000);
        if (!(enemy->npcSettings->unk_2A & AI_ACTION_JUMP_WHEN_SEE_PLAYER)) {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        } else {
            script->AI_TEMP_STATE = AI_STATE_ALERT_INIT;
        }
        return;
    }

    // look around randomly
    if (npc->turnAroundYawAdjustment == 0) {
        npc->duration--;
        if (npc->duration == 0) {
            script->functionTemp[1]--;
            if (script->functionTemp[1] != 0) {
                if (!(enemy->npcSettings->unk_2A & AI_ACTION_LOOK_AROUND_DURING_LOITER)) {
                    npc->yaw = clamp_angle(npc->yaw + 180.0f);
                }
                npc->duration = aiSettings->waitTime / 2 + rand_int(aiSettings->waitTime / 2 + 1);
            } else {
                script->AI_TEMP_STATE = AI_STATE_LOITER_POST;
            }
        }
    }
}

void N(PatrolAI_PostLoiter)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    script->functionTemp[2]++;
    if (script->functionTemp[2] >= enemy->territory->patrol.numPoints) {
        script->functionTemp[2] = 0;
    }
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_WALK];
    if (enemy->territory->patrol.moveSpeedOverride < 0) {
        npc->moveSpeed = aiSettings->moveSpeed;
    } else {
        npc->moveSpeed = enemy->territory->patrol.moveSpeedOverride / 32767.0;
    }
    script->AI_TEMP_STATE = AI_STATE_PATROL;
}

void N(PatrolAI_JumpInit)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_JUMP];
    npc->jumpVelocity = 10.0f;
    npc->jumpScale = 2.0f;
    npc->moveToPos.y = npc->pos.y;
    npc->flags |= NPC_FLAG_JUMPING;
    script->functionTemp[0] = AI_STATE_ALERT;
}

void N(PatrolAI_Jump)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc->pos.y += npc->jumpVelocity;
    npc->jumpVelocity -= npc->jumpScale;

    if (!(npc->pos.y > npc->moveToPos.y)) {
        npc->pos.y = npc->moveToPos.y;
        npc->jumpVelocity = 0.0f;
        npc->flags &= ~NPC_FLAG_JUMPING;
        script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
    }
}

void N(PatrolAI_ChaseInit)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    f32 angle;
    f32 angleDiff;

    npc->duration = (aiSettings->chaseUpdateInterval / 2) + rand_int(aiSettings->chaseUpdateInterval / 2 + 1);
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_CHASE];
    npc->moveSpeed = aiSettings->chaseSpeed;

    angle = atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z);
    angleDiff = get_clamped_angle_diff(npc->yaw, angle);

    if (aiSettings->chaseTurnRate < fabsf(angleDiff)) {
        angle = npc->yaw;

        if (angleDiff < 0.0f) {
            angle += -aiSettings->chaseTurnRate;
        } else {
            angle += aiSettings->chaseTurnRate;
        }
    }

    npc->yaw = clamp_angle(angle);
    script->functionTemp[0] = 13;
}

ApiStatus N(PatrolAI_Chase)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 emoteTemp;

    if (!basic_ai_check_player_dist(territory, enemy, aiSettings->chaseRadius, aiSettings->chaseOffsetDist, 1)) {
        fx_emote(EMOTE_QUESTION, npc, 0.0f, npc->collisionHeight, 1.0f, 2.0f, -20.0f, 15, &emoteTemp);
        npc->currentAnim.w = enemy->animList[ENEMY_ANIM_IDLE];
        npc->duration = 25;
        script->AI_TEMP_STATE = AI_STATE_LOSE_PLAYER;
    } else {
        func_8003D660(npc, 1);
        npc_move_heading(npc, npc->moveSpeed, npc->yaw);
        if (npc->duration > 0) {
            npc->duration--;
        } else {
            script->AI_TEMP_STATE = AI_STATE_CHASE_INIT;
        }
    }
}

void N(PatrolAI_LosePlayer)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);

    npc->duration--;
    if (npc->duration == 0) {
        if (enemy->aiFlags & ENEMY_AI_FLAGS_80) {
            script->AI_TEMP_STATE = AI_STATE_PATROL_15;
        } else {
            script->AI_TEMP_STATE = AI_STATE_WANDER_INIT;
        }
    }
}

void N(PatrolNoAttackAI_15)(Evt* script, NpcAISettings* aiSettings, EnemyDetectVolume* territory) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    s32 i;

    // get next patrol point
    for (i = script->AI_PATROL_GOAL_INDEX; i < enemy->territory->patrol.numPoints; i++) {
        if (i[enemy->territory->patrol.points].y <= npc->pos.y) {
            script->AI_PATROL_GOAL_INDEX = i;
            break;
        }
    }

    npc->moveSpeed = aiSettings->moveSpeed;
    npc->currentAnim.w = enemy->animList[ENEMY_ANIM_WALK];
    script->functionTemp[1] = 0;
    script->AI_TEMP_STATE = AI_STATE_PATROL;
}

#endif

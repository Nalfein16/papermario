#include "common.h"
#include "effects.h"

typedef struct HammerHitData {
    /* 0x00 */ Vec3f hitPos;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 hitID;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 timer;
    /* 0x1C */ s32 unk_1C;
} HammerHitData;

extern HammerHitData* HammerHit;

void func_802B6820_E256F0(void);

s32 action_hammer_is_swinging_away(s32 animID) {
    if (animID & 0x1000000) {
        return TRUE;
    }

    // away-facing swing anims
    switch (animID) {
        case 0x60011:
        case 0x60013:
        case 0x60015:
        case 0x60017:
        case 0x60019:
        case 0x6001B:
            return TRUE;
    }
    return FALSE;
}

void action_hammer_play_hit_fx(s32 hitID) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 shakeAmt;
    s32 time;
    s32 radius;
    s32 soundID;
    f32 theta, sinTheta, cosTheta;
    s32 numParticles;
    f32 x, y, z;

    if (gPlayerData.hammerLevel == 2) {
        shakeAmt = 1.2f;
        time = 1;
        radius = 28;
        soundID = SOUND_211A;
    } else if (gPlayerData.hammerLevel == 1) {
        shakeAmt = 0.8f;
        time = 1;
        radius = 16;
        soundID = SOUND_2119;
    } else {
        shakeAmt = 0.4f;
        time = 1;
        radius = 4;
        soundID = SOUND_2118;
    }

    theta = (func_800E5348() * TAU) / 360.0f;
    sinTheta = sin_rad(theta) * 25.0f;
    cosTheta = cos_rad(theta) * -25.0f;

    if (hitID < 0) {
        numParticles = 6;
        x = playerStatus->position.x + sinTheta;
        y = playerStatus->position.y;
        z = playerStatus->position.z + cosTheta;
    } else {
        numParticles = 3;
        x = HammerHit->hitPos.x + sinTheta;
        y = HammerHit->hitPos.y + playerStatus->colliderHeight - 5.0f;
        z = HammerHit->hitPos.z + cosTheta;
        radius = 1;
    }

    exec_ShakeCamX(0, 2, time, shakeAmt);
    fx_smoke_impact(0, x, y, z, radius, numParticles, 0, (time + 3) * 3);

    switch (is_ability_active(ABILITY_ATTACK_FX)) {
        case 1:
            soundID = SOUND_372;
            break;
        case 2:
            soundID = SOUND_F1;
            break;
        case 3:
            soundID = SOUND_DC;
            break;
        case 4:
            soundID = SOUND_2072;
            break;
        case 5:
            soundID = SOUND_2073;
            break;
        case 6:
            soundID = SOUND_205B;
            break;
    }

    sfx_play_sound_at_player(soundID, 0);
    start_rumble(0x100, 50);
}

s32 func_802B62A4_E25174(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 yaw;
    f32 angle;
    f32 outSinTheta;
    f32 outCosTheta;
    f32 playerX, playerY, playerZ;
    f32 x, y, z;
    s32 ret;
    s32 i;

    yaw = func_800E5348();
    if (action_hammer_is_swinging_away(playerStatus->trueAnimation)) {
        angle = clamp_angle(yaw + 90.0f - gCameras[gCurrentCameraID].currentYaw);
        if (angle >= 90.0f && angle < 270.0f) {
            yaw += -30.0f;
        } else {
            yaw += 30.0f;
        }
    }

    sin_cos_rad(yaw * TAU / 360.0f, &outSinTheta, &outCosTheta);
    playerX = playerStatus->position.x;
    playerY = playerStatus->position.y;
    playerZ = playerStatus->position.z;

    for (i = 1; i < 16; i++) {
        x = playerX + (outSinTheta * i);
        y = playerY;
        z = playerZ - (outCosTheta * i);
        ret = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
        if (ret >= 0) {
            HammerHit->hitPos.x = x;
            HammerHit->hitPos.y = y;
            HammerHit->hitPos.z = z;
            break;
        }
    }

    if (i >= 0x10) {
        yaw = func_800E5348();
        if (!action_hammer_is_swinging_away(playerStatus->trueAnimation)) {
            angle = clamp_angle(yaw + 90.0f - gCameras[gCurrentCameraID].currentYaw);
            if (angle >= 90.0f && angle < 270.0f) {
                yaw += 15.0f;
            } else {
                yaw += -15.0f;
            }
        }

        sin_cos_rad(yaw * TAU / 360.0f, &outSinTheta, &outCosTheta);
        for (i = 1; i < 16; i++) {
            x = playerX + (outSinTheta * i);
            y = playerY;
            z = playerZ - (outCosTheta * i);

            ret = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
            if (ret >= 0) {
                HammerHit->hitPos.x = x;
                HammerHit->hitPos.y = y;
                HammerHit->hitPos.z = z;
                break;
            }
        }
    }

    if (ret >= 0 && (ret & COLLISION_WITH_ENTITY_BIT)) {
        s32 hammerLevel = gPlayerData.hammerLevel;

        switch (get_entity_type(ret)) {
            case ENTITY_TYPE_HAMMER1_BLOCK:
            case ENTITY_TYPE_HAMMER1_BLOCK_TINY:
                if (hammerLevel >= 0) {
                    ret = -1;
                } else {
                    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SHIVERING;
                }
                break;
            case ENTITY_TYPE_HAMMER2_BLOCK:
            case ENTITY_TYPE_HAMMER2_BLOCK_TINY:
                if (hammerLevel >= 1) {
                    ret = -1;
                } else {
                    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SHIVERING;
                }
                break;
            case ENTITY_TYPE_HAMMER3_BLOCK:
            case ENTITY_TYPE_HAMMER3_BLOCK_TINY:
                if (hammerLevel >= 2) {
                    ret = -1;
                } else {
                    playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SHIVERING;
                }
                break;
            case ENTITY_TYPE_WOODEN_CRATE:
            case ENTITY_TYPE_BOMBABLE_ROCK:
                playerStatus->animFlags |= PLAYER_STATUS_ANIM_FLAGS_SHIVERING;
                break;
            case ENTITY_TYPE_BLUE_SWITCH:
            case ENTITY_TYPE_RED_SWITCH:
            case ENTITY_TYPE_BRICK_BLOCK:
                ret = -1;
                break;
        }
    }

    return ret;
}

void action_hammer_update(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    HammerHit->unk_1C = 0;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        s32 animID;
        s32 soundID;

        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags |= PLAYER_STATUS_FLAGS_200000;
        HammerHit->timer = 0;
        playerStatus->fallState = 0;
        playerStatus->currentSpeed = 0.0f;
        playerStatus->unk_BC = 0;
        HammerHit->hitID = func_802B62A4_E25174();

        if (gPlayerData.hammerLevel == 2) {
            soundID = SOUND_2117;
            animID = 0x6001A;
            if (HammerHit->hitID < 0) {
                soundID = SOUND_2117;
                animID = 0x60018;
            }
        } else if (gPlayerData.hammerLevel == 1) {
            soundID = SOUND_2116;
            animID = 0x60016;
            if (HammerHit->hitID < 0) {
                soundID = SOUND_2116;
                animID = 0x60014;
            }
        } else {
            soundID = SOUND_2115;
            animID = 0x60012;
            if (HammerHit->hitID < 0) {
                soundID = SOUND_2115;
                animID = 0x60010;
            }
        }

        suggest_player_anim_clearUnkFlag(animID);
        sfx_play_sound_at_player(soundID, 0);
        HammerHit->unk_0C = 0;
        HammerHit->unk_14 = 0;
    }

    playerStatus->flags &= ~PLAYER_STATUS_FLAGS_1000000;
    if (HammerHit->timer < 3 && (playerStatus->flags & PLAYER_STATUS_FLAGS_40000)) {
        playerStatus->flags |= PLAYER_STATUS_FLAGS_20000000;
    } else if (HammerHit->timer < 2) {
        HammerHit->timer++;
    } else {
        func_802B6820_E256F0();
    }
}

void func_802B6820_E256F0(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus;
    f32 yaw;
    f32 angle;
    f32 outSinTheta;
    f32 outCosTheta;
    f32 playerX, playerY, playerZ;
    f32 x, y, z;
    s32 result;
    s32 hammerLevel;
    s32 soundID;
    u32 unk_BC;
    s32 ten;
    s32 ret;
    s32 i;

    do {
        collisionStatus = &gCollisionStatus;
    } while (0); // required to match;

    yaw = func_800E5348();
    if (action_hammer_is_swinging_away(playerStatus->trueAnimation)) {
        angle = clamp_angle(yaw + 90.0f - gCameras[gCurrentCameraID].currentYaw);
        if (angle >= 90.0f && angle < 270.0f) {
            yaw += -30.0f;
        } else {
            yaw += 30.0f;
        }
    }

    sin_cos_rad(yaw * TAU / 360.0f, &outSinTheta, &outCosTheta);
    playerX = playerStatus->position.x;
    playerY = playerStatus->position.y;
    playerZ = playerStatus->position.z;

    for (i = 1; i < 16; i++) {
        x = playerX + (outSinTheta * i);
        y = playerY;
        z = playerZ - (outCosTheta * i);
        result = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
        if (HammerHit->unk_14 == 0) {
            collisionStatus->lastWallHammered = result;
            if (result >= 0) {
                if (result & COLLISION_WITH_ENTITY_BIT) {
                    get_entity_by_index(result)->collisionTimer = 0;
                }
            }
        }

        if (result >= 0) {
            break;
        }
    }

    if (i >= 16) {
        yaw = func_800E5348();
        if (action_hammer_is_swinging_away(playerStatus->trueAnimation) == 0) {
            angle = clamp_angle(yaw + 90.0f - gCameras[gCurrentCameraID].currentYaw);
            if (angle >= 90.0f && angle < 270.0f) {
                yaw += 15.0f;
            } else {
                yaw += -15.0f;
            }
        }
        sin_cos_rad(yaw * TAU / 360.0f, &outSinTheta, &outCosTheta);

        for (i = 1; i < 16; i++) {
            x = playerX + (outSinTheta * i);
            y = playerY;
            z = playerZ - (outCosTheta * i);
            result = player_test_lateral_overlap(3, playerStatus, &x, &y, &z, 4.0f, yaw);
            if (HammerHit->unk_14 == 0) {
                collisionStatus->lastWallHammered = result;
                if (result >= 0) {
                    if (result & COLLISION_WITH_ENTITY_BIT) {
                        get_entity_by_index(result)->collisionTimer = 0;
                    }
                }
            }

            if (result >= 0) {
                break;
            }
        }
    }

    if (HammerHit->timer == 2) {
        hammerLevel = gPlayerData.hammerLevel;
        if (hammerLevel == 2) {
            soundID = SOUND_2117;
        } else if (hammerLevel == 1) {
            soundID = SOUND_2116;
        } else {
            soundID = SOUND_2115;
        }
        sfx_play_sound_at_player(soundID, 0);

        action_hammer_play_hit_fx(HammerHit->hitID);

        if (collisionStatus->lastWallHammered >= 0 && (collisionStatus->lastWallHammered & COLLISION_WITH_ENTITY_BIT)) {
            get_entity_by_index(collisionStatus->lastWallHammered)->collisionTimer = 0;
            playerStatus->flags |= PLAYER_STATUS_FLAGS_1000000;
        } else if (HammerHit->hitID < 0) {
            playerStatus->flags |= PLAYER_STATUS_FLAGS_1000000;
        }

        if (HammerHit->hitID < 0 && gPlayerData.hammerLevel >= 2) {
            D_8015A578.unk_00 = TRUE;
            D_8015A578.unk_08 = playerStatus->position.y;
        }
    }

    if (playerStatus->fallState == 0 && result >= 0 && HammerHit->unk_14 == 0) {
        playerStatus->fallState++;
    }
    if (playerStatus->fallState == 1 && result < 0) {
        playerStatus->fallState = 2;
    }
    HammerHit->timer += 1;
    if (result >= 0) {
        HammerHit->unk_14 = 1;
    }
    if (HammerHit->timer == 6) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_200000;
    }

    unk_BC = playerStatus->unk_BC;
    if (unk_BC == 1) {
        if (HammerHit->timer >= 7 && (playerStatus->pressedButtons & BUTTON_B)) {
            HammerHit->unk_1C = unk_BC;
        }

        HammerHit->unk_14 = 0;
        ten = 10; // required to match
        if (HammerHit->unk_1C != 0 || HammerHit->timer > ten) {
            playerStatus->flags &= ~PLAYER_STATUS_FLAGS_1000000;
            set_action_state(ACTION_STATE_IDLE);
        }
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_200000;
    }
}

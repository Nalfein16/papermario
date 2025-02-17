#include "common.h"

extern f32 D_8010C960;
extern f32 D_8010C97C;

void func_802B6508_E24548(void);
void func_802B647C_E244BC(void);

void func_802B6000_E24040(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 temp_v1;

    playerStatus->fallState = 0;
    playerStatus->timeInAir = 0;
    playerStatus->unk_C2 = 0;
    playerStatus->flags &= ~0x80000008;
    playerStatus->flags |= 2;
    playerStatus->jumpFromPos.x = playerStatus->position.x;
    playerStatus->jumpFromPos.z = playerStatus->position.z;
    playerStatus->jumpFromHeight = playerStatus->position.y;

    phys_init_integrator_for_current_state();

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
        temp_v1 = 0x90005;
    } else if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
        temp_v1 = 0x10007;
    } else {
        temp_v1 = 0x60009;
    }
    suggest_player_anim_clearUnkFlag(temp_v1);

    collisionStatus->lastTouchedFloor = collisionStatus->currentFloor;
    collisionStatus->currentFloor = -1;
}

void func_802B60B4_E240F4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 anim;

    if (playerStatus->flags < 0) {
        playerStatus->flags &= ~0x80000000;
        func_802B6000_E24040();

        if (playerStatus->actionState == ACTION_STATE_LAUNCH) {
            phys_adjust_cam_on_landing();
        } else {
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
        }

        if (playerStatus->actionState == ACTION_STATE_JUMP) {
            if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
                sfx_play_sound_at_player(SOUND_JUMP_8BIT_MARIO, 0);
            }
            else {
                sfx_play_sound_at_player(SOUND_JUMP_2081, 0);
            }
        }
    }

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
        anim = 0x90005;
    } else if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
        anim = 0x10007;
    } else {
        anim = 0x60009;
    }
    suggest_player_anim_clearUnkFlag(anim);

    playerStatus->timeInAir++;
}

void func_802B6198_E241D8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    s32 anim;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        Entity* entity = get_entity_by_index(collisionStatus->currentFloor);

        D_8010C960 = entity->position.x;
        D_8010C97C = entity->position.z;
        func_802B6000_E24040();
        playerStatus->flags |= 0x880000;
        disable_player_input();
    }

    playerStatus->timeInAir++;

    if (playerStatus->fallState != 1) {
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;


        if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
            anim = 0x10008;
        } else {
            anim = 0x6000A;
        }

        suggest_player_anim_clearUnkFlag(anim);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }

    playerStatus->fallState++;
}

void func_802B6294_E242D4(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B647C_E244BC();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        s32 phi_a0;

        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_8BIT_MARIO) {
            phi_a0 = 0x90005;
        } else  if (!(playerStatus->animFlags & (PLAYER_STATUS_ANIM_FLAGS_HOLDING_WATT | PLAYER_STATUS_ANIM_FLAGS_2))) {
            phi_a0 = 0x10008;
        } else {
            phi_a0 = 0x6000A;
        }
        suggest_player_anim_clearUnkFlag(phi_a0);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }
    playerStatus->timeInAir++;
}

void func_802B6348_E24388(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 sub_arg5;
    f32 sub_arg6;
    f32 sub_arg7;
    f32 sub_arg8;
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp34;

    if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
        func_802B6508_E24548();
        return;
    }

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED | PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }

    playerStatus->timeInAir++;
    phys_update_interact_collider();
    sp28 = playerStatus->position.x;
    sp2C = playerStatus->position.y;
    sp30 = playerStatus->position.z;
    sp34 = playerStatus->colliderHeight;

    if (((get_collider_type_by_id(player_raycast_below_cam_relative(playerStatus, &sp28, &sp2C, &sp30, &sp34,
                                    &sub_arg5, &sub_arg6, &sub_arg7, &sub_arg8)) & 0xFF) - 2 >= 2U) && check_input_jump()) {

        set_action_state(ACTION_STATE_JUMP);
        playerStatus->flags &= ~0xE;
        func_802B60B4_E240F4();
    }
}

void func_802B647C_E244BC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 temp_v1;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;

        if (!(playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS)) {
            temp_v1 = 0x10008;
        } else {
            temp_v1 = 0xA0006;
        }

        suggest_player_anim_clearUnkFlag(temp_v1);
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;
    }
    playerStatus->timeInAir++;
}

void func_802B6508_E24548(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->flags & PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED) {
        playerStatus->flags &= ~PLAYER_STATUS_FLAGS_ACTION_STATE_CHANGED;
        playerStatus->flags &= ~(PLAYER_STATUS_FLAGS_JUMPING | PLAYER_STATUS_FLAGS_FLYING);
        playerStatus->flags |= PLAYER_STATUS_FLAGS_FALLING;
        gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_FLAGS_1;

        if (playerStatus->animFlags & PLAYER_STATUS_ANIM_FLAGS_USING_PEACH_PHYSICS) {
            suggest_player_anim_clearUnkFlag(0xA0006);
        }
    }
    playerStatus->timeInAir++;
    phys_update_interact_collider();
}

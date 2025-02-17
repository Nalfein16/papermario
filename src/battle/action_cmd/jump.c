#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_jump

extern s32 D_802941C0;

// icon IDs for hud elements
extern HudScript HES_AButton;
extern HudScript HES_RightOn;
extern HudScript HES_AButtonDown;

ApiStatus N(CreateHudElements)(Evt* script, s32 isInitialCall) {
    s32 hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    gBattleStatus.unk_82 = 1;
    gBattleStatus.unk_434 = &D_802941C0;
    gBattleStatus.unk_86 = 0;

    if (gBattleStatus.unk_83 == 0) {
        gBattleStatus.actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_JUMP;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_alpha(hudElement, 0xFF);

    hudElement = hud_element_create(&HES_RightOn);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_alpha(hudElement, 0xFF);

    return ApiStatus_DONE2;
}

ApiStatus func_802A9120_421B10(Evt* script, s32 isInitialCall) {
    s32 hudElement;

    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    } else {
        func_80268858();
        actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
        actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
        actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
        actionCommandStatus->unk_60 = 0;
        battleStatus->actionSuccess = 0;

        hudElement = actionCommandStatus->hudElements[0];
        actionCommandStatus->hudElementX = 50;
        battleStatus->flags1 &= ~0x8000;
        battleStatus->flags1 &= ~0x2000;
        hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
        if (actionCommandStatus->unk_61 != 0) {
            hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
        }

        actionCommandStatus->state = 10;
        func_80269118();
        btl_set_popup_duration(10);
        return ApiStatus_DONE2;
    }
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 temp_s0_3;

    switch (actionCommandStatus->state) {
        case 0:
            if (battleStatus->unk_83 == 2) {
                btl_set_popup_duration(99);
            }
            actionCommandStatus->state = 1;
            break;
        case 1:
            if (battleStatus->unk_83 == 2) {
                btl_set_popup_duration(99);
            }

            actionCommandStatus->hudElementX += 20;
            if (actionCommandStatus->hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }

            hudElement = actionCommandStatus->hudElements[0];
            hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            if (actionCommandStatus->unk_61) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
            }

            if (actionCommandStatus->autoSucceed) {
                hudElement = actionCommandStatus->hudElements[1];
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX + 50, actionCommandStatus->hudElementY);
                if (actionCommandStatus->unk_61) {
                    hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
                    break;
                }
            }
            break;
        case 10:
            if (battleStatus->unk_83 == 2) {
                btl_set_popup_duration(99);
            }

            temp_s0_3 = battleStatus->unk_434[actionCommandStatus->unk_50];
            if (((actionCommandStatus->unk_4E - temp_s0_3) - 2) <= 0) {
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButtonDown);
            }
            if ((battleStatus->currentButtonsPressed & BUTTON_A) && (actionCommandStatus->autoSucceed == 0)) {
                actionCommandStatus->unk_60 = 1;
                battleStatus->unk_86 = -1;
            }
            if ((actionCommandStatus->unk_4E - temp_s0_3) > 0) {
                actionCommandStatus->unk_4E -= 1;
                break;
            }

            actionCommandStatus->unk_54 = battleStatus->unk_434[actionCommandStatus->unk_50];
            battleStatus->actionSuccess = -1;
            actionCommandStatus->state = 11;
        case 11:
            if (battleStatus->unk_83 == 2) {
                btl_set_popup_duration(99);
            }
            if (battleStatus->unk_83 >= 2) {
                if (actionCommandStatus->unk_54 == 0) {
                    break;
                }
            } else {
                if (battleStatus->actionSuccess >= 0) {
                    hudElement = actionCommandStatus->hudElements[0];
                    if (actionCommandStatus->unk_61 != 0) {
                        hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                }
            }

            if (battleStatus->actionSuccess < 0) {
                if (((battleStatus->currentButtonsPressed & BUTTON_A)&&
                    (actionCommandStatus->unk_60 == 0)) ||
                    (actionCommandStatus->autoSucceed != 0)) {
                    battleStatus->actionSuccess = 1;
                    battleStatus->unk_86 = 1;
                    gBattleStatus.flags1 |= 0x2000;
                }
            }

            if (actionCommandStatus->unk_54 == 0) {
                if (battleStatus->actionSuccess == 1) {
                    func_80269160();
                }
                if (battleStatus->unk_83 == 2) {
                    btl_set_popup_duration(0);
                }
                actionCommandStatus->unk_54 = 5;
                actionCommandStatus->state = 12;
                break;
            }
            actionCommandStatus->unk_54 -= 1;
            break;
        case 12:
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54 -= 1;
                break;
            }
            func_80268C9C();
            break;
    }
}

void N(draw_hud_elements)(void) {
	hud_element_draw_clipped(gActionCommandStatus.hudElements[0]);
	if (!(gGameStatusPtr->demoFlags & 1)) {
		hud_element_draw_clipped(gActionCommandStatus.hudElements[1]);
	}
}

void N(free_hud_elements)(void) {
	hud_element_free(gActionCommandStatus.hudElements[0]);
	hud_element_free(gActionCommandStatus.hudElements[1]);
}

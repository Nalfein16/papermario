#include "kpa_03.h"

ApiStatus func_80241E50_A4A410(Evt* script) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->lastGoodPosition.y >= 0) {
        evt_set_variable(script, GW(0), FALSE);
    }
    if (playerStatus->lastGoodPosition.y <= -280) {
        evt_set_variable(script, GW(0), TRUE);
    }
    return ApiStatus_BLOCK;
}

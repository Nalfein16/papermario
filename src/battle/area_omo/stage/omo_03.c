#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_omo_omo_03

EvtScript N(beforeBattle_8022DC20) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(SetGroupEnabled, 18, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_8022DC70) = {
    EVT_RETURN
    EVT_END
};

Stage NAMESPACE = {
    .texture = "omo_tex",
    .shape = "omo_bt03_shape",
    .hit = "omo_bt03_hit",
    .bg = "omo_bg",
    .preBattle = &N(beforeBattle_8022DC20),
    .postBattle = &N(afterBattle_8022DC70),
};

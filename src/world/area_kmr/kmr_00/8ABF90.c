#include "kmr_00.h"
#include "effects.h"

static char* N(exit_str_0) = "kmr_02";
static char* N(exit_str_1) = "kmr_02\0";

INCLUDE_ASM(s32, "world/area_kmr/kmr_00/8ABF90", func_80240000_8ABF90);

INCLUDE_ASM(s32, "world/area_kmr/kmr_00/8ABF90", func_80240388_8AC318);

ApiStatus func_802403B8_8AC348(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    s32 var4 = evt_get_variable(script, *args++);

    fx_sparkles(var0, var1, var2, var3, var4);
    return ApiStatus_DONE2;
}

ApiStatus func_802404A0_8AC430(Evt* script, s32 isInitialCall) {
    fx_energy_orb_wave(4, 0.0f, 0.0f, 0.0f, 0.3f, 30);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_00/8ABF90", func_802404E8_8AC478);

ApiStatus func_80240530_8AC4C0(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(evt_get_variable(script, *script->ptrReadPos));

    fx_sparkles(3, npc->pos.x, npc->pos.y + 10.0f, npc->pos.z, 10.0f);
    return ApiStatus_DONE2;
}

ApiStatus func_80240584_8AC514(Evt* script, s32 isInitialCall) {
    func_8005553C(0, 2000);
    return ApiStatus_DONE2;
}

ApiStatus func_802405A8_8AC538(Evt* script, s32 isInitialCall) {
    func_80055590(0, 2000);
    return ApiStatus_DONE2;
}

ApiStatus func_802405CC_8AC55C(Evt* script, s32 isInitialCall) {
    func_800554E8(0, 1000);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_00/8ABF90", func_802405F0_8AC580);

ApiStatus func_80240BD8_8ACB68(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc;

    if (isInitialCall) {
        script->functionTemp[1] = evt_get_variable(script, *args);
        npc = get_npc_unsafe(script->functionTemp[1]);
        sfx_play_sound_at_position(SOUND_B000001E, 0, npc->pos.x, npc->pos.y, npc->pos.z);
        fx_sparkles(0, npc->pos.x, npc->pos.y + 20.0f, npc->pos.z, 10.0f);
        script->functionTemp[0] = 3;
    }

    npc = get_npc_unsafe(script->functionTemp[1]);
    script->functionTemp[0]--;
    if (script->functionTemp[0] == -1) {
        npc->pos.y = -1000.0f;
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "world/area_kmr/kmr_00/8ABF90", func_80240CB0_8ACC40);

#include "dead.h"
#include "common.h"

#define NAMESPACE EB5470

ApiStatus func_80240340_EB5470(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCollisionStatus.currentFloor);
    return ApiStatus_DONE2;
}

ApiStatus func_8024036C_EB549C(Evt* script, s32 isInitialCall) {
    func_80059AC8(0, 1);
    return ApiStatus_DONE2;
}

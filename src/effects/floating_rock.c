#include "common.h"
#include "effects_internal.h"

typedef struct FloatingRockFXData {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ f32 unk_0C;
} FloatingRockFXData; // size = 0x??

void floating_rock_appendGfx(void* effect);

INCLUDE_ASM(s32, "effects/floating_rock", floating_rock_main);

void floating_rock_init(void) {
}

INCLUDE_ASM(s32, "effects/floating_rock", floating_rock_update);

void floating_rock_render(EffectInstance *effect) {
    FloatingRockFXData* effect76 = effect->data;
    RenderTask renderTask;
    RenderTask* retTask;

    renderTask.appendGfx = floating_rock_appendGfx;
    renderTask.appendGfxArg = effect;
    renderTask.distance = effect76->unk_0C;
    renderTask.renderMode = RENDER_MODE_2D;

    retTask = shim_queue_render_task(&renderTask);
    retTask->renderMode |= RENDER_TASK_FLAG_2;
}

INCLUDE_ASM(s32, "effects/floating_rock", floating_rock_appendGfx);

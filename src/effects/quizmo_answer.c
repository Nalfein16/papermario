#include "common.h"
#include "effects_internal.h"

// INCLUDE_ASM(s32, "effects/quizmo_answer", quizmo_answer_main);
void quizmo_answer_main(Gfx *gfxArg)
{
    EffectBlueprint blueprint;
    EffectInstance *effect;
    Gfx *gfx_1;
    Gfx *gfx_2;
    s32 int_1;
    s32 int_2;

    // gfxArg is located at 0x28(sp)
    // blueprint is located at 0x10(sp)
    // s0 = a0 (which is gfxArg)

    blueprint.unk_00 = NULL;      // sw zero, 0x10(sp)
    blueprint.init = NULL;        // sw zero, 0x18(sp)
    blueprint.update = NULL;      // sw zero, 0x1c(sp)
    blueprint.renderWorld = NULL; // sw zero, 0x20(sp)
    blueprint.unk_14 = NULL;      // sw zero, 0x24(sp)

    // v0 is EFFECT_QUIZMO_ANSWER (0x50)
    blueprint.effectID = EFFECT_QUIZMO_ANSWER; // sw v0, 0x14(sp)

    effect = shim_create_effect_instance(&blueprint); // jal shim_create_effect_instance

    ////////////////////////
    // ALL ABOVE IS CORRECT AS OF 7/29 @ 4:55PM EST
    ////////////////////////

    // a0 = 0xdb060024
    int_1 = 0xdb060024; // lui a0 0xdb06; ori a0 a0 0x24

    // a2 = gMasterGfxPos
    // a1 = 0(a2)
    int_2 = gMasterGfxPos->words.w0; // lui a2, %hi(gMasterGfxPos); addiu a2, %lo(gMasterGfxPos); lw a1, 0(a2)

    // t3 = v0 (which is 0x50, EFFECT_QUIZMO_ANSWER, from last section)
    effect->data = NULL; // move t3, v0; sw zero, 0xc(t3)

    gfx_1 = &(gMasterGfxPos->dma); // sw v0, 0(v1)
    // gMasterGfxPos->words.w0 += 0x8;
    gMasterGfxPos->words.w0 = gMasterGfxPos->dma.par;

    // v0 = 0xe7000000
    gMasterGfxPos->words.w0 = 0xE7000000; // lui v0, 0xe700; sw v0, 0(v1)
    gMasterGfxPos->words.w1 = NULL;       // sw zero, 4(v1)
    gfx_1->words.w0 = int_1;              // sw a0, 0(a1)

    // v1 = 0x10(t3) (EFFECT_THROW_SPINY???)
    int_1 = EFFECT_THROW_SPINY; // lw v1, 0x10(t3)

    gMasterGfxPos = gfx_1 + 8; // addiu v0, a1, 8; sw v0, 0(a2)

    gfx_1->words.w1 = (u32)(effect->graphics->data + 0x80000000); // lw v0, 0x1c(v1); lui v1, 0x8000; addu v0, v0, v1

    if (gfxArg == NULL) // bnez s0
    {
        int_2 = 0xFF4040E6;                            // lui v1, 0xff40; ori v1, v1, 0x40e6
        gMasterGfxPos = gfx_1 + 0x10;                  // addiu v0, a1, 0x10; sw v0, 0(a2)
        int_1 = 0x09000400;                            // lui v0, 0x900; addiu v0, v0, 0x4a8
        gfx_1->force_structure_alignment = 0xDE000000; // lui v0, 0xde00; sw v0, 8(a1)
    }
    else
    {
        int_2 = 0x5050FFE6;                            // lui v1, 0x5050; ori v1, v1, 0xffe6
        gMasterGfxPos = gfx_1 + 0x10;                  // addiu v0, a1, 0x10; sw v0, 0(a2)
        int_1 = 0x090004A8;                            // lui v0, 0x900; addiu v0, v0, 0x4a8
        gfx_1->force_structure_alignment = 0xDE000000; // lui v0, 0xde00; sw v0, 8(a1)
    }

    gfx_1->words.w1 = int_1; // sw v0, 4(a1)

    gfx_1->dma.par = int_1; // sw v0, 0xc(a1)

    gMasterGfxPos = gfx_1 + 0x18; // addiu v0, a1, 0x18
    gfx_1->dma.par = 0xFA000000;  // lui v0, 0xfa00; sw v0, 0x10(a1)
    gfx_1->dma.len = int_2;       // sw v1, 0x14(a1)

    // sw v0, 0(a2)

    // lui a3, 0x50; ori a3, a3, 0x3c0
    // lui t1, 0xe430; ori t1, t1, 0x230
    // lui t0, 0x20; ori t0, t0, 0x130
    // lui t2, 0x400; ori t2, t2, 0x400

    // A1 now contains gMasterGfxPos
    // lui a1, %hi(gMasterGfxPos); addiu a1, a1, %lo(gMasterGfxPos)

    // T3 now contains A0 (the "effect" variable)
    // move a0, t3

    int_1 = gMasterGfxPos->words.w0; // lw v0, 0(a1)
    // lui v1, 0xed00
    // move a2, v0

    int_1 += 8;                      // addiu v0, v0, 8
    gMasterGfxPos->words.w0 = int_1; // sw v0, 0(a1)

    // sw v1, 0(a2)
    // addiu v1, v0, 8
    // sw a3, 4(a2)
    // addiu v1, v0, 0x10
    gMasterGfxPos->words.w0 = 0xE4300230; // sw t1, 0(v0)
    gMasterGfxPos->words.w1 = 0x200130;   // sw t0, 4(v0)
    // sw v1, 0(a1)
    gMasterGfxPos->dma.cmd = 0xE100;           // lui v1, 0xe100; sw v1, 8(v0)
    gMasterGfxPos->dma.par = 0xE1000400;       // li v1, 0x400; sw v1, 0xc(v0)
    gMasterGfxPos->words.w0 = gfxArg->tri.cmd; // addiu v1, v0, 0x18; sw v1, 0(a1)
    gfxArg->dma.len = 0xF1000000;              // lui v1, 0xf100; sw v1, 0x10(v0)
    // addiu v1, v0, 0x20
    // sw t2, 0x14(v0)
    // sw v1, 0(a1)
    // lui v1, 0xe700
    // sw v1, 0x18(v0)
    // addiu v1, v0, 0x28
    // sw zero, 0x1c(v0)
    // sw v1, 0(a1)
    // lui v1, 0xdb06; sw v1, 0x20(v0)
    shim_remove_effect(effect); // jal shim_remove_effect

    return NULL;

    ////////////////
    // REFERENCE FROM MIPS_TO_C OUTPUT
    ////////////////
    gfxArg = gMasterGfxPos; // temp_v0_2 = (a2_gMasterGfxPos + 0x20) ???
    gfx_2 = gfxArg + 8;
    gMasterGfxPos = gfx_2;
    gfxArg->words.w0 = 0xED000000;
    gfxArg->words.w1 = 0x5003C0;
    gMasterGfxPos = gfx_2 + 8;
    gfx_2->words.w0 = 0xE4300230;
    gfx_2->words.w1 = 0x200130;
    gMasterGfxPos = gfx_2 + 0x10;
    gfx_2->force_structure_alignment = 0xE1000000;
    gfx_2->dma.cmd = 0x400; // unkC -> dma.cmd?
    gMasterGfxPos = gfx_2 + 0x18;
    gfx_2->dma.par = 0xF1000000; // gfx_2->unk10 -> dma.par?
    gfx_2->dma.len = 0x04000400; // gfx_2->unk14 -> dma.len?
    gMasterGfxPos = gfx_2 + 0x20;
    gfx_2->dma.addr = 0xE7000000; // gfx_2->unk18 -> dma.addr?
    gfx_2->tri.cmd = 0;           // gfx_2->unk1C -> tri.cmd?
    gMasterGfxPos = gfx_2 + 0x28;
    gfx_2->tri.pad = 0xDB060000; // gfx_2->unk20 -> tri.pad?
    gfx_2->tri.tri.flag = NULL;  // gfx_2->unk24 -> tri.tri.flag?
    shim_remove_effect(effect);

    return NULL;
}

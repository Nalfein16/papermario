#include "common.h"
#include "effects_internal.h"

// INCLUDE_ASM(s32, "effects/quizmo_answer", quizmo_answer_main);
void quizmo_answer_main(Gfx *gfxArg)
{
    EffectBlueprint bp;
    EffectInstance *effect;
    Gfx *v1;
    Gfx *temp_v0_3;
    s32 a0;
    s32 var_v1;

    // gfxArg is located at 0x28(sp)
    // bp is located at 0x10(sp)
    // v0 is EFFECT_QUIZMO_ANSWER (0x50)
    // a0 is the Gfx argument of this function (gfxArg)
    // a1 is 0(a2)
    // a2 is gMasterGfxPos

    bp.unk_00 = NULL;                   // sw zero, 0x10(sp)
    bp.init = NULL;                     // sw zero, 0x18(sp)
    bp.update = NULL;                   // sw zero, 0x1c(sp)
    bp.renderWorld = NULL;              // sw zero, 0x20(sp)
    bp.unk_14 = NULL;                   // sw zero, 0x24(sp)
    bp.effectID = EFFECT_QUIZMO_ANSWER; // sw v0, 0x14(sp)

    effect = shim_create_effect_instance(&bp); // jal shim_create_effect_instance

    ////////////////////////
    // ALL ABOVE IS CORRECT AS OF 7/29 @ 4:55PM EST
    ////////////////////////

    // a0 = 0xdb060024
    // a1 = 0(a2)
    // a2 = gMasterGfxPos
    // t3 = v0 (which is EFFECT_QUIZMO_ANSWER, from last section)
    // v0 = 0xe7000000 (after t3 assignment!)
    // v1 = a1
    // v1 = 0x10(t3) (EFFECT_THROW_SPINY???)

    effect->flags = 0xdb060024; // lui a0 0xdb06; ori a0 a0 0x24

    var_v1 = gMasterGfxPos->words.w0; // lui a2, %hi(gMasterGfxPos); addiu a2, %lo(gMasterGfxPos); lw a1, 0(a2)

    // move t3, v0

    bp.effectID = 0xE7000000; // lui v0, 0xe700
    effect->data = NULL;      // sw zero, 0xc(t3)

    gMasterGfxPos->words.w0 = gMasterGfxPos->words.w1; // move v1, a1; addiu a1, a1, 8; sw a1, 0(a2)

    gMasterGfxPos->words.w1 = NULL; // sw zero, 4(v1)
    v1 = &(gMasterGfxPos->dma);     // sw v0, 0(v1)
    // gMasterGfxPos->words.w1 = effect->flags; // sw a0, 0(a1)

    a0 = EFFECT_THROW_SPINY; // lw v1, 0x10(t3)

    gMasterGfxPos = v1 + 8; // addiu v0, a1, 8; sw v0, 0(a2)

    effect->effectIndex = bp.effectID; // sw v0, 4(a1)

    v1->words.w1 = (u32)(effect->graphics->data + 0x80000000); // lw v0, 0x1c(v1); lui v1, 0x8000; addu v0, v0, v1

    if (gfxArg == NULL) // bnez s0
    {
        var_v1 = 0xFF4040E6;                        // lui v1, 0xff40; ori v1, v1, 0x40e6
        gMasterGfxPos = v1 + 0x10;                  // addiu v0, a1, 0x10; sw v0, 0(a2)
        a0 = 0x09000400;                            // lui v0, 0x900; addiu v0, v0, 0x4a8
        v1->force_structure_alignment = 0xDE000000; // lui v0, 0xde00; sw v0, 8(a1)
    }
    else
    {
        var_v1 = 0x5050FFE6;                        // lui v1, 0x5050; ori v1, v1, 0xffe6
        gMasterGfxPos = v1 + 0x10;                  // addiu v0, a1, 0x10; sw v0, 0(a2)
        a0 = 0x090004A8;                            // lui v0, 0x900; addiu v0, v0, 0x4a8
        v1->force_structure_alignment = 0xDE000000; // lui v0, 0xde00; sw v0, 8(a1)
    }

    v1->dma.cmd = a0; // sw v0, 4(a1)

    // sw v0, 0xc(a1)
    // addiu v0, a1, 0x18
    // sw v0, 0(a2)
    // lui v0, 0xfa00
    // sw v0, 0x10(a1)
    // sw v1, 0x14(a1)
    // lui a3, 0x50; ori a3, a3, 0x3c0
    // lui t1, 0xe430; ori t1, t1, 0x230
    // lui t0, 0x20; ori t0, t0, 0x130
    // lui t2, 0x400; ori t2, t2, 0x400
    // lui a1, %hi(gMasterGfxPos)
    // addiu a1, a1, %lo(gMasterGfxPos)
    // move a0, t3
    // lw v0, 0(a1)
    // lui v1, 0xed00
    // move a2, v0
    // ...(left off at 120)

    gMasterGfxPos = v1 + 0x18;
    v1->dma.par = 0xFA000000; // temp unk10 -> dma.par?
    v1->dma.len = var_v1;     // temp unk14 -> dma.len?

    gfxArg = gMasterGfxPos; // temp_v0_2 = (a2_gMasterGfxPos + 0x20) ???
    temp_v0_3 = gfxArg + 8;
    gMasterGfxPos = temp_v0_3;
    gfxArg->words.w0 = 0xED000000;
    gfxArg->words.w1 = 0x5003C0;
    gMasterGfxPos = temp_v0_3 + 8;
    temp_v0_3->words.w0 = 0xE4300230;
    temp_v0_3->words.w1 = 0x200130;
    gMasterGfxPos = temp_v0_3 + 0x10;
    temp_v0_3->force_structure_alignment = 0xE1000000;
    temp_v0_3->dma.cmd = 0x400; // unkC -> dma.cmd?
    gMasterGfxPos = temp_v0_3 + 0x18;
    temp_v0_3->dma.par = 0xF1000000; // temp_v0_3->unk10 -> dma.par?
    temp_v0_3->dma.len = 0x04000400; // temp_v0_3->unk14 -> dma.len?
    gMasterGfxPos = temp_v0_3 + 0x20;
    temp_v0_3->dma.addr = 0xE7000000; // temp_v0_3->unk18 -> dma.addr?
    temp_v0_3->tri.cmd = 0;           // temp_v0_3->unk1C -> tri.cmd?
    gMasterGfxPos = temp_v0_3 + 0x28;
    temp_v0_3->tri.pad = 0xDB060000; // temp_v0_3->unk20 -> tri.pad?
    temp_v0_3->tri.tri.flag = NULL;  // temp_v0_3->unk24 -> tri.tri.flag?
    shim_remove_effect(effect);

    return NULL;
}

#include "common.h"
#include "effects_internal.h"

// INCLUDE_ASM(s32, "effects/quizmo_answer", quizmo_answer_main);
void quizmo_answer_main(Gfx *temp_v0_2)
{
    EffectBlueprint bp;
    EffectInstance *effect;
    Gfx *a2_gMasterGfxPos;
    Gfx *temp_a1_2;
    // Gfx *temp_v0_2;
    Gfx *temp_v0_3;
    s32 var_v0;
    s32 var_v1;

    // v0 (bp) is located at 0x10(sp)

    bp.unk_00 = NULL;                   // sw zero, 0x10(sp)
    bp.init = NULL;                     // sw zero, 0x18(sp)
    bp.update = NULL;                   // sw zero, 0x1c(sp)
    bp.renderWorld = NULL;              // sw zero, 0x20(sp)
    bp.unk_14 = NULL;                   // sw zero, 0x24(sp)
    bp.effectID = EFFECT_QUIZMO_ANSWER; // sw v0, 0x14(sp)

    effect = shim_create_effect_instance(&bp); // jal shim_create_effect_instance
    effect->numParts = 0xDB060024;             // lui a0 0xdb06; ori a0 a0 0x24

    a2_gMasterGfxPos = gMasterGfxPos; // lui a2 %hi(gMasterGfxPos); addiu a2, a2, %lo(gMasterGfxPos)

    effect->data = NULL; // sw zero, 0xc(t3)

    temp_a1_2 = a2_gMasterGfxPos + 8; // move v1, a1; addiu a1, a1, 8 ... temp_a1_2 = &(a2_gMasterGfxPos->dma); ???
    gMasterGfxPos = temp_a1_2;        // sw a1, 0(a2)

    bp.effectID = 0xE7000000; // lui v0, 0xe700

    a2_gMasterGfxPos->words.w1 = NULL;                                // sw zero, 4(v1)
    gMasterGfxPos = temp_a1_2 + 8;                                    // addiu v0, a1, 8; sw v0, 0(a2)
    temp_a1_2->words.w1 = (u32)(effect->graphics->data + 0x80000000); // lw v0, 0x1c(v1); lui v1, 0x8000; addu v0, v0, v1
    if (temp_v0_2 == NULL)                                            // bnez s0
    {
        var_v1 = 0xFF4040E6;
        var_v0 = 0x09000400;
        gMasterGfxPos = temp_a1_2 + 0x10;                  // ???
        temp_a1_2->force_structure_alignment = 0xDE000000; // temporarily unk8 -> force_structure_alignment
    }
    else
    {
        var_v1 = 0x5050FFE6;
        gMasterGfxPos = temp_a1_2 + 0x10;
        temp_a1_2->force_structure_alignment = 0xDE000000;
        var_v0 = 0x090004A8;
    }
    temp_a1_2->words.w0 = var_v0; // temp unkC -> words.w0
    gMasterGfxPos = temp_a1_2 + 0x18;
    temp_a1_2->words.w1 = 0xFA000000; // temp unk10 -> words.w1
    temp_a1_2->words.w0 = var_v1;     // temp unk14 -> words.w0

    temp_v0_2 = gMasterGfxPos; // temp_v0_2 = (a2_gMasterGfxPos + 0x20) ???
    temp_v0_3 = temp_v0_2 + 8;
    gMasterGfxPos = temp_v0_3;
    temp_v0_2->words.w0 = 0xED000000;
    temp_v0_2->words.w1 = 0x5003C0;
    gMasterGfxPos = temp_v0_3 + 8;
    temp_v0_3->words.w0 = 0xE4300230;
    temp_v0_3->words.w1 = 0x200130;
    gMasterGfxPos = temp_v0_3 + 0x10;
    temp_v0_3->force_structure_alignment = 0xE1000000;
    temp_v0_3->words.w0 = 0x400; // unkC -> words.w0
    gMasterGfxPos = temp_v0_3 + 0x18;
    temp_v0_3->dma.cmd = 0xF1000000; // temp_v0_3->unk10 -> dma.cmd?
    temp_v0_3->dma.par = 0x04000400; // temp_v0_3->unk14 -> dma.par?
    gMasterGfxPos = temp_v0_3 + 0x20;
    temp_v0_3->dma.len = 0xE7000000; // temp_v0_3->unk18 -> dma.len?
    temp_v0_3->dma.addr = 0;         // temp_v0_3->unk1C -> dma.addr?
    gMasterGfxPos = temp_v0_3 + 0x28;
    temp_v0_3->words.w0 = 0xDB060000; // temp_v0_3->unk20 -> words.w0
    temp_v0_3->words.w1 = 0;          // temp_v0_3->unk24 -> words.w1
    shim_remove_effect(effect);

    return NULL;
}

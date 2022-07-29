#include "common.h"
#include "effects_internal.h"

// INCLUDE_ASM(s32, "effects/quizmo_answer", quizmo_answer_main);
void quizmo_answer_main(EffectBlueprint *sp14)
{
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    // EffectBlueprint *sp14;
    s32 sp10;
    EffectInstance *temp_v0;
    Gfx *a2_gMasterGfxPos;
    Gfx *temp_a1_2;
    Gfx *temp_v0_2;
    Gfx *temp_v0_3;
    s32 var_v0;
    s32 var_v1;

    sp14->unk_00 = 0x50; // li v0, 0x50
    // sp10 = 0;            //
    // sp18 = 0;            // one of these five corresponds to:
    // sp1C = 0;            // 0x10       0x18
    // sp20 = 0;            // 0x1c       0x20
    // sp24 = 0;            // 0x24
    // temp_v0 = sp14;
    sp14->effectID = 0;
    sp14->init = 0;

    temp_v0 = shim_create_effect_instance((EffectBlueprint *)&sp14); // jal shim_create_effect_instance

    temp_a1_2->words.w0 = 0xDB060024; // lui a0 0xdb06; ori a0 a0 0x24
    a2_gMasterGfxPos = gMasterGfxPos; // lui a2 %hi(gMasterGfxPos); addiu a2, a2, %lo(gMasterGfxPos)
    temp_v0->data = NULL;
    temp_a1_2 = a2_gMasterGfxPos + 8;
    gMasterGfxPos = temp_a1_2;
    a2_gMasterGfxPos->words.w0 = 0xE7000000;
    a2_gMasterGfxPos->words.w1 = 0; // "= 0" is right; should be stored into 0xC(t3)
    gMasterGfxPos = temp_a1_2 + 8;
    temp_a1_2->words.w1 = (u32)(temp_v0->graphics->data + 0x80000000);
    if (temp_a1_2 == 0) // bnez s0    ...what should I be comparing to zero???
    {
        gMasterGfxPos = temp_a1_2 + 0x10;
        temp_a1_2->force_structure_alignment = 0xDE000000; // temporarily unk8 -> force_structure_alignment
        var_v0 = 0x09000400;
        var_v1 = 0xFF4040E6;
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
    temp_v0_2 = gMasterGfxPos;
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
    shim_remove_effect(temp_v0);

    return 0;
}

#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/chain_chomp.h"
#include "sprite/npc/tutankoopa.h"

#define NAMESPACE b_area_isk_part_2_chain_chomp

extern EvtScript N(init_80218EC4);
extern EvtScript N(takeTurn_8021A7C4);
extern EvtScript N(idle_80219108);
extern EvtScript N(handleEvent_802197C4);
extern EvtScript N(8021972C);
extern EvtScript N(8021A200);
extern EvtScript N(8021B41C);
extern EvtScript N(8021B50C);

s32 N(idleAnimations_80218B40)[] = {
    STATUS_NORMAL,    NPC_ANIM_chain_chomp_Palette_00_Anim_1,
    STATUS_STONE,     NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_chain_chomp_Palette_00_Anim_7,
    STATUS_POISON,    NPC_ANIM_chain_chomp_Palette_00_Anim_1,
    STATUS_STOP,      NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_STATIC,    NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_chain_chomp_Palette_00_Anim_8,
    STATUS_END,
};

s32 N(idleAnimations_80218B84)[] = {
    STATUS_NORMAL,    NPC_ANIM_chain_chomp_Palette_00_Anim_3,
    STATUS_POISON,    NPC_ANIM_chain_chomp_Palette_00_Anim_3,
    STATUS_STOP,      NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_STONE,     NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_chain_chomp_Palette_00_Anim_7,
    STATUS_STATIC,    NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_chain_chomp_Palette_00_Anim_8,
    STATUS_END,
};

s32 N(idleAnimations_80218BC8)[] = {
    STATUS_NORMAL,    NPC_ANIM_chain_chomp_Palette_00_Anim_4,
    STATUS_POISON,    NPC_ANIM_chain_chomp_Palette_00_Anim_4,
    STATUS_STOP,      NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_STONE,     NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_chain_chomp_Palette_00_Anim_7,
    STATUS_STATIC,    NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_chain_chomp_Palette_00_Anim_8,
    STATUS_END,
};

s32 N(idleAnimations_80218C0C)[] = {
    STATUS_NORMAL,    NPC_ANIM_chain_chomp_Palette_00_Anim_5,
    STATUS_POISON,    NPC_ANIM_chain_chomp_Palette_00_Anim_5,
    STATUS_STOP,      NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_STONE,     NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_chain_chomp_Palette_00_Anim_7,
    STATUS_STATIC,    NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_PARALYZE,  NPC_ANIM_chain_chomp_Palette_00_Anim_0,
    STATUS_DIZZY,     NPC_ANIM_chain_chomp_Palette_00_Anim_8,
    STATUS_END,
};

s32 N(idleAnimations_80218C50)[] = {
    STATUS_NORMAL,    NPC_ANIM_chain_chomp_Palette_00_Anim_2,
    STATUS_END,
};

s32 N(defenseTable_80218C5C)[] = {
    ELEMENT_NORMAL, 3,
    ELEMENT_SHOCK, 3,
    ELEMENT_FIRE, 99,
    ELEMENT_ICE, 99,
    ELEMENT_MAGIC, 99,
    ELEMENT_END,
};

s32 N(statusTable_80218C88)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 0,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 0,
    STATUS_SHRINK, 75,
    STATUS_STOP, 75,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(partsTable_80218D34)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218B40),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_100000 | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -13, 40 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218B40),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1D = 240,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218C50),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218C50),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218C50),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218C50),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218C50),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218C50),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 9,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218C50),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
    {
        .flags = ACTOR_PART_FLAG_2 | ACTOR_PART_FLAG_4000 | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_100000,
        .index = 10,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 12 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80218C50),
        .defenseTable = N(defenseTable_80218C5C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_CHOMP,
    .level = 14,
    .maxHP = 4,
    .partCount = ARRAY_COUNT(N(partsTable_80218D34)),
    .partsData = N(partsTable_80218D34),
    .script = &N(init_80218EC4),
    .statusTable = N(statusTable_80218C88),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 0,
    .size = { 56, 40 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

#include "common/ChompChainInit.inc.c"

#include "common/ChompChainUpdateHelperFunc.inc.c"

#include "common/ChompChainUpdateHelperFunc2.inc.c"

ApiStatus N(ChompChainUpdate)(Evt* script, s32 isInitialCall);
INCLUDE_ASM(ApiStatus, "battle/area_isk_part_2/4EF4A0", b_area_isk_part_2_chain_chomp_ChompChainUpdate);

ApiStatus func_8021866C_4EFB0C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = *args++;

    evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(init_80218EC4) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn_8021A7C4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle_80219108)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent_802197C4)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_SET(LW(0), 3)
    EVT_LOOP(8)
        EVT_CALL(SetPartSize, ACTOR_SELF, LW(0), 16, 16)
        EVT_ADD(LW(0), 1)
    EVT_END_LOOP
    EVT_CALL(N(ChompChainInit))
    EVT_EXEC(N(8021972C))
    EVT_RETURN
    EVT_END
};

EvtScript N(80218FCC) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, 0, 24)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, 0, 0)
    EVT_ELSE
        EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
        EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
        EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -13, 40)
        EVT_CALL(func_8027D4C8, ACTOR_SELF, 2, 0, -14)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_80219108) = {
    EVT_LABEL(0)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218C0C)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 10)
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 11, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 6, 1)
    EVT_CALL(RandInt, 10, LW(0))
    EVT_ADD(LW(0), 1)
    EVT_WAIT_FRAMES(LW(0))
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218BC8)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 15, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218C0C)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 12, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 9, 1)
    EVT_LOOP(0)
        EVT_EXEC_WAIT(N(80218FCC))
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT_FRAMES(1)
    EVT_END_LOOP
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_ADDR(N(idleAnimations_80218B84)))
    EVT_CALL(SetActorIdleJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetIdleGoalToHome, ACTOR_SELF)
    EVT_CALL(GetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetIdleGoal, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(IdleJumpToGoal, ACTOR_SELF, 6, 1)
    EVT_CALL(RandInt, 10, LW(0))
    EVT_ADD(LW(0), 10)
    EVT_WAIT_FRAMES(LW(0))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021972C) = {
    EVT_LABEL(0)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LW(0))
    EVT_IF_EQ(LW(0), TRUE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_CALL(N(ChompChainUpdate), LW(2))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802197C4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SET(LW(15), LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_SET_CONST(LW(2), -1)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 12, 2)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(8021A200))
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SET(LW(1), 0)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.4))
            EVT_CALL(AddGoalPos, ACTOR_SELF, 30, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 15, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 5, 0, 0)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_5)
            EVT_EXEC_WAIT(N(8021B41C))
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
            EVT_END_THREAD
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
            EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetGoalToHome, ACTOR_SELF)
                EVT_CALL(GetGoalPos, ACTOR_SELF, LW(1), LW(2), LW(3))
                EVT_IF_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_SUB(LW(1), 10)
                    EVT_ADD(LW(2), 4)
                EVT_ELSE
                    EVT_SUB(LW(1), 5)
                    EVT_ADD(LW(2), 11)
                EVT_END_IF
                EVT_CALL(SetActorPos, ACTOR_SELF, LW(1), LW(2), LW(3))
            EVT_END_IF
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoAirLift)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 12, 2)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 12, 2)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(N(8021A200))
            EVT_CALL(SetActorVar, ACTOR_ENEMY0, 12, 2)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_6)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
    EVT_IF_FLAG(LW(0), STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE)
        EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_IF_NE(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 0, LW(2))
            EVT_CALL(FallToGoal, ACTOR_SELF, 11)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021A200) = {
    EVT_CALL(ActorExists, ACTOR_ENEMY0, LW(0))
    EVT_IF_EQ(LW(0), FALSE)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_ENEMY0, 8, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_6)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_ENEMY0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), 20, LW(2))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(7.0))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 2, EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_WAIT_FRAMES(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 1, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 150, LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 130, LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(15)
    EVT_GOTO(10)
    EVT_LABEL(1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_6)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 135, LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 105, LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    EVT_WAIT_FRAMES(15)
    EVT_LABEL(10)
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_1)
    EVT_EXEC_WAIT(N(8021B41C))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_tutankoopa_Palette_00_Anim_1)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021A7C4) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.5))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_SET(LW(1), 0)
    EVT_ADD(LW(0), 45)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
    EVT_THREAD
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
            EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_5)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x10F)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LW(10), LW(0))
            EVT_CALL(PlaySound, 0x10F)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_1)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 20)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_SUB(LW(0), 25)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LW(0), 15)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_4)
            EVT_WAIT_FRAMES(20)
            EVT_IF_EQ(LW(10), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_1)
            EVT_EXEC_WAIT(N(8021B41C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_1)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(10))
    EVT_IF_FLAG(LW(10), STATUS_FLAG_SHRINK)
        EVT_ADD(LW(0), 4)
    EVT_ELSE
        EVT_ADD(LW(0), 10)
    EVT_END_IF
    EVT_SET(LW(1), 27)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.2))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(15), 0, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LW(15))
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(MoveBattleCamOver, 20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_4)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_ADD(LW(0), 40)
            EVT_SET(LW(1), 0)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_ADD(LW(0), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_ADD(LW(0), 20)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_SUB(LW(0), 10)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_1)
            EVT_WAIT_FRAMES(8)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_IF_EQ(LW(15), HIT_RESULT_10)
                EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
                EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_chain_chomp_Palette_00_Anim_1)
            EVT_EXEC_WAIT(N(8021B41C))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_1)
    EVT_END_SWITCH
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, -1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B41C) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, LW(0), LW(1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_chain_chomp_Palette_00_Anim_4)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.8))
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_EXEC_WAIT(N(8021B50C))
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
    EVT_CALL(SetPartPos, ACTOR_SELF, 2, LW(0), LW(1), LW(2))
    EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021B50C) = {
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_IF_LT(LW(3), LW(0))
        EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_ELSE
        EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
    EVT_END_IF
    EVT_LABEL(0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LW(3), LW(4), LW(5))
    EVT_IF_EQ(LW(3), LW(0))
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_LT(LW(3), LW(0))
        EVT_SET(LW(4), LW(0))
        EVT_SUB(LW(4), LW(3))
        EVT_IF_LT(LW(4), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_ELSE
            EVT_SET(LW(4), LW(3))
            EVT_ADD(LW(3), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(3), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_IF
    EVT_ELSE
        EVT_SET(LW(4), LW(3))
        EVT_SUB(LW(4), LW(0))
        EVT_IF_LT(LW(4), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_ELSE
            EVT_SUB(LW(3), 30)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LW(3), LW(1), LW(2))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, 0x2062)
            EVT_THREAD
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
                EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
                    EVT_CALL(ShakeCam, 1, 0, 1, EVT_FLOAT(0.5))
                EVT_END_IF
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_GOTO(0)
    EVT_LABEL(10)
    EVT_RETURN
    EVT_END
};

#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_clubba.h"

extern EvtScript N(init);
extern EvtScript N(idle);
extern EvtScript N(takeTurn);
extern EvtScript N(handleEvent);

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_battle_clubba_Palette_01_Anim_1,
    STATUS_STONE, NPC_ANIM_battle_clubba_Palette_01_Anim_0,
    STATUS_SLEEP, NPC_ANIM_battle_clubba_Palette_01_Anim_3,
    STATUS_POISON, NPC_ANIM_battle_clubba_Palette_01_Anim_1,
    STATUS_STOP, NPC_ANIM_battle_clubba_Palette_01_Anim_0,
    STATUS_STATIC, NPC_ANIM_battle_clubba_Palette_01_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_battle_clubba_Palette_01_Anim_0,
    STATUS_DIZZY, NPC_ANIM_battle_clubba_Palette_01_Anim_5,
    STATUS_FEAR, NPC_ANIM_battle_clubba_Palette_01_Anim_5,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_FIRE, -2,
    ELEMENT_ICE, 99,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 80,
    STATUS_POISON, 50,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 100,
    STATUS_STATIC, 50,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 80,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -12, 32 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ICY,
        .elementImmunityFlags = 0,
        .unk_1C = 8,
        .unk_1D = -3,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_WHITE_CLUBBA,
    .level = 23,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .script = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 50,
    .airLiftChance = 50,
    .spookChance = 60,
    .baseStatusChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 42, 42 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 35 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_ADDR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_ADDR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_ADDR(N(handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_clubba_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_6)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_clubba_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_7)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_2)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_CASE_EQ(EVENT_SHOCK_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT_FRAMES(10)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_2)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_4)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_63)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 27)
        EVT_SET(LW(1), 0)
        EVT_SUB(LW(2), 6)
        EVT_CALL(SetActorPos, ACTOR_SELF, LW(0), LW(1), LW(2))
        EVT_WAIT_FRAMES(15)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_2)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LW(0))
        EVT_IF_NOT_FLAG(LW(0), STATUS_FLAG_SHRINK)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 27, 0, -6)
        EVT_ELSE
            EVT_CALL(AddGoalPos, ACTOR_SELF, 10, 0, -6)
        EVT_END_IF
        EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_1)
        EVT_WAIT_FRAMES(10)
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_8)
            EVT_WAIT_FRAMES(20)
            EVT_IF_EQ(LW(0), HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                EVT_WAIT_FRAMES(20)
            EVT_END_IF
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, 1, 0, 2)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_2)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 1, 0)
            EVT_CALL(SetActorYaw, ACTOR_SELF, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_IF_EQ(LW(0), PHASE_FIRST_STRIKE)
        EVT_GOTO(40)
    EVT_END_IF
    EVT_CALL(GetActorHP, ACTOR_SELF, LW(0))
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LW(1))
    EVT_MULF(LW(0), EVT_FLOAT(100.0))
    EVT_DIVF(LW(0), LW(1))
    EVT_IF_LT(LW(0), 30)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_CALL(RandInt, 100, LW(0))
    EVT_IF_LT(LW(0), 25)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_LABEL(40) // heavy club attack
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_9)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_A)
    EVT_WAIT_FRAMES(2)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_GOTO(100)
    EVT_LABEL(50) // swift club attack
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_9)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_A)
    EVT_WAIT_FRAMES(2)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_10)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_CALL(GetActorHP, ACTOR_PLAYER, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_9)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_A)
    EVT_WAIT_FRAMES(2)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_40)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_CALL(GetActorHP, ACTOR_PLAYER, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_9)
    EVT_WAIT_FRAMES(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20C5)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_clubba_Palette_01_Anim_A)
    EVT_WAIT_FRAMES(2)
    EVT_WAIT_FRAMES(2)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LW(0), DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_THREAD
        EVT_CALL(ShakeCam, 1, 0, 10, EVT_FLOAT(1.5))
    EVT_END_THREAD
    EVT_LABEL(100)
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_WAIT_FRAMES(19)
            EVT_CALL(YieldTurn)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_clubba_Palette_01_Anim_2)
            EVT_EXEC_WAIT(DoReturnHome)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

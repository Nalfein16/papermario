#include "common.h"
#include "battle/battle.h"

void dispatch_event_partner(s32 lastEventType) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ScriptInstance* onHitScript = partnerActor->onHitScript;
    ScriptID onHitID = partnerActor->onHitID;
    ScriptInstance* script;

    partnerActor->lastEventType = lastEventType;
    script = start_script(partnerActor->onHitScriptSource, 10, 0x20);
    partnerActor->onHitScript = script;
    partnerActor->onHitID = script->id;
    script->owner1.actorID = ACTOR_PARTNER;

    if (partnerActor->takeTurnScript != NULL) {
        kill_script_by_ID(partnerActor->takeTurnID);
        partnerActor->takeTurnScript = NULL;
    }

    if (onHitScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

void dispatch_event_partner_continue_turn(s8 lastEventType) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ScriptInstance* onHitScript = partnerActor->onHitScript;
    ScriptID onHitID = partnerActor->onHitID;
    ScriptInstance* script;

    partnerActor->lastEventType = lastEventType;
    script = start_script(partnerActor->onHitScriptSource, 10, 0x20);
    partnerActor->onHitScript = script;
    partnerActor->onHitID = script->id;
    script->owner1.actorID = ACTOR_PARTNER;

    if (onHitScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

INCLUDE_ASM(s32, "1AC760", calc_partner_test_enemy);

INCLUDE_ASM(s32, "1AC760", calc_partner_damage_enemy);

//Some slight stack / ordering issues at the beginning
#ifdef NON_MATCHING
s32 dispatch_damage_event_partner(s32 damageAmount, s32 event, s32 stopMotion) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    ActorMovement* walkMovement = &partner->walk;
    s32 flagCheck;
    s32 temp_a1;

    damageAmount = (s16)damageAmount;
    battleStatus->currentAttackDamage = damageAmount;
    partner->currentHP = 127;
    temp_a1 = (s16)(partner->hpChangeCounter + damageAmount);
    partner->hpChangeCounter += damageAmount;
    partner->hpChangeCounter -= temp_a1;
    partner->damageCounter += temp_a1;
    battleStatus->lastAttackDamage = 0;
    partner->currentHP -= temp_a1;

    if (partner->currentHP <= 0) {
        battleStatus->lastAttackDamage += partner->currentHP;
        partner->currentHP = 0;
        event = 0x20;
    }

    battleStatus->lastAttackDamage += temp_a1;
    partner->lastDamageTaken = battleStatus->lastAttackDamage;
    battleStatus->unk_19A = 0;

    if (battleStatus->flags1 & 0x20) {
        if (event == 0x9) {
            event = 0xA;
        }
        if (event == 0x17) {
            event = 0x19;
        }
    }

    if (battleStatus->lastAttackDamage > 0) {
        BattleStatus* battleStatus2 = &gBattleStatus; // TODO macro for setting flags of battleStatus
        battleStatus2->flags1 |= 0x20;

        inflict_status(partner, 0xD, battleStatus->lastAttackDamage);
    }

    if (stopMotion == 0) {
        set_goal_pos_to_part(walkMovement, 0x100, 0);
    }

    show_damage_popup(walkMovement->goalPos.x, walkMovement->goalPos.y, walkMovement->goalPos.z,
                      battleStatus->lastAttackDamage, 1);
    func_802666E4(partner, walkMovement->goalPos.x, walkMovement->goalPos.y, walkMovement->goalPos.z,
                  battleStatus->lastAttackDamage);

    if (battleStatus->lastAttackDamage > 0) {
        func_80267018(partner, 1);
    }

    partner->flags |= 0x80000;

    flagCheck = (gBattleStatus.flags1 & 0x240) != 0;
    dispatch_event_partner(event);
    return flagCheck;
}
#else
INCLUDE_ASM(s32, "1AC760", dispatch_damage_event_partner);
#endif

s32 dispatch_damage_event_partner_0(s32 damageAmount, s32 event, s32 stopMotion) {
    return dispatch_damage_event_partner(damageAmount, event, FALSE);
}

s32 dispatch_damage_event_partner_1(s32 damageAmount, s32 event, s32 stopMotion) {
    return dispatch_damage_event_partner(damageAmount, event, TRUE);
}

ApiStatus MakeOwnerTargetIndex(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 numTargets = actor->targetListLength;
    s8* targetList = &actor->targetIndexList;
    s32 arg1 = get_variable(script, *args++);
    s32 arg2 = get_variable(script, *args++);
    s32 otherArg = *args++;
    SelectableTarget* selectableTarget;

    if (numTargets == 0) {
        arg2 = -1;
    } else {
        if (arg2 != 0) {
            if (arg2 >= numTargets) {
                arg2 = numTargets - 1;
            } else {
                arg2--;
            }
        }

        selectableTarget = &actor->targetData[targetList[arg2]];
        actor->targetActorID = selectableTarget->actorID;
        actor->targetPartIndex = selectableTarget->partID;
    }

    set_variable(script, otherArg, arg2);
    return ApiStatus_DONE2;
}

s32 calc_partner_damage_enemy(void);

ApiStatus func_8027FC90(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hitResult;
    Actor* actor;
    ActorID actorID = get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    outVar = *args++;
    actor = get_actor(actorID);
    battleStatus->flags1 |= 0x20;

    hitResult = calc_partner_damage_enemy();
    show_damage_popup(actor->walk.goalPos.x, actor->walk.goalPos.y, actor->walk.goalPos.z, battleStatus->lastAttackDamage,
                      0);
    set_variable(script, outVar, hitResult);

    return ApiStatus_DONE2;
}

ApiStatus GetActorLevel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Bytecode* outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    outVar = *args++;
    set_variable(script, outVar, get_actor(actorID)->staticActorData->level);

    return ApiStatus_DONE2;
}

// INCLUDE_ASM(s32, "1AC760", PartnerDamageEnemy);
// s32 calc_partner_damage_enemy(s32); // extern
// s32 does_script_exist_by_ref(void*); // extern
// void* get_actor(s32); // extern
// s16 get_variable(void*, s32); // extern
// ? set_variable(void*, s32, s32); // extern
// extern ? gBattleStatus;

// ? PartnerDamageEnemy(void* arg0) {
//     s32 temp_s0_6;
//     s32 temp_s4;
//     s32 temp_v0;
//     s32* temp_s0;
//     s32* temp_s0_2;
//     s32* temp_s0_3;
//     s32* temp_s0_4;
//     s32* temp_s0_5;
//     u8 temp_v1;
//     void* temp_s3;
//     s32 phi_v0;
//     s32 phi_v0_2;

//     temp_s0 = arg0->unkC;
//     temp_s4 = *temp_s0;
//     temp_s0_2 = temp_s0 + 4;
//     temp_s0_3 = temp_s0_2 + 4;
//     temp_s3 = get_actor(arg0->unk148);
//     gBattleStatus.unk188 = (s32) *temp_s0_2;
//     temp_s0_4 = temp_s0_3 + 4;
//     gBattleStatus.unk18C = (s32) *temp_s0_3;
//     temp_s0_5 = temp_s0_4 + 4;
//     gBattleStatus.unk190 = (s32) *temp_s0_4;
//     gBattleStatus.unk17E = get_variable(arg0, *temp_s0_5);
//     gBattleStatus.unk198 = 0;
//     temp_s0_6 = *(temp_s0_5 + 4);
//     if ((temp_s0_6 & 0x30) != 0x30) {
//         if ((temp_s0_6 & 0x10) != 0) {
//             phi_v0_2 = gBattleStatus.unk0 | 0x10;
//             goto block_9;
//         }
//         if ((temp_s0_6 & 0x20) != 0) {
//             phi_v0 = (gBattleStatus.unk0 & ~0x10) | 0x20;
//         } else {
//             phi_v0_2 = gBattleStatus.unk0 & ~0x10;
// block_9:
//             phi_v0 = phi_v0_2 & ~0x20;
//         }
//     } else {
//         phi_v0 = gBattleStatus.unk0 | 0x30;
//     }
//     gBattleStatus.unk0 = phi_v0;
//     if ((temp_s0_6 & 0x40) != 0) {
//         gBattleStatus.unk0 = (s32) (gBattleStatus.unk0 | 0x40);
//     } else {
//         gBattleStatus.unk0 = (s32) (gBattleStatus.unk0 & ~0x40);
//     }
//     if ((temp_s0_6 & 0x200) != 0) {
//         gBattleStatus.unk0 = (s32) (gBattleStatus.unk0 | 0x200);
//     } else {
//         gBattleStatus.unk0 = (s32) (gBattleStatus.unk0 & ~0x200);
//     }
//     if ((temp_s0_6 & 0x80) != 0) {
//         gBattleStatus.unk0 = (s32) (gBattleStatus.unk0 | 0x80);
//     } else {
//         gBattleStatus.unk0 = (s32) (gBattleStatus.unk0 & ~0x80);
//     }
//     if ((temp_s0_6 & 0x800) != 0) {
//         gBattleStatus.unk0 = (s32) (gBattleStatus.unk0 | 0x800);
//     } else {
//         gBattleStatus.unk0 = (s32) (gBattleStatus.unk0 & ~0x800);
//     }
//     temp_v1 = gBattleStatus.unk193;
//     gBattleStatus.unk1A0 = (u16) temp_s3->unk428;
//     gBattleStatus.unk194 = temp_v1;
//     gBattleStatus.unk1A2 = (u8) temp_s3->unk426;
//     if ((temp_v1 & 0xFF) == 0xFF) {
//         gBattleStatus.unk194 = 0U;
//     }
//     gBattleStatus.unk195 = (s8) ((s32) (gBattleStatus.unk190 & 0xF00) >> 8);
//     temp_v0 = calc_partner_damage_enemy(-0x801);
//     if (temp_v0 >= 0) {
//         set_variable(arg0, temp_s4, temp_v0);
//         if (does_script_exist_by_ref(arg0) != 0) {
//             return 2;
//         }
//         // Duplicate return node #28. Try simplifying control flow for better match
//         return 0xFF;
//     }
//     return 0xFF;
// }
s32 PartnerDamageEnemy(ScriptInstance* script) { // a0, s2
    s32* ptrReadPos; // s0
    s32 ptrReadPosCopy; // s4
    Actor* enemyActor;
    s8 labelIndices;
    s8 labelIndices4;
    s8 labelIndices8;
    s8 labelPositions;
    s32 labelPositions4;
    u8 currentAttackStatus;
    s32 setFlags1;
    s32 setFlags1Helper;
    s32 damageDealt;

    ptrReadPos = script->ptrReadPos;
    enemyActor = get_actor(script->owner1.enemyID);
    ptrReadPosCopy = *ptrReadPos; // 1f60

    labelIndices = script->labelIndices[0];
    labelIndices += 4;
    labelIndices4 = script->labelIndices[labelIndices];
    labelIndices += 4;
    labelIndices8 = script->labelIndices[labelIndices];
    labelPositions = script->labelPositions[0];

    gBattleStatus.currentAttackElement = labelIndices;
    gBattleStatus.currentAttackEventSuppression = labelIndices4;
    gBattleStatus.currentAttackStatus = labelIndices8;
    gBattleStatus.currentAttackDamage = get_variable(script, labelPositions);
    gBattleStatus.powerBounceCounter = 0;
    
    labelPositions4 = script->labelPositions[labelPositions + 4];

    if ((labelPositions4 & 0x30) != 0x30) {
        if ((labelPositions4 & 0x10) != 0) {
            setFlags1Helper = gBattleStatus.flags1 | 0x10;
            goto block_9;
        }

        if ((labelPositions4 & 0x20) != 0) {
            setFlags1 = (gBattleStatus.flags1 & ~0x10) | 0x20;
        } else {
            setFlags1Helper = gBattleStatus.flags1 & ~0x10;
block_9:
            setFlags1 = setFlags1Helper & ~0x20;
        }
        
    } else {
        setFlags1 = gBattleStatus.flags1 | 0x30;
    }

    gBattleStatus.flags1 = setFlags1;

    if ((labelPositions4 & 0x40) != 0) {
        gBattleStatus.flags1 = (s32) (gBattleStatus.flags1 | 0x40);
    } else {
        gBattleStatus.flags1 = (s32) (gBattleStatus.flags1 & ~0x40);
    }

    if ((labelPositions4 & 0x200) != 0) {
        gBattleStatus.flags1 = (s32) (gBattleStatus.flags1 | 0x200);
    } else {
        gBattleStatus.flags1 = (s32) (gBattleStatus.flags1 & ~0x200);
    }

    if ((labelPositions4 & 0x80) != 0) {
        gBattleStatus.flags1 = (s32) (gBattleStatus.flags1 | 0x80);
    } else {
        gBattleStatus.flags1 = (s32) (gBattleStatus.flags1 & ~0x80);
    }

    if ((labelPositions4 & 0x800) != 0) {
        gBattleStatus.flags1 = (s32) (gBattleStatus.flags1 | 0x800);
    } else {
        gBattleStatus.flags1 = (s32) (gBattleStatus.flags1 & ~0x800);
    }

    currentAttackStatus = gBattleStatus.currentAttackStatus;
    gBattleStatus.currentTargetID = (u16) enemyActor->targetActorID;
    gBattleStatus.statusChance = currentAttackStatus;
    gBattleStatus.currentTargetPart = (u8) enemyActor->targetPartIndex;
    if ((currentAttackStatus & 0xFF) == 0xFF) {
        gBattleStatus.statusChance = 0U;
    }
    gBattleStatus.statusDuration = (s8) ((s32) (gBattleStatus.currentAttackStatus & 0xF00) >> 8);

    // damageDealt = calc_partner_damage_enemy(-0x801);
    damageDealt = calc_partner_damage_enemy(); // this is a void call... what's with the number?
    if (damageDealt >= 0) {
        set_variable(script, ptrReadPosCopy, damageDealt);
        if (does_script_exist_by_ref(script) != 0) {
            return 2;
        }
        // Duplicate return node #28. Try simplifying control flow for better match
        return 0xFF;
    }
    return 0xFF;
}


INCLUDE_ASM(s32, "1AC760", PartnerAfflictEnemy);

INCLUDE_ASM(s32, "1AC760", PartnerPowerBounceEnemy);

INCLUDE_ASM(s32, "1AC760", PartnerTestEnemy);

ApiStatus func_8028070C(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 damageAmount = get_variable(script, *args++);
    s32 event = get_variable(script, *args++);

    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;

    if (dispatch_damage_event_partner_0(damageAmount, event, battleStatus) >= 0) {
        return does_script_exist_by_ref(script) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}

ApiStatus DeletePartner(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    btl_delete_actor(battleStatus->partnerActor);
    return ApiStatus_DONE2;
}

ApiStatus GetActionCommandResult(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var = *script->ptrReadPos;
    s32 actionSuccess = battleStatus->actionSuccess;
    s32 outVal = 0;

    if (actionSuccess < outVal) {
        actionSuccess = outVal;
    }

    if (actionSuccess > outVal) {
        outVal = actionSuccess;
    }

    set_variable(script, var, outVal);
    return ApiStatus_DONE2;
}

/// Seems to be the same functionality as YieldTurn in 1A5830.c
ApiStatus func_80280818(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x200000;
    return ApiStatus_DONE2;
}

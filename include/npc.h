#ifndef _NPC_H_
#define _NPC_H_

#include "common_structs.h"
#include "enums.h"
#include "script_api/map.h"

#define NO_DROPS { { F16(100), F16(0), 0, F16(0) }, }

#define STANDARD_HEART_DROPS(attempts) { \
    { F16(20), F16(70), attempts, F16(50) }, \
    { F16(30), F16(60), attempts, F16(50) }, \
    { F16(50), F16(50), attempts, F16(40) }, \
    { F16(80),  F16(40), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(30) }, \
}

#define GENEROUS_HEART_DROPS(attempts) { \
    { F16(20), F16(80), attempts, F16(50) } \
    { F16(30), F16(70), attempts, F16(50) } \
    { F16(50), F16(60), attempts, F16(40) } \
    { F16(80), F16(50), attempts, F16(40) } \
    { F16(100), F16(40), attempts, F16(30) }, \
}

#define GENEROUS_WHEN_LOW_HEART_DROPS(attempts) { \
    { F16(20), F16(80), attempts, F16(60) }, \
    { F16(30), F16(70), attempts, F16(50) }, \
    { F16(50), F16(60), attempts, F16(50) }, \
    { F16(80), F16(50), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(30) }, \
}

#define STANDARD_FLOWER_DROPS(attempts) { \
    { F16(20), F16(50), attempts, F16(40) }, \
    { F16(30), F16(40), attempts, F16(40) }, \
    { F16(50), F16(40), attempts, F16(40) }, \
    { F16(80), F16(40), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(40) }, \
}

#define GENEROUS_WHEN_LOW_FLOWER_DROPS(attempts) { \
    { F16(20), F16(70), attempts, F16(50) }, \
    { F16(30), F16(60), attempts, F16(50) }, \
    { F16(50), F16(50), attempts, F16(40) }, \
    { F16(80), F16(40), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(40) }, \
}

#define REDUCED_FLOWER_DROPS(attempts) { \
    { F16(20), F16(40), attempts, F16(40) }, \
    { F16(30), F16(40), attempts, F16(40) }, \
    { F16(50), F16(40), attempts, F16(40) }, \
    { F16(80), F16(40), attempts, F16(40) }, \
    { F16(100), F16(30), attempts, F16(40) }, \
}

#define OVERRIDE_MOVEMENT_SPEED(speed) (speed * 32767)
#define NO_OVERRIDE_MOVEMENT_SPEED OVERRIDE_MOVEMENT_SPEED(-1)

typedef struct QuizRequirement {
    s32 requiredStoryProgress;
    s32 numQuestionsUnlocked;
} QuizRequirement; // size = 0x8

typedef struct NpcBlueprint {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 initialAnim;
    /* 0x08 */ void (*onUpdate)(struct Npc*);
    /* 0x0C */ void (*onRender)(struct Npc*);
} NpcBlueprint; // size = 0x10

typedef struct NpcAISettings {
    /* 0x00 */ f32 moveSpeed;
    /* 0x04 */ s32 moveTime;
    /* 0x08 */ s32 waitTime;
    /* 0x0C */ f32 alertRadius;
    /* 0x10 */ f32 alertOffsetDist;         // offset along npc->yaw of the test point for alert volume overlap, creates directionality to enemy 'sight'
    /* 0x14 */ s32 playerSearchInterval;    // how often to search for player (frames)
    /* 0x18 */ f32 chaseSpeed;
    /* 0x1C */ s32 chaseTurnRate;           // how many degrees this NPC can turn per frame while chasing
    /* 0x20 */ s32 chaseUpdateInterval;     // how often to re-run chase init and re-acquire player position (frames)
    /* 0x24 */ f32 chaseRadius;
    /* 0x28 */ f32 chaseOffsetDist;         // offset along npc->yaw of the test point for chase volume overlap, creates directionality to enemy 'sight'
    /* 0x2C */ s32 unk_AI_2C;               // unk time
} NpcAISettings; // size = 0x30

typedef struct NpcSettings {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 height;
    /* 0x06 */ s16 radius;
    /* 0x08 */ UNK_PTR otherAI;
    /* 0x0C */ EvtScript* onInteract;
    /* 0x10 */ EvtScript* ai;
    /* 0x14 */ EvtScript* onHit;
    /* 0x18 */ EvtScript* aux;
    /* 0x1C */ EvtScript* onDefeat;
    /* 0x20 */ s32 flags;
    /* 0x24 */ char unk_24[4];
    /* 0x28 */ s16 level;
    /* 0x2A */ s16 unk_2A;  // action flags: 1 = jump on seeing player
} NpcSettings; // size = 0x2C

typedef struct ItemDrop {
    /* 0x00 */ s16 item;
    /* 0x02 */ s16 weight;
    /* 0x04 */ s16 unk_08;
} ItemDrop; // size = 0x06

/// @brief Describes heart/flower drop chances after defeating an Npc in the overworld.
///
/// The algorithm for calculating the number of hearts/flowers from a StatDrop is:
/// - If current HP/FP > cutoff, drop 0.
/// - Roll generalChance. If it fails, drop 0.
/// - Roll chancePerAttempt attempts times. For each success, drop a heart/flower.
///
/// StaticNpc holds a table of StatDrops for each stat (hearts, flowers). All are checked together
/// and the number of hearts/flowers to drop is the total number of successful attempts for each stat.
///
/// Each heart/flower is worth 1 HP and 1 FP respectively, if picked up.
///
/// cutoff, generalChance, and chancePerAttempt are short fixed-point percentage values.
/// That is, `F16(0)` is a 0% chance and `F16(100)` is a 100% chance.
typedef struct StatDrop {
    /* 0x00 */ s16 cutoff;           ///< % of max HP/FP. If current HP/FP > cutoff, no hearts/flowers can be dropped.
    /* 0x02 */ s16 generalChance;    ///< % chance for any hearts/flowers to be dropped at all from this StatDrop.
    /* 0x04 */ s16 attempts;         ///< Maximum number of hearts/flowers that can be dropped from this StatDrop.
    /* 0x06 */ s16 chancePerAttempt; ///< % chance for a single heart/flower to be dropped from each attempt.
} StatDrop; // size = 0x08

typedef struct StaticNpc {
    /* 0x000 */ s32 id;
    /* 0x004 */ NpcSettings* settings;
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ s32 flags;
    /* 0x018 */ EvtScript* init;
    /* 0x01C */ char unk_1C[8];
    /* 0x024 */ s32 yaw;
    /* 0x028 */ u8 dropFlags; // TODO: use EnemyDrops (requires tons of map edits)
    /* 0x029 */ s8 itemDropChance; // %
    /* 0x02A */ ItemDrop itemDrops[8];
    /* 0x05A */ StatDrop heartDrops[8];
    /* 0x09A */ StatDrop flowerDrops[8];
    /* 0x0DA */ s16 minCoinBonus;
    /* 0x0DC */ s16 maxCoinBonus;
    /* 0x0E0 */ s32 movement[48]; // TODO: type
    /* 0x1A0 */ struct {
        /* 0x00 */ s32 idle;
        /* 0x04 */ s32 walk;
        /* 0x08 */ s32 run;
        /* 0x0C */ s32 chase;
        /* 0x10 */ s32 unk_10;
        /* 0x14 */ s32 unk_14;
        /* 0x18 */ s32 death;
        /* 0x1C */ s32 hit;
        /* 0x20 */ s32 unk_20;
        /* 0x24 */ s32 unk_24;
        /* 0x28 */ s32 unk_28;
        /* 0x2C */ s32 unk_2C;
        /* 0x30 */ s32 unk_30;
        /* 0x34 */ s32 unk_34;
        /* 0x38 */ s32 unk_38;
        /* 0x3C */ s32 unk_3C;
    } animations;
    /* 0x1E0 */ char unk_1E0[8];
    /* 0x1E8 */ s32* extraAnimations;
    /* 0x1EC */ s32 tattle;
} StaticNpc; // size = 0x1F0

/// Zero-terminated.
typedef struct {
    /* 0x00 */ s32 npcCount;
    /* 0x04 */ StaticNpc* npcs;
    /* 0x08 */ s32 battle;
} NpcGroupList[]; // size = 0x0C

#define NPC_GROUP(npcs, battle) { sizeof(npcs) / sizeof(StaticNpc), (StaticNpc*) &npcs, battle }

typedef struct EnemyDrops {
    /* 0x00 */ u8 dropFlags;
    /* 0x01 */ s8 itemDropChance; // %
    /* 0x02 */ ItemDrop itemDrops[8];
    /* 0x32 */ StatDrop heartDrops[8];
    /* 0x72 */ StatDrop flowerDrops[8];
    /* 0xB2 */ s16 minCoinBonus;
    /* 0xB4 */ s16 maxCoinBonus;
    /* 0xB6 */ char unk_DE[2];
} EnemyDrops; // size = 0xB8

enum TerritoryShape { SHAPE_CYLINDER, SHAPE_RECT };

typedef struct {
    /* 0x00 */ s32 skipPlayerDetectChance;
    /* 0x04 */ enum TerritoryShape shape;
    /* 0x08 */ s32 pointX;
    /* 0x0C */ s32 pointZ;
    /* 0x10 */ s32 sizeX;
    /* 0x14 */ s32 sizeZ;
    /* 0x18 */ f32 halfHeight;
    /* 0x1C */ s16 detectFlags;  // 1 = ignore partner hiding (bow/sushie dont work) | 2 = ignore elevation
} EnemyDetectVolume; // size = 0x20

typedef struct {
    /* 0x00 */ Vec3i point;
    /* 0x0C */ s32 wanderSizeX;
    /* 0x10 */ s32 wanderSizeZ;
    /* 0x14 */ s32 moveSpeedOverride;
    /* 0x18 */ enum TerritoryShape wanderShape;
    /* 0x1C */ Vec3i detect;
    /* 0x28 */ s32 detectSizeX;
    /* 0x2C */ s32 detectSizeZ;
    /* 0x30 */ enum TerritoryShape detectShape;
    /* 0x34 */ s32 isFlying;
} EnemyTerritoryWander; // size = 0x38

typedef struct {
    /* 0x00 */ s32 numPoints;
    /* 0x04 */ Vec3i points[10];
    /* 0x7C */ s32 moveSpeedOverride;
    /* 0x80 */ Vec3i detect;
    /* 0x8C */ s32 detectSizeX;
    /* 0x90 */ s32 detectSizeZ;
    /* 0x94 */ enum TerritoryShape detectShape;
    /* 0x98 */ s32 isFlying;
} EnemyTerritoryPatrol; // size = 0x9C

typedef union {
    EnemyTerritoryWander wander;
    EnemyTerritoryPatrol patrol;
    char PADDING[0xC0];
} EnemyTerritory; // size = 0xC0

// function signature used for state handlers in AI main functions
typedef void AIStateHandler(Evt* script, NpcAISettings* settings, EnemyDetectVolume* territory);

typedef struct Enemy {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s8 encounterIndex;
    /* 0x05 */ s8 encountered;
    /* 0x06 */ u8 scriptGroup; /* scripts launched for this npc controller will be assigned this group */
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ s16 npcID;
    /* 0x0A */ s16 spawnPos[3];
    /* 0x10 */ Vec3s unk_10;
    /* 0x16 */ char unk_16[2];
    /* 0x18 */ NpcSettings* npcSettings;
    /* 0x1C */ EvtScript* initBytecode;
    /* 0x20 */ EvtScript* interactBytecode;
    /* 0x24 */ EvtScript* aiBytecode;
    /* 0x28 */ EvtScript* hitBytecode;
    /* 0x2C */ EvtScript* auxBytecode;
    /* 0x30 */ EvtScript* defeatBytecode;
    /* 0x34 */ struct Evt* initScript;
    /* 0x38 */ struct Evt* interactScript;
    /* 0x3C */ struct Evt* aiScript;
    /* 0x40 */ struct Evt* hitScript;
    /* 0x44 */ struct Evt* auxScript;
    /* 0x48 */ struct Evt* defeatScript;
    /* 0x4C */ s32 initScriptID;
    /* 0x50 */ s32 interactScriptID;
    /* 0x54 */ s32 aiScriptID;
    /* 0x58 */ s32 hitScriptID;
    /* 0x5C */ s32 auxScriptID;
    /* 0x60 */ s32 defeatScriptID;
    /* 0x64 */ UNK_PTR unk_64;
    /* 0x68 */ char unk_68[4];
    /* 0x6C */ union {
    /*      */      s32 varTable[16];
    /*      */      f32 varTableF[16];
    /*      */      void* varTablePtr[16];
    /*      */ };
    /* 0xAC */ u8 aiDetectFlags; // detect player flags: 1 = require line of sight | 2 = adjust hitbox for moving player
    /* 0xAD */ char unk_AD[3];
    /* 0xB0 */ u32 aiFlags;
    /* 0xB4 */ s8 aiPaused;
    /* 0xB5 */ s8 unk_B5;
    /* 0xB6 */ char unk_B6[2];
    /* 0xB8 */ EvtScript* unk_B8; // some bytecode
    /* 0xBC */ struct Evt* unk_BC; // some script
    /* 0xC0 */ s32 unk_C0; // some script ID
    /* 0xC4 */ s32 unk_C4;
    /* 0xC8 */ s32 unk_C8;
    /* 0xCC */ s32* animList;
    /* 0xD0 */ EnemyTerritory* territory;
    /* 0xD4 */ EnemyDrops* drops;
    /* 0xD8 */ u32 tattleMsg;
    /* 0xDC */ s32 unk_DC;
    /* 0xE0 */ s16 unk_E0;
    /* 0xE2 */ char unk_E2[0xE];
} Enemy; // size = 0xF0

typedef struct Encounter {
    /* 0x00 */ s32 count;
    /* 0x04 */ Enemy* enemy[16];
    /* 0x44 */ s16 battle;
    /* 0x46 */ s16 stage;
    /* 0x48 */ s16 encounterID;
    /* 0x4A */ char unk_4C[0x12];
} Encounter; // size = 0x5C

typedef struct EncounterStatus {
    /* 0x000 */ s32 flags;
    /* 0x004 */ s8 eFirstStrike; /* 0 = none, 1 = player, 2 = enemy */
    /* 0x005 */ s8 hitType; /* 1 = none/enemy, 2 = jump */
    /* 0x006 */ s8 hitTier; /* 0 = normal, 1 = super, 2 = ultra */
    /* 0x007 */ char unk_07;
    /* 0x008 */ s8 unk_08;
    /* 0x009 */ s8 battleOutcome; /* 0 = won, 1 = lost */
    /* 0x00A */ s8 unk_0A;
    /* 0x00B */ s8 merleeCoinBonus; /* triple coins when != 0 */
    /* 0x00C */ u8 damageTaken; /* valid after battle */
    /* 0x00D */ char unk_0D;
    /* 0x00E */ s16 coinsEarned; /* valid after battle */
    /* 0x010 */ char unk_10;
    /* 0x011 */ u8 allowFleeing;
    /* 0x012 */ s8 unk_12;
    /* 0x013 */ u8 dropWhackaBump;
    /* 0x014 */ s32 songID;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s8 numEncounters; /* number of encounters for current map (in list) */
    /* 0x01D */ s8 currentAreaIndex;
    /* 0x01E */ u8 currentMapIndex;
    /* 0x01F */ u8 currentEntryIndex;
    /* 0x020 */ s8 mapID;
    /* 0x021 */ s8 resetMapEncounterFlags;
    /* 0x021 */ char unk_22[2];
    /* 0x024 */ s32* npcGroupList;
    /* 0x028 */ Encounter* encounterList[24];
    /* 0x088 */ Encounter* currentEncounter;
    /* 0x08C */ Enemy* currentEnemy;
    /* 0x090 */ s32 fadeOutAmount;
    /* 0x094 */ s32 unk_94;
    /* 0x098 */ s32 fadeOutAccel;
    /* 0x09C */ s32 battleStartCountdown;
    /* 0x0A0 */ s8 unk_A0;
    /* 0x0A1 */ char unk_A1[0x1];
    /* 0x0A2 */ s16 unk_A2;
    /* 0x0A4 */ char unk_A4[0xC];
    /* 0x0B0 */ s32 defeatFlags[60][12];
    /* 0xFB0 */ s16 recentMaps[2];
    /* 0xFB4 */ char unk_FB4[4];
} EncounterStatus; // size = 0xFB8

extern EncounterStatus gCurrentEncounter;

s32 basic_ai_check_player_dist(EnemyDetectVolume* arg0, Enemy* arg1, f32 arg2, f32 arg3, s8 arg4);

/// The default Npc::onUpdate and Npc::onRender callback.
void STUB_npc_callback(Npc*);

void mtx_ident_mirror_y(Matrix4f mtx);

void clear_npcs(void);

/// Points the current NPC list to the world or battle lists depending on game state.
void init_npc_list(void);

/// Iterates over the NPC list, doing absolutely nothing.
/// Presumably did something once upon a time but got commented out.
void npc_iter_no_op(void);

s32 _create_npc(NpcBlueprint* blueprint, s32** animList, s32 skipLoadingAnims);

s32 _create_npc_basic(NpcBlueprint* blueprint);

s32 _create_npc_standard(NpcBlueprint* blueprint, s32** animList);

void _create_npc_partner(NpcBlueprint* blueprint);

void free_npc_by_index(s32 listIndex);

void free_npc(Npc* npc);

Npc* get_npc_by_index(s32 listIndex);

void npc_do_world_collision(Npc* npc);

void npc_do_other_npc_collision(Npc* npc);

/// @returns TRUE if a collision occurred
s32 npc_do_player_collision(Npc* npc);

void npc_do_gravity(Npc* npc);

s32 func_800397E8(Npc* npc, f32 arg1);

/// Updates all NPCs.
void update_npcs(void);

f32 npc_get_render_yaw(Npc* npc);

void appendGfx_npc(Npc* npc);

/// Renders all NPCs.
void render_npcs(void);

void npc_move_heading(Npc* npc, f32 speed, f32 yaw);

Npc* get_npc_unsafe(s32 npcID);

/// @returns NULL if not found
Npc* get_npc_safe(s32 npcID);

void enable_npc_shadow(Npc* npc);

void disable_npc_shadow(Npc* npc);

void update_npc_blur(Npc* npc);

void appendGfx_npc_blur(Npc* npc);

void npc_enable_collisions(void);

void npc_disable_collisions(void);

void func_8003B1A8(void);

void npc_reload_all(void);

void set_npc_yaw(Npc* npc, f32 yaw);

void npc_set_palswap_mode_A(Npc* npc, s32 arg1);

void npc_set_palswap_mode_B(Npc* npc, s32 arg1);

void func_8003B420(Npc* npc);

void npc_set_palswap_1(Npc* npc, s32 palIndexA, s32 palIndexB, s32 timeHoldA, s32 timeAB);

void npc_set_palswap_2(Npc* npc, s32 timeHoldB, s32 timeBA, s32 palIndexC, s32 palIndexD);

void npc_draw_with_palswap(Npc* npc, s32 arg1, Matrix4f mtx);

void npc_draw_palswap_mode_0(Npc* npc, s32 arg1, Matrix4f mtx);

s32 npc_draw_palswap_mode_1(Npc*, s32, Matrix4f mtx);

u16 npc_blend_palette_colors(u16 colorA, u16 colorB, s32 lerpAlpha);

s32 npc_draw_palswap_mode_2(Npc*, s32, s32, Matrix4f mtx);

s32 npc_draw_palswap_mode_4(Npc*, s32, Matrix4f mtx);

void npc_set_decoration(Npc* npc, s32 idx, s32 decorationType);

void npc_remove_decoration(Npc* npc, s32 idx);

s32 npc_update_decorations(Npc* npc);

void npc__remove_decoration(Npc* npc, s32 idx);

void npc_reset_current_decoration(Npc* npc, s32 idx);

void npc_update_decoration_none(Npc* npc, s32 idx);

void npc_remove_decoration_none(Npc* npc, s32 idx);

void npc_update_decoration_bowser_aura(Npc* npc, s32 idx);

void npc_remove_decoration_bowser_aura(Npc* npc, s32 idx);

void npc_update_decoration_sweat(Npc* npc, s32 idx);

void npc_remove_decoration_sweat(Npc* npc, s32 idx);

void npc_update_decoration_seeing_stars(Npc* npc, s32 idx);

void npc_remove_decoration_seeing_stars(Npc* npc, s32 idx);

void npc_update_decoration_glow_in_front(Npc* npc, s32 idx);

void npc_remove_decoration_glow_in_front(Npc* npc, s32 idx);

void npc_update_decoration_glow_behind(Npc* npc, s32 idx);

void npc_remove_decoration_glow_behind(Npc* npc, s32 idx);

void npc_update_decoration_charged(Npc* npc, s32 idx);

void npc_remove_decoration_charged(Npc* npc, s32 idx);

void npc__reset_current_decoration(Npc* npc, s32 idx);

/// Finds the closest NPC to a given point within a radius. Ignores Y position.
///
/// NPCs with NPC_FLAG_PARTICLE set are ignored.
/// See also npc_find_closest_simple(), which requires that NPC_FLAG_PARTICLE be set.
///
/// @param x        X position
/// @param y        Y position (unused)
/// @param z        Z position
/// @param radius   No NPCs further than this distance will be considered
///
/// @returns NULL if there are no NPCs within radius
Npc* npc_find_closest(f32 x, f32 y, f32 z, f32 radius);

/// Finds the closest simple-hitbox NPC to a given point within a radius. Ignores Y position.
///
/// Only NPCs with NPC_FLAG_PARTICLE set are considered.
/// See also npc_find_closest(), which requires that NPC_FLAG_PARTICLE be unset.
///
/// @param x        X position
/// @param y        Y position (unused)
/// @param z        Z position
/// @param radius   No NPCs further than this distance will be considered
///
/// @returns NULL if there are no NPCs within radius
Npc* npc_find_closest_simple(f32 x, f32 y, f32 z, f32 radius);

//s32 npc_find_standing_on_entity();

s32 npc_get_collider_below(Npc* npc);

void func_8003D3BC(Npc* npc);

void func_8003D624(Npc* npc, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);

void func_8003D660(Npc* npc, s32);

void func_8003D788(Npc* npc, s32);

void func_8003DA38(Npc* npc, s32);

s32 func_8003DC38(Npc*, s32);

void func_8003DFA0(Npc* npc, s32);

void func_8003E0D4(Npc* npc, s32);

void func_8003E1D0(Npc* npc, s32);

/// Duplicate of set_defeated().
void COPY_set_defeated(s32 mapID, s32 encounterID);

void init_encounter_status(void);

void clear_encounter_status(void);

void func_8003E50C(void);

void func_8003E514(s8 arg0);

void update_encounters(void);

void draw_encounter_ui(void);

void draw_first_strike_ui(void);

void npc_dyn_entity_draw_no_op(void);

void make_npcs(s32 flags, s32 mapID, s32* npcGroupList);

s32 kill_encounter(Enemy* enemy);

void kill_enemy(Enemy* enemy);

/// Binds the specified ai script to the specified enemy
///
/// @param enemy               pointer to the enemy to bind the script to
/// @param aiScriptBytecode    pointer to the script to be bound.
s32 bind_enemy_ai(Enemy* enemy, EvtScript* aiScriptBytecode);

/// Binds the specified auxillary script to the specified enemy
///
/// @param enemy               pointer to the enemy to bind the script to
/// @param auxScriptBytecode   pointer to the script to be bound.
s32 bind_enemy_aux(Enemy* enemy, EvtScript* auxScriptBytecode);

/// Binds the specified interact script to the specified enemy
///
/// @param enemy                    pointer to the enemy to bind the script to
/// @param interactScriptBytecode   pointer to the script to be bound.
s32 bind_enemy_interact(Enemy* enemy, EvtScript* interactScriptBytecode);

/// Binds the specified ai script to the npc matching the specified npcId
///
/// @param npcID           ID of the desired npc
/// @param npcAiBytecode   pointer to the script to be bound.
void bind_npc_ai(s32 npcID, EvtScript* npcAiBytecode);

/// Binds the specified auxillary script to the npc matching the specified npcId
///
/// @param npcID           ID of the desired npc
/// @param npcAuxBytecode  pointer to the script to be bound.
void bind_npc_aux(s32 npcID, EvtScript* npcAuxBytecode);

/// Binds the specified interact script to the npc matching the specified npcId
///
/// @param npcID                ID of the desired npc
/// @param npcInteractBytecode  pointer to the script to be bound.
void bind_npc_interact(s32 npcID, EvtScript* npcInteractBytecode);

/// Looks for an enemy matching the specified npcID.
///
/// @param npcID   ID of the npc bound to the desired enemy.
///
/// @returns pointer to Enemy struct, if one is found. If one is not found, a panic occurs.
Enemy* get_enemy(s32 npcID);

/// Same as get_enemy(), with the exception of always returning a value if an enemy is not found.
///
/// @param npcID   ID of the npc bound to the desired enemy.
///
/// @returns pointer to Enemy struct, if one is found. Otherwise, NULL.
Enemy* get_enemy_safe(s32 npcID);

#endif

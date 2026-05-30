#ifndef SKILL_TYPES_H
#define SKILL_TYPES_H

#include "math.h"

typedef enum {
    STR,
    DEX,
    VIT,
    SPR,
    INT,
    AWA,
    CHA,
    LCK
} Attribute;

typedef enum {
    BRAWL,              // STR
    AXES,
    POLEARMS,
    GREATSWORDS,
    ARMOR,
    HEAVY_ARMOR,
    GRAPPLING,
    SWIMMING,
    FENCING,
    ARCHERY,            // DEX
    ACROBATICS,
    STEALTH,
    LOCKPICKING,
    SLEIGHT_OF_HAND,
    CRAFTS,
    WELLNESS,           // VIT
    ENDURANCE,
    BEAUTY,
    INSIGHT,            // SPR
    ATTUNEMENT,
    MEDICINE,
    WILL,
    ARTS,
    EDUCATION,          // INT
    HISTORY,
    OCCULT,
    NATURE,
    INVESTIGATION,
    SENSE,              // AWA
    TRACKING,
    NAVIGATION,
    CHARM,              // CHA
    PERSUASION,
    DECEPTION,
    PERFORMANCE,
    FATE,               // LCK
    FORTUNE,
    GAMBLING
} Skill;

typedef struct {
    Skill id;
    Attribute default_stat;
    char* name;
    byte untrained_value;
    // Maybe add this? Maybe not...
    // char* description;
} SkillData;

typedef struct {
    Skill id;
    byte rank;
} SkillRank;

typedef struct {
    byte length;
    SkillRank* ranks;
} Skills;

typedef enum {
    SOLDIER,
    NOBLE,
    SCHOLAR,
    URCHIN,
    MERCHANT
} Background;

typedef struct {
    Background id;
    char* name;
    Skills base_skills;
} BackgroundData;

#endif


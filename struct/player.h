#ifndef PLAYER_TYPES_H
#define PLAYER_TYPES_H

#include "math.h"
#include "skill.h"

typedef enum {
    SHE = 1,
    HE = 2,
    THEY = 3
} Pronoun;

typedef enum {
    ROGUE,
    FIGHTER,
    MAGE,
    PRIESTESS,
    MONK
} Class;

typedef struct {
    byte str;
    byte dex;
    byte vit;
    byte spr;
    byte intel;
    byte awa;
    byte cha;
    byte lck;
} Attributes;

typedef struct {
    char* name;
    Pronoun pronoun;
    int exp;
    sint hp;
    sint max_hp;
    Attributes attributes;
    Class class;
    Background background;
    Skills skills;
    byte skill_points;
} Adventurer;

typedef struct {
    Adventurer* party_members;
    int size;
} Party;

typedef struct {
    Party party;
    int money;
    ushort location;
} Player;

#endif


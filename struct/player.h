#ifndef PLAYER_TYPES_H
#define PLAYER_TYPES_H

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
    int str;
    int dex;
    int vit;
    int spr;
    int intel;
    int awa;
    int cha;
    int lck;
} Attributes;

typedef struct {
    char* name;
    Pronoun pronoun;
    int exp;
    int hp;
    int max_hp;
    Class class;
    Attributes attributes;
} Adventurer;

typedef struct {
    Adventurer* party_members;
    int size;
} Party;

typedef struct {
    Party party;
    int money;
    int location;
} Player;

#endif


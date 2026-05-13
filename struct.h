#ifndef STRUCT_H
#define STRUCT_H

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

typedef enum {
    ROGUE,
    FIGHTER,
    MAGE,
    PRIESTESS,
    MONK
} Class;

typedef struct {
    Class class;
    char* name;
    Attributes base_stats;
} ClassData;

// I don't think this is needed here
// ClassData class_list[];

typedef struct {
    char* name;
    int exp;
    int hp;
    int max_hp;
    Class class;
    Attributes attributes;
} Adventurer;

typedef struct {
    Adventurer* party_members;
    int party_size;
} Party;

typedef struct {
    Party party;
    int money;
    int location;
} Player;

#endif

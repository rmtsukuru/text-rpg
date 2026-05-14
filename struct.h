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

typedef enum {
    XLOW = 1,
    LOW = 3,
    AVG = 5,
    HIGH = 8,
    XHIGH = 10
} StatGrowthRate;

typedef struct {
    StatGrowthRate hp;
    StatGrowthRate str;
    StatGrowthRate dex;
    StatGrowthRate vit;
    StatGrowthRate spr;
    StatGrowthRate intel;
    StatGrowthRate awa;
    StatGrowthRate cha;
    StatGrowthRate lck;
} AttributeGrowthRates;

typedef struct {
    Class class;
    char* name;
    Attributes base_stats;
    AttributeGrowthRates stat_growth;
} ClassData;

// I don't think this is needed here
// ClassData class_list[];

typedef enum {
    SHE = 1,
    HE = 2,
    THEY = 3
} Pronoun;

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
    int party_size;
} Party;

typedef struct {
    Party party;
    int money;
    int location;
} Player;

#endif

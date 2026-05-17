#ifndef CLASS_TYPES_H
#define CLASS_TYPES_H

#include "player.h"

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
    int base_hp;
    Attributes base_stats;
    AttributeGrowthRates stat_growth;
} ClassData;

#endif


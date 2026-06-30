#include <stdio.h>
#include <stdlib.h>

#include "level.h"

const ushort PC_HP_MAX = 500;
const byte PC_STAT_MAX = 100;
const byte LEVEL_MAX = 100;

int level_table[] = {
    -10000,    // Level 0 (mostly unused)
    0,         // Level 1
    300, 
    900,
    2700,
    6500,      // Level 5
    14000,
    23000,
    34000,
    48000,
    64000,     // Level 10
    85000,
    100000,
    120000,
    140000,
    165000,    // Level 15
    195000,
    225000,
    265000,
    305000,
    355000,    // Level 20
    405000,
    455000,
    500000,
    550000,
    605000,    // Level 25
    655000,
    705000,
    760000,
    815000,
    870000,    // Level 30
    930000,
    1000000,
    1060000,
    1125000,
    1185000,   // Level 35
    1245000,
    1305000,
    1370000,
    1435000,
    1500000,   // Level 40
    1570000,
    1640000,
    1710000,
    1780000,
    1855000,   // Level 45
    1925000,
    2000000,
    2075000,
    2150000,
    2230000,   // Level 50
    2315000,
    2405000,
    2500000,
    2600000,
    2705000,   // Level 55
    2815000,
    2930000,
    3050000,
    3175000,
    3305000,   // Level 60
};

// TODO fill in remaining class skill ranks and fix stats
// (now that all EIGHTEEN classes have been added lol)
ClassData class_list[] = {
    {ROGUE, "Rogue", 10, {10, 25, 10, 8, 15, 13, 7, 13},
        {AVG, AVG, XHIGH, AVG, LOW, HIGH, HIGH, LOW, AVG},
        {2, (SkillRank[2]){{STEALTH, 60}, {FENCING, 50}}}
    },
    {NOMAD, "Nomad", 16, {20, 7, 18, 12, 4, 12, 14, 10},
        {XHIGH, HIGH, AVG, HIGH, AVG, LOW, AVG, AVG, AVG},
        {3, (SkillRank[3]){{BRAWL, 30}, {ARCHERY, 60}, {FENCING, 40}}}
    },
    {KNIGHT, "Knight", 16, {20, 7, 18, 12, 4, 12, 14, 10},
        {XHIGH, HIGH, AVG, HIGH, AVG, LOW, AVG, AVG, AVG},
        {2, (SkillRank[2]){{BRAWL, 60}, {FENCING, 30}}}
    },
    {SCOUT, "Scout", 14, {10, 25, 10, 8, 15, 13, 7, 13},
        {AVG, AVG, HIGH, AVG, AVG, HIGH, HIGH, LOW, AVG},
        {2, (SkillRank[2]){{STEALTH, 50}, {TRACKING, 60}}}
    },
    {MONK, "Monk", 12, {10, 20, 13, 15, 8, 16, 11, 5},
        {AVG, HIGH, HIGH, AVG, HIGH, LOW, XHIGH, AVG, XLOW},
        {3, (SkillRank[3]){{BRAWL, 50}, {FENCING, 30}, {FORTUNE, 20}}}
    },
    {BARD, "Bard", 10, {6, 10, 12, 24, 10, 15, 18, 20},
        {LOW, XLOW, AVG, AVG, XHIGH, LOW, AVG, AVG, HIGH},
        {2, (SkillRank[2]){{ATTUNEMENT, 40}, {PERFORMANCE, 50}}}
    },
    {WARLOCK, "Warlock", 8, {8, 15, 5, 16, 23, 17, 13, 12},
        {XLOW, LOW, HIGH, AVG, HIGH, XHIGH, HIGH, AVG, AVG},
        {2, (SkillRank[2]){{OCCULT, 45}, {SENSE, 20}}}
    },
    {ORACLE, "Oracle", 8, {8, 15, 5, 16, 23, 17, 13, 12},
        {XLOW, LOW, HIGH, AVG, HIGH, XHIGH, HIGH, AVG, AVG},
        {2, (SkillRank[2]){{OCCULT, 45}, {SENSE, 20}}}
    },
    {PRIESTESS, "Priestess", 10, {6, 10, 12, 24, 10, 15, 18, 20},
        {LOW, XLOW, AVG, AVG, XHIGH, LOW, AVG, AVG, HIGH},
        {2, (SkillRank[2]){{ATTUNEMENT, 40}, {INSIGHT, 30}}}
    },
    {WITCH, "Witch", 12, {8, 15, 5, 16, 23, 17, 13, 12},
        {LOW, LOW, HIGH, AVG, HIGH, XHIGH, HIGH, AVG, AVG},
        {2, (SkillRank[2]){{OCCULT, 45}, {SENSE, 20}}}
    },
    {SHAMAN, "Shaman", 10, {10, 15, 7, 16, 23, 17, 13, 12},
        {AVG, LOW, LOW, AVG, HIGH, XHIGH, HIGH, AVG, AVG},
        {2, (SkillRank[2]){{OCCULT, 45}, {SENSE, 20}}}
    },
    {SORCERER, "Sorcerer", 8, {8, 15, 5, 16, 23, 17, 13, 12},
        {XLOW, LOW, HIGH, AVG, HIGH, XHIGH, HIGH, AVG, AVG},
        {2, (SkillRank[2]){{OCCULT, 45}, {SENSE, 20}}}
    },
    {OCCULTIST, "Occultist", 8, {8, 15, 5, 16, 23, 17, 13, 12},
        {XLOW, LOW, HIGH, AVG, HIGH, XHIGH, HIGH, AVG, AVG},
        {2, (SkillRank[2]){{OCCULT, 60}, {SENSE, 20}}}
    },
    {ALCHEMIST, "Alchemist", 8, {8, 15, 5, 16, 23, 17, 13, 12},
        {XLOW, LOW, HIGH, AVG, HIGH, XHIGH, HIGH, AVG, AVG},
        {2, (SkillRank[2]){{OCCULT, 45}, {SENSE, 20}}}
    },
    {WIZARD, "Wizard", 8, {8, 15, 5, 16, 23, 17, 13, 12},
        {XLOW, LOW, HIGH, AVG, HIGH, XHIGH, HIGH, AVG, AVG},
        {2, (SkillRank[2]){{OCCULT, 45}, {SENSE, 20}}}
    },
    {SLAYER, "Slayer", 10, {10, 25, 10, 8, 15, 13, 7, 8},
        {AVG, AVG, HIGH, AVG, AVG, HIGH, HIGH, LOW, AVG},
        {2, (SkillRank[2]){{OCCULT, 30}, {TRACKING, 60}}}
    },
    {SURFACEWALKER, "Surfacewalker", 14, {10, 25, 10, 8, 15, 13, 7, 13},
        {AVG, AVG, HIGH, AVG, AVG, HIGH, HIGH, LOW, HIGH},
        {2, (SkillRank[2]){{ATTUNEMENT, 40}, {INSIGHT, 60}}}
    },
    {ACCURSED, "Accursed", 18, {10, 25, 10, 8, 15, 13, 7, 13},
        {AVG, HIGH, HIGH, AVG, AVG, HIGH, HIGH, AVG, XLOW},
        {2, (SkillRank[2]){{STEALTH, 50}, {TRACKING, 60}}}
    }
};

ClassData* getClassData(Class class) {
    int class_count = sizeof(class_list)/sizeof(ClassData);
    for (int i = 0; i < class_count; i++) {
        if (class_list[i].class == class) {
            return &class_list[i];
        }
    }
}

int getBaseHp(Class class) {
    ClassData* data = getClassData(class);
    return data->base_hp;
}

Attributes* getBaseAttributes(Class class) {
    ClassData* data = getClassData(class);
    return &data->base_stats;
}

byte getClassCount() {
    return sizeof(class_list) / sizeof(ClassData);
}

// TODO refactor this
char* getClassName(Adventurer* pc) {
    int class_count = getClassCount();
    for (int i = 0; i < class_count; i++) {
        if (class_list[i].class == pc->class) {
            return class_list[i].name;
        }
    }
}

void loadClassOptions(char** options, byte count) {
    for (int i = 0; i < count; i++) {
        options[i] = class_list[i].name;
    }
}

Skills* getClassSkills(Class class) {
    ClassData* data = getClassData(class);
    return &data->base_skills;
}

int getLevel(Adventurer* pc) {
    int level = 0;
    while (level_table[level + 1] <= pc->exp) {
        level++;
    }
    return level;
}

byte calculateSkillPoints(Adventurer* pc) {
    byte increase = 0;
    // Minimum int (and lck) bonus of 1 to prevent dividing by 0
    byte int_bonus = pc->attributes.intel / 5 + 1;
    byte lck_bonus = pc->attributes.lck / 5 + 1;
    increase = (rand() % int_bonus + rand() % lck_bonus) + 1;
    pc->skill_points += increase;
    return increase;
}

int calculateHpGrowth(Adventurer* pc, StatGrowthRate* growth_rate) {
    int increase = 0;
    int vit_bonus = pc->attributes.vit / 10;
    int max = *growth_rate;
    increase = (rand() % max) + 1 + vit_bonus;
    pc->max_hp += increase;
    pc->hp += increase;
    if (pc->max_hp > PC_HP_MAX) {
        pc->max_hp = PC_HP_MAX;
    }
    if (pc->hp > PC_HP_MAX) {
        pc->hp = PC_HP_MAX;
    }
    return increase;
}

byte calculateStatGrowth(byte* stat, StatGrowthRate* growth_rate) {
    byte increase = 0;
    // switch(*growth_rate) {
        // TODO add proper switch case logic here later
        // default:
            int threshold = (int) *growth_rate;
            int roll = rand() % (11);
            if (roll < threshold) {
                if (roll > 7) {
                    increase = 3;
                } else if (roll > 4) {
                    increase = 2;
                } else {
                    increase = 1;
                }
            }
    // }
    (*stat) += increase;

    if (*stat > PC_STAT_MAX) {
        *stat = PC_STAT_MAX;
    }
    return increase;
}

void levelUp(Adventurer* pc, byte currentLevel) {
    int newLevel = getLevel(pc);
    while (currentLevel < newLevel) {
        // Just get stat boosts for each level for now
        Attributes* stats = &pc->attributes;
        ClassData* class = getClassData(pc->class);
        AttributeGrowthRates* growth_rates = &class->stat_growth;
        calculateStatGrowth(&stats->str, &growth_rates->str);
        calculateStatGrowth(&stats->dex, &growth_rates->dex);
        calculateStatGrowth(&stats->vit, &growth_rates->vit);
        calculateStatGrowth(&stats->spr, &growth_rates->spr);
        calculateStatGrowth(&stats->intel, &growth_rates->intel);
        calculateStatGrowth(&stats->awa, &growth_rates->awa);
        calculateStatGrowth(&stats->cha, &growth_rates->cha);
        calculateStatGrowth(&stats->lck, &growth_rates->lck);
        calculateHpGrowth(pc, &growth_rates->hp);
        calculateSkillPoints(pc);
        currentLevel++;
    }
}

int getTotalExpForNextLevel(Adventurer* pc) {
    int level = getLevel(pc);
    return level_table[level + 1];
}

int getRemainingExpForNextLevel(Adventurer* pc) {
    int total = getTotalExpForNextLevel(pc);
    return total - pc->exp;
}

void printExpThresholds() {
    int length = sizeof(level_table)/sizeof(int);
    for (int i = 1; i < length - 1; i++) {
        int exp = level_table[i + 1] - level_table[i];
        printf("EXP to get from level %2d to level %2d: %7d\n", i, i + 1, exp);
    }
}


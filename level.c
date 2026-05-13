#include <stdio.h>

#include "level.h"

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
    500000     // Level 21 (currently unused)
};

ClassData class_list[] = {
    {MONK, "Monk", {10, 20, 13, 15, 8, 16, 11, 5}},
    {ROGUE, "Rogue", {10, 25, 10, 8, 15, 13, 7, 13}},
    {FIGHTER, "Fighter", {20, 7, 18, 12, 4, 12, 14, 10}},
    {PRIESTESS, "Priestess", {6, 10, 12, 24, 10, 15, 18, 20}},
    {MAGE, "Mage", {8, 15, 5, 16, 23, 17, 13, 12}}
};

ClassData* getClassData(Class class) {
    int class_count = sizeof(class_list)/sizeof(ClassData);
    for (int i = 0; i < class_count; i++) {
        if (class_list[i].class == class) {
            return &class_list[i];
        }
    }
}

Attributes* getBaseAttributes(Class class) {
    ClassData* data = getClassData(class);
    return &data->base_stats;
}

int getLevel(Adventurer* pc) {
    int level = 0;
    while (level_table[level + 1] < pc->exp) {
        level++;
    }
    return level;
}

void levelUp(Adventurer* pc, int currentLevel) {
    int newLevel = getLevel(pc);
    while (currentLevel < newLevel) {
        // Just get stat boosts for each level for now
        // TODO finish this
    }
}

int getTotalExpForNextLevel(Adventurer* pc) {
    int level = getLevel(pc);
    return level_table[level + 1];
}

int getRemaingExpForNextLevel(Adventurer* pc) {
    int total = getTotalExpForNextLevel(pc);
    return total - pc->exp;
}

void printExpThresholds() {
    int length = sizeof(level_table)/sizeof(int);
    for (int i = 1; i < length - 1; i++) {
        int exp = level_table[i + 1] - level_table[i];
        printf("EXP to get from level %d to level %d: %d\n", i, i + 1, exp);
    }
}


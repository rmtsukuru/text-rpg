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

int getLevel(Adventurer* pc) {
    int level = 0;
    while (level_table[level + 1] < pc->exp) {
        level++;
    }
    return level;
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


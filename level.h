#ifndef LEVEL_H
#define LEVEL_H

#include "struct.h"

int getLevel(Adventurer* pc);

int getTotalExpForNextLevel(Adventurer* pc);

int getRemaingExpForNextLevel(Adventurer* pc);

void printExpThresholds();

#endif

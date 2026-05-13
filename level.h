#ifndef LEVEL_H
#define LEVEL_H

#include "struct.h"

extern ClassData class_list[5];

Attributes* getBaseAttributes(Class class);

int getLevel(Adventurer* pc);

void levelUp(Adventurer* pc, int currentLevel);

int getTotalExpForNextLevel(Adventurer* pc);

int getRemaingExpForNextLevel(Adventurer* pc);

void printExpThresholds();

#endif

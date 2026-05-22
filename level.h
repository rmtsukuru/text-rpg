#ifndef LEVEL_H
#define LEVEL_H

#include "types.h"
#include "player.h"

extern ClassData class_list[5];

int getBaseHp(Class class);

Attributes* getBaseAttributes(Class class);

int getLevel(Adventurer* pc);

void levelUp(Adventurer* pc, byte currentLevel);

int getTotalExpForNextLevel(Adventurer* pc);

int getRemainingExpForNextLevel(Adventurer* pc);

void printExpThresholds();

#endif


#ifndef LEVEL_H
#define LEVEL_H

#include "types.h"
#include "player.h"
#include "skill.h"

int getBaseHp(Class class);

Attributes* getBaseAttributes(Class class);

byte getClassCount();

char* getClassName(Adventurer* pc);

void loadClassOptions(char** options, byte count);

Skills* getClassSkills(Class class);

int getLevel(Adventurer* pc);

void levelUp(Adventurer* pc, byte currentLevel);

int getTotalExpForNextLevel(Adventurer* pc);

int getRemainingExpForNextLevel(Adventurer* pc);

void printExpThresholds();

#endif


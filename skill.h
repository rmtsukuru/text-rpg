#ifndef SKILL_H
#define SKILL_H

#include "types.h"

Skills* getBaseSkills(Background background);

void combineBaseSkills(Skills* skills, Skills* class_skills, Skills* bg_skills);

BackgroundData* getBackgroundData(Background background);

byte getBackgroundCount();

void loadBackgroundOptions(char** options, byte count);

void cleanupBackgroundOptions(char** options);

SkillData* getSkillData(Skill skill);

#endif


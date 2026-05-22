
#include "skill.h"

// Make sure these are in proper enum order so array indices work.
SkillData skills[] = {
    {BRAWL, STR, "Brawl", 20},
    {GRAPPLING, STR, "Grappling", 10},
    {FENCING, STR, "Fencing", 5},
    {ARCHERY, DEX, "Archery", 0},
    {ACROBATICS, DEX, "Acrobatics", 10},
    {STEALTH, DEX, "Stealth", 20},
    {LOCKPICKING, DEX, "Lockpicking", 0}
    // TODO fill in the rest of these
};

// Make sure these are in proper enum order so array indices work.
// (The skill ranks can be in any order though, they're fine as is).
BackgroundData backgrounds[] = {
    {SOLDIER, "Soldier",
        {1, (SkillRank[1]){{BRAWL, 60}}}
    },
    {NOBLE, "Noble",
        {2, (SkillRank[2]){{FENCING, 40}, {STEALTH, 30}}}
    },
    // TODO fill in the rest of these too
};

SkillData* getSkillData(Skill skill) {
    byte index = (byte) skill;
    return &skills[index];
}

BackgroundData* getBackgroundData(Background background) {
    byte index = (byte) background;
    return &backgrounds[index];
}

Skills* getBaseSkills(Background background) {
    BackgroundData* data = getBackgroundData(background);
    return &data->base_skills;
}


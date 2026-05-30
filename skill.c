#include <stdlib.h>

#include "skill.h"

// Make sure these are in proper enum order so array indices work.
SkillData skills[] = {
    {BRAWL, STR, "Brawl", 20},                      // STR
    {AXES, STR, "Axes", 5},
    {POLEARMS, STR, "Polearms", 0},
    {GREATSWORDS, STR, "Greatswords", 0},
    {ARMOR, STR, "Light Armor", 10},
    {HEAVY_ARMOR, STR, "Heavy Armor", 0},
    {GRAPPLING, STR, "Grappling", 10},
    {SWIMMING, STR, "Swimming", 5},
    {FENCING, STR, "Fencing", 5},
    {ARCHERY, DEX, "Archery", 0},                   // DEX
    {ACROBATICS, DEX, "Acrobatics", 10},
    {STEALTH, DEX, "Stealth", 20},
    {LOCKPICKING, DEX, "Lockpicking", 0},
    {SLEIGHT_OF_HAND, DEX, "Sleight of Hand", 5},
    {CRAFTS, DEX, "Crafts", 10},
    {WELLNESS, VIT, "Wellness", 20},                // VIT
    {ENDURANCE, VIT, "Endurance", 10},
    {BEAUTY, VIT, "Beauty", 5},
    {INSIGHT, SPR, "Insight", 15},                  // SPR
    {ATTUNEMENT, SPR, "Attunement", 1},
    {MEDICINE, SPR, "Medicine", 0},
    {WILL, SPR, "Will", 15},
    {ARTS, SPR, "Arts", 10},
    {EDUCATION, INT, "Education", 0},               // INT
    {HISTORY, INT, "History", 5},
    {OCCULT, INT, "Occult", 0},
    {NATURE, INT, "Nature", 10},
    {INVESTIGATION, INT, "Investigation", 10},
    {SENSE, AWA, "Sense", 20},                      // AWA
    {TRACKING, AWA, "Tracking", 0},
    {NAVIGATION, AWA, "Navigation", 10},
    {CHARM, CHA, "Charm", 0},                       // CHA
    {PERSUASION, CHA, "Persuasion", 15},
    {DECEPTION, CHA, "Deception", 10},
    {PERFORMANCE, CHA, "Performance", 0},
    {FATE, LCK, "Fate", 0},                         // LCK
    {FORTUNE, LCK, "Fortune", 0},
    {GAMBLING, LCK, "Gambling", 10}
};

// Make sure these are in proper enum order so array indices work.
// (The skill ranks can be in any order though, they're fine as is).
BackgroundData backgrounds[] = {
    {SOLDIER, "Soldier",
        {2, (SkillRank[2]){{BRAWL, 60}, {ARCHERY, 40}}}
    },
    {NOBLE, "Noble",
        {2, (SkillRank[2]){{FENCING, 40}, {STEALTH, 30}}}
    },
    {SCHOLAR, "Scholar",
        {1, (SkillRank[1]){{EDUCATION, 60}}}
    },
    {URCHIN, "Urchin",
        {2, (SkillRank[2]){{STEALTH, 50}, {BRAWL, 60}}}
    },
    {MERCHANT, "Merchant",
        {2, (SkillRank[2]){{EDUCATION, 40}, {PERSUASION, 50}}}
    }
};

SkillData* getSkillData(Skill skill) {
    byte index = (byte) skill;
    return &skills[index];
}

BackgroundData* getBackgroundData(Background background) {
    byte index = (byte) background;
    return &backgrounds[index];
}

byte getBackgroundCount() {
    return sizeof(backgrounds) / sizeof(BackgroundData);
}

char** getBackgroundOptions() {
    byte max_name_length = 30;
    byte background_count = getBackgroundCount();
    int block_size = sizeof(char) * max_name_length * background_count;
    char** background_options = malloc(sizeof(char*) * background_count);
    for (int i = 0; i < background_count; i++) {
        background_options[i] = malloc(sizeof(char) * max_name_length);
        background_options[i] = backgrounds[i].name;
    }
    return background_options;
}

void cleanupBackgroundOptions(char** options) {
    byte background_count = getBackgroundCount();
    for (int i = 0; i < background_count; i++) {
        free(options[i]);
    }
    free(options);
}

Skills* getBaseSkills(Background background) {
    BackgroundData* data = getBackgroundData(background);
    return &data->base_skills;
}


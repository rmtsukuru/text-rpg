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

void loadBackgroundOptions(char** options, byte count) {
    for (int i = 0; i < count; i++) {
        options[i] = backgrounds[i].name;
    }
}

Skills* getBaseSkills(Background background) {
    BackgroundData* data = getBackgroundData(background);
    return &data->base_skills;
}

void combineBaseSkills(Skills* skills, Skills* class_skills, Skills* bg_skills) {
    byte length = class_skills->length;
    byte bg_length = bg_skills->length;
    byte total_length = length + bg_length;
    for (int i = 0; i < length; i++) {
        skills->ranks[i].id = class_skills->ranks[i].id;
        skills->ranks[i].rank = class_skills->ranks[i].rank;
    }
    byte total_counter = length;
    for (int i = 0; i < bg_length; i++) {
        byte skip = 0;
        for (int j = 0; j < length; j++) {
            // If class and background both provide ranks in the same skill,
            // use the higher of the two.
            if (skills->ranks[j].id == bg_skills->ranks[i].id) {
                skip = 1;
                total_length--;
                if (bg_skills->ranks[i].rank > skills->ranks[j].rank) {
                    skills->ranks[j].rank = bg_skills->ranks[i].rank;
                }
            }
        }
        if (!skip) {
            skills->ranks[total_counter].id = bg_skills->ranks[i].id;
            skills->ranks[total_counter].rank = bg_skills->ranks[i].rank;
            total_counter++;
        }
    }
    skills->length = total_length;
}


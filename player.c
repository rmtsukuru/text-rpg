#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "skill.h"
#include "player.h"

char* getStringFromPronoun(Pronoun pronoun) {
    switch (pronoun) {
        case SHE:
            return "she/her";

        case HE:
            return "he/him";

        case THEY:
            return "they/them";
    }
}

Pronoun parsePronounString(char* pronoun_string) {
    if (strcmp(pronoun_string, "she/her") == 0) {
        return SHE;
    }
    if (strcmp(pronoun_string, "he/him") == 0) {
        return HE;
    }
    if (strcmp(pronoun_string, "they/them") == 0) {
        return THEY;
    }
}

void createNewAdventurer(Party* party) {
    char* name = malloc(sizeof(char) * MAX_NAME_LENGTH);
    int exp = 500;
    printf("\nWhat's the name of your character? ");
    scanf("%s", name);
    Pronoun pronoun_list[] = {SHE, HE, THEY};
    const byte pronoun_count = 3;
    char* pronoun_choices[pronoun_count];
    for (byte i = 0; i < pronoun_count; i++) {
        pronoun_choices[i] = getStringFromPronoun(pronoun_list[i]);
    }
    byte selection = listMenuPrompt("And what are your character's pronouns?", pronoun_choices, pronoun_count);
    Pronoun pronoun = pronoun_list[selection];

    Class class;
    int class_count = sizeof(class_list)/sizeof(ClassData);
    char* class_options[class_count];
    for (int i = 0; i < class_count; i++) {
        class_options[i] = class_list[i].name;
    }
    byte class_index = listMenuPrompt("What class is this character? Options include:", class_options, class_count);
    class = class_list[class_index].class;

    printf("How many experience points (EXP) does this character have? ");
    scanf("%d", &exp);

    Background bg;
    byte background_count = getBackgroundCount();
    char** background_options = getBackgroundOptions();
    byte background_index = listMenuPrompt("What is this character's background?", background_options, background_count);
    bg = (Background) background_index;
    cleanupBackgroundOptions(background_options);

    Skills* base_skills = getClassSkills(class);
    byte length = base_skills->length;
    Skills* bg_base_skills = getBaseSkills(bg);
    byte bg_length = bg_base_skills->length;
    byte total_length = length + bg_length;

    Skills* skills = &(Skills){total_length, malloc(sizeof(SkillRank) * total_length)};
    for (int i = 0; i < length; i++) {
        skills->ranks[i].id = base_skills->ranks[i].id;
        skills->ranks[i].rank = base_skills->ranks[i].rank;
    }
    byte total_counter = length;
    for (int i = 0; i < bg_length; i++) {
        byte skip = 0;
        for (int j = 0; j < length; j++) {
            // If class and background both provide ranks in the same skill,
            // use the higher of the two.
            if (skills->ranks[j].id == bg_base_skills->ranks[i].id) {
                skip = 1;
                total_length--;
                if (bg_base_skills->ranks[i].rank > skills->ranks[j].rank) {
                    skills->ranks[j].rank = bg_base_skills->ranks[i].rank;
                }
            }
        }
        if (!skip) {
            skills->ranks[total_counter].id = bg_base_skills->ranks[i].id;
            skills->ranks[total_counter].rank = bg_base_skills->ranks[i].rank;
            total_counter++;
        }
    }
    skills->length = total_length;

    int max_hp = getBaseHp(class);
    Attributes* stats = getBaseAttributes(class);
    Adventurer hero = {name, pronoun, exp, max_hp, max_hp, *stats, class, bg, *skills};
    levelUp(&hero, 1);

    party->party_members[party->size] = hero;
    party->size++;
}

void createParty(Party* party) {
    printf("Okay, let's get you started!\n");
    createNewAdventurer(party);

    int add_more_pcs = 1;

    while (party->size < MAX_PARTY_SIZE && add_more_pcs) {
        printf("Add another character (Y/n)? ");
        char response;
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y') {
            createNewAdventurer(party);
        } else {
            add_more_pcs = 0;
        }
    }
    printf("\n");
}

Player createInitialPlayer(int starting_money, int starting_location) {
    Adventurer* party_members = malloc(sizeof(Adventurer) * MAX_PARTY_SIZE);
    Party party = {party_members, 0};
    createParty(&party);
    Player player = {party, starting_money, starting_location};
    return player;
}

void cleanupPlayerData(Player* player) {
    for (int i = 0; i < player->party.size; i++) {
        Adventurer pc = player->party.party_members[i];
        free(pc.name);
        free(pc.skills.ranks);
    }
    free(player->party.party_members);
    player->party.party_members = NULL;
}

char* getClass(Adventurer* pc) {
    int class_count = sizeof(class_list)/sizeof(ClassData);
    for (int i = 0; i < class_count; i++) {
        if (class_list[i].class == pc->class) {
            return class_list[i].name;
        }
    }
}


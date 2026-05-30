#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Pronoun pronoun;
    printf("\nWhat's the name of your character? ");
    scanf("%s", name);
    printf("\nAnd what are your character's pronouns?\n");
    Pronoun pronoun_list[] = {SHE, HE, THEY};
    int pronoun_count = 3;
    for (int i = 0; i < pronoun_count; i++) {
        printf("%s - %d\n", getStringFromPronoun(pronoun_list[i]), (int) pronoun_list[i]);
    }
    printf("Make your choice (enter corresponding number): ");
    scanf("%d", &pronoun);
    printf("\n");

    Class class;
    int class_index;
    printf("\nWhat class is this character? Options include:\n");
    int class_count = sizeof(class_list)/sizeof(ClassData);
    for (int i = 0; i < class_count; i++) {
        printf("%s - %d\n", class_list[i].name, i + 1);
    }
    printf("Make your choice: ");
    scanf("%d", &class_index);
    class = class_list[class_index - 1].class;
    printf("\n");

    printf("How many experience points (EXP) does this character have? ");
    scanf("%d", &exp);
    printf("\n");

    int max_hp = getBaseHp(class);
    Attributes* stats = getBaseAttributes(class);
    Background bg = NOBLE; // TODO fix this later, actually ask for background
    if (class == FIGHTER) {
        bg = SOLDIER;
    }
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
    Adventurer hero = {name, pronoun, exp, max_hp, max_hp, *stats, class, bg, *skills};
    levelUp(&hero, 1);

    party->party_members[party->size] = hero;
    party->size++;
}

void createParty(Party* party) {
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
    printf("Okay, let's get you started!\n");
    createNewAdventurer(&party);
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


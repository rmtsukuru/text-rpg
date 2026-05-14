#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#include "level.h"

#define DEBUG
#define MAX_NAME_LENGTH 50
#define MAX_PARTY_SIZE 4

char* locations[] = {
    "Whispering Fields",
    "Cave"
};

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

Player createInitialPlayer(char* name, Pronoun pronoun, Class class, int exp, int max_hp, int starting_money, int starting_location) {
    Attributes* stats = getBaseAttributes(class);
    Adventurer hero = {name, pronoun, exp, max_hp, max_hp, class, *stats};
    Adventurer* party_members = malloc(sizeof(Adventurer) * MAX_PARTY_SIZE);
    levelUp(&hero, 1);
    *party_members = hero;
    Party party = {party_members, 1};
    Player player = {party, starting_money, starting_location};
    return player;
}

void cleanupPlayerData(Player* player) {
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

void printStats(Adventurer* pc) {
    char* pronoun = getStringFromPronoun(pc->pronoun);
    printf("%s (%s)  Level %d %s\nHP %d/%d\n", pc->name, pronoun, getLevel(pc), getClass(pc), pc->hp, pc->max_hp);
    printf("Strength:     %2d   Dexterity: %2d   Vitality: %2d   Spirit: %2d\n", pc->attributes.str, pc->attributes.dex, pc->attributes.vit, pc->attributes.spr);
    printf("Intelligence: %2d   Awareness: %2d   Charisma: %2d   Luck:   %2d\n", pc->attributes.intel, pc->attributes.awa, pc->attributes.cha, pc->attributes.lck);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    #ifdef DEBUG
        if (argc > 1 && strcmp(argv[1], "--debug") == 0) {
            printf("\n");
            printExpThresholds();
            return 0;
        }
    #endif

    char name[MAX_NAME_LENGTH];
    int exp = 500, max_hp = 12, money = 300, location = 0;
    Pronoun pronoun;
    printf("Okay, let's get you started!\n");
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
    printf("\n\n");

    Player player = createInitialPlayer(name, pronoun, class, exp, max_hp, money, location);

    printf("Current Location: %s\n", locations[player.location]);
    printf("Current Money: $%d\n", player.money);
    Adventurer hero = player.party.party_members[0];
    printf("Party:\n");
    printStats(&hero);

    cleanupPlayerData(&player);
}


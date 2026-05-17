#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "player.h"
#include "level.h"

#define DEBUG

char* locations[] = {
    "Whispering Fields",
    "Cave"
};

void printStats(Adventurer* pc) {
    char* pronoun = getStringFromPronoun(pc->pronoun);
    printf("%s (%s)  Level %d %s\nHP %d/%d\n", pc->name, pronoun, getLevel(pc), getClass(pc), pc->hp, pc->max_hp);
    printf("Strength:     %2d   Dexterity: %2d   Vitality: %2d   Spirit: %2d\n", pc->attributes.str, pc->attributes.dex, pc->attributes.vit, pc->attributes.spr);
    printf("Intelligence: %2d   Awareness: %2d   Charisma: %2d   Luck:   %2d\n", pc->attributes.intel, pc->attributes.awa, pc->attributes.cha, pc->attributes.lck);
}

void printPlayerInfo(Player* player) {
    printf("Current Location: %s\n", locations[player->location]);
    printf("Current Money: $%d\n", player->money);
    printf("Party:\n");
    for (int i = 0; i < player->party.size; i++) {
        printStats(&player->party.party_members[i]);
        if (i < player->party.size - 1) {
            printf("\n");
        }
    }
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

    int money = 300, location = 0;

    Player player = createInitialPlayer(money, location);
    createParty(&player.party);

    printPlayerInfo(&player);
    cleanupPlayerData(&player);
}


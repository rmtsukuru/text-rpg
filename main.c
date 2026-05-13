#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "level.h"

// #define DEBUG
#define MAX_NAME_LENGTH 50
#define MAX_PARTY_SIZE 4

char *locations[] = {
    "Whispering Fields",
    "Cave"
};

Player createInitialPlayer(char* name, char* class, int exp, int max_hp, int starting_money, int starting_location) {
    Adventurer hero = {name, exp, max_hp, max_hp, class};
    Adventurer* party_members = malloc(sizeof(Adventurer) * MAX_PARTY_SIZE);
    *party_members = hero;
    Party party = {party_members, 1};
    Player player = {party, starting_money, starting_location};
    return player;
}

void cleanupPlayerData(Player* player) {
    free(player->party.party_members);
    player->party.party_members = NULL;
}

int main() {
    char name[MAX_NAME_LENGTH];
    char class[MAX_NAME_LENGTH];
    int exp = 500, max_hp = 12, money = 300, location = 0;
    printf("Okay, let's get you started!\n");
    printf("\nWhat's the name of your character? ");
    scanf("%s", name);
    printf("\nWhat class is this character? ");
    scanf("%s", class);
    printf("\n");
    Player player = createInitialPlayer(name, class, exp, max_hp, money, location);

    printf("Current Location: %s\n", locations[player.location]);
    printf("Current Money: $%d\n", player.money);
    Adventurer hero = player.party.party_members[0];
    printf("Party:\n%s   Level %d %s\nHP %d/%d\n", hero.name, getLevel(&hero), hero.class, hero.hp, hero.max_hp);

    cleanupPlayerData(&player);

#ifdef DEBUG
    printf("\n");
    printExpThresholds();
#endif
}


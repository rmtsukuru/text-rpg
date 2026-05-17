#ifndef PLAYER_H
#define PLAYER_H

#include "struct/player.h"
#include "level.h"

#define MAX_NAME_LENGTH 50
#define MAX_PARTY_SIZE 4

char* getStringFromPronoun(Pronoun pronoun);

Pronoun parsePronounString(char* pronoun_string);

void createNewAdventurer(Party* party);

void createParty(Party* party);

Player createInitialPlayer(int starting_money, int starting_location);

void cleanupPlayerData(Player* player);

char* getClass(Adventurer* pc);

#endif


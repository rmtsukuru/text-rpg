#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "config/options.h"

char* getStringFromPronoun(Pronoun pronoun);

Pronoun parsePronounString(char* pronoun_string);

void createNewAdventurer(Party* party);

void createParty(Party* party);

Player createInitialPlayer(int starting_money, int starting_location);

void cleanupPlayerData(Player* player);

#endif


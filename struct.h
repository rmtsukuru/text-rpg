#ifndef STRUCT_H
#define STRUCT_H

typedef struct {
    char* name;
    int exp;
    int hp;
    int max_hp;
    char* class;
} Adventurer;

typedef struct {
    Adventurer* party_members;
    int party_size;
} Party;

typedef struct {
    Party party;
    int money;
    int location;
} Player;

#endif

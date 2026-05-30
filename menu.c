#include <stdio.h>

#include "menu.h"

// Returns the index of the option selected by the user
// (not the actual number typed into user input).
byte listMenuPrompt(char* prompt, char** choices, byte length) {
    byte result;
    printf("\n%s\n", prompt);
    Pronoun pronoun_list[] = {SHE, HE, THEY};
    int pronoun_count = 3;
    for (int i = 0; i < length; i++) {
        printf("%s - %d\n", choices[i], i + 1);
    }
    printf("Make your choice (enter corresponding number): ");
    scanf("%d", &result);
    return result - 1;
}


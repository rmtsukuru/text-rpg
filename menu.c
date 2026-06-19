#include <stdio.h>

#include "menu.h"

// Returns the index of the option selected by the user
// (not the actual number typed into user input).
byte listMenuPrompt(char* prompt, char** choices, byte length) {
    byte result;
    printf("\n%s\n", prompt);
    for (int i = 0; i < length; i++) {
        printf("%s - %d\n", choices[i], i + 1);
    }
    printf("Make your choice (enter corresponding number): ");
    scanf("%d", &result);
    return result - 1;
}

// Returns 1 (true) for yes, 0 (false) for no
byte yesNoPrompt(char* prompt, byte default_return) {
    char result;
    if (default_return) {
        printf("\n%s (Y/n) ", prompt);
    } else {
        printf("\n%s (y/N) ", prompt);
    }
    scanf(" %c", &result);
    if (result == '1' || result == 'Y' || result == 'y') {
        return 1;
    }
    if (result == '2' || result == 'N' || result == 'n') {
        return 0;
    }
    return default_return;
}


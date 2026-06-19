#ifndef MENU_H
#define MENU_H

#include "types.h"

byte listMenuPrompt(char* prompt, char** choices, byte length);

byte yesNoPrompt(char* prompt, byte default_return);

#endif

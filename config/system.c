#include "system.h"

#if defined(_WIN32) || defined(WIN32)
#include <windows.h>
#define CONFIG_WINDOWS 1
#endif

void configureTextEncoding() {
    if (CONFIG_WINDOWS) {
        SetConsoleOutputCP(CP_UTF8);
    }
    // Otherwise do nothing, UTF-8 should be default on Mac/UNIX.
}

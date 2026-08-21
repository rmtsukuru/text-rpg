#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#include "../types.h"
#include "../functions.h"
#include "options.h"

byte parseCliArgs(int argc, char** argv) {
    char ch = 0;
    struct option long_opts[] = {
        {"debug", no_argument, NULL, 'd'}
    };
    while (ch != -1) {
        ch = getopt_long(argc, argv, "d", long_opts, NULL);

        if (ch == 'd') {
            printf("\n");
            #ifdef DEBUG
            printExpThresholds();
            return 1;
            #endif
        }
    }

    return 0;
}


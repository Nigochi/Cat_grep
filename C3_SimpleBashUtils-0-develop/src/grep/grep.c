#include <stdio.h>
#include "grep_no_args.h"
#include "grep_args.h"

int main (int argc, char *argv[]) {
    if (argc == 3) {
        grep_no_args(argv);
    }
    else {
        if (!grep_args(argv)) {
            return 1;
        }
    }
    return 0;
}

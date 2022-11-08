#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "cat_no_args.h"
#include "cat_info.h"
#include "cat_args.h"

int main(int argc, char *argv[]) {
    (void)argv;
    if (argc == 1) {
        cat_no_args(STDERR_FILENO);
    }
    else {
        if (!cat_args(argc, argv))
            return 1;
    }
    return 0;
}

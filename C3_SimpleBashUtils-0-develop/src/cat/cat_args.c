#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "cat_info.h"
#include "cat_parse_arg.h"

bool cat_args(int argc, char *argv[]) {
    cat_info info = {0, 0, 0, 0, 0};
    for(int i = 1;  i != argc; i++) {
        if (*argv[i] == '-') {
            if (!cat_parse_arg(&info, argv[i])) {
                return false;
            }
            else {
                cat_distibution(&info, argv);
            }
        }
    }
    return true;
}
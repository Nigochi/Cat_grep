#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void cat_no_args(int fb) {
    char array[4096];
    int for_read = read(fb, array, 4096);
    while (for_read > 0) {
        printf("%.*s", for_read, array);
        for_read = read(fb, array, 4096);
    }
}
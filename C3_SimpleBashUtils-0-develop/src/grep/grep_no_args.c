#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void grep_no_args (char *argv[]) {
    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("s21_grep: %s: No such file or directory", argv[2]);
        exit(0);
    }
    char *output = malloc(sizeof(char));
    do {
        if (fgets(output, strlen(argv[1])+1, file) != NULL) {
            if (strcmp(argv[1], output) == 0) {
                printf(output);
                if (!feof(file)) {
                    printf("\n");
            }
            }
        } 
    } while (!feof(file));
    free(output);
}
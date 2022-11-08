#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "cat_flags.h"

void just_cat (char *argv) {
    FILE *file = fopen(argv, "r");
    char *output = malloc(sizeof(char));
    while (!feof(file)) {
        if (fgets(output, 4096, file) != NULL) {
            printf("%s", output);
        }
    }
    free(output);
}

void cat_number_empty(FILE *file) {
    char *output = malloc(sizeof(char));
    int i = 0;
    while (!feof(file)) {
        if (fgets(output, 4069, file) != NULL) {
            if (output[0] != '\n') {
                printf("     %d  %s", i+1, output);
                i++;
            }
            else
                printf("\n");
        }
    }
    free(output);
}

void cat_show_endl(FILE *file) {
    char *output = malloc(sizeof(char));
    do {
        int i = 0;
        if (fgets(output, 4069, file) != NULL) {
            while (output[i] != '\n' && !feof(file)) {
                printf("%c", output[i]);
                i++;
            }
            if (!feof(file)){
                printf("$\n");
            }
            else {
                printf("%s", output);
            }
        }
    } while (!feof(file));
    free(output);
}

void cat_number_all(FILE *file) {
    char *output = malloc(sizeof(char));
    int i = 0;
    while (!feof(file)) {
        if (fgets(output, 4069, file) != NULL) {
            printf("     %d  %s", i+1, output);
            i++;
        }
    }
    free(output);
}

void cat_squeeze(FILE *file){
    char *output = malloc(sizeof(char));
    int flag = 0;
    while (!feof(file)) {
        if (fgets(output, 4069, file) != NULL) {
            if (output[0] != '\n') {
                printf("%s", output);
                flag = 0;
            }
            else if (flag < 1){
                printf("%s", output);
                flag ++;
            }
        }
    }
}

void cat_show_tabs(FILE *file) {
    char *output = malloc(sizeof(char));
    do {
        int i = 0;
        if (fgets(output, 4069, file) != NULL) {
            if (!feof(file)) {
            while (output[i] != '\n') {
                if (output[i] == '	') {
                    output[i] = 'I';
                    printf("^");
                }
                printf("%c", output[i]);
                i++;
            }
                printf("\n");
            }
            else {
                while (output[i] != '\0') {
                    if (output[i] == '	') {
                        output[i] = 'I';
                        printf("^");
                }
                printf("%c", output[i]);
                i++;
            }
            }
        }
    } while (!feof(file));
    free(output);
}


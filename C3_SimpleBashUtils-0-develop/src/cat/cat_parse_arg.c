#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "cat_info.h"
#include "cat_flags.h"

bool cat_parse_arg(cat_info *info, char *argv) {
    if (*argv == '-') {
        argv++;
        if (strcmp(argv, "number-nonblank") == 0) {
            info->number_empty = true;
        }
        else if (strcmp(argv, "number") == 0) {
            info->number_all = true;
        }
        else if (strcmp(argv, "squeeze-blank") == 0) {
            info->squeeze = true;
        }
        else if (strcmp(argv, "E") == 0) {
            info->show_endl = true;
        }
        else if (strcmp(argv, "T") == 0) {
            info->show_tabs = true;
        }    
    switch (*argv) {
        case 'b':
            info->number_empty = true; break;
        case 'e':
            info->show_endl = true; break;
        case 'n':
            info->number_all = true; break;
        case 's':
            info->squeeze = true; break;
        case 't':
            info->show_tabs = true; break;
        default:
            break;
    }
    if ((info->number_all + info->number_empty + info->show_endl +
         info->show_tabs + info->squeeze) != 1) {
            printf("s21_cat: illegal option -- %s", argv);
            exit(0);
        }
    if (*argv++ != ' ') {
        printf("\n%s\n", argv++);
        printf("\n%s\n", argv);
        cat_parse_arg(info, argv);
    }
    printf("%d %d %d %d %d\n", info->number_all, info->number_empty,
            info->show_endl, info->show_tabs, info->squeeze);
    }
    printf("\n%s\n", argv);
    return true;
}

void cat_distibution (cat_info *info, char *argv[]) {
    FILE *file = fopen(argv[2], "r");
    if (!file) {
         printf("s21_cat: %s: No such file or directory", argv[2]);
         exit(0);
    }
    if (info->number_empty == 1) {
        cat_number_empty(file);
    }
    else if (info->show_endl == 1) {
        cat_show_endl(file);
    }
    else if (info->number_all == 1) {
        cat_number_all(file);
    }
    else if (info->squeeze == 1) {
        cat_squeeze(file);
    }
    else if (info->show_tabs == 1) {
        cat_show_tabs(file);
    }
    fclose(file);
}

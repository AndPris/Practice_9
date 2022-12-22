//
// Created by andpr on 21.12.2022.
//
#pragma once
#ifndef PRACTICE_9_MYFUNCS_H
#define PRACTICE_9_MYFUNCS_H

#endif //PRACTICE_9_MYFUNCS_H

#include <stdio.h>

void noCharShort(short *var) { //checking for characters
    char cond, ch;
    do {
        cond = 0;
        scanf("%hd%c", var, &ch);

        if(ch != '\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
        }
    } while(cond);

}

short choose(short *var, short low, short top) {
    char cond;
    do {
        cond = 0;
        noCharShort(var);

        if (*var < low || *var > top) {
            printf("You have to enter a number from %hd to %hd\n", low, top);
            fflush(stdin);
            cond = 1;
        }
    } while(cond);
}
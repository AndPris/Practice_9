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

void floatInput(float *var) { //checking for characters and >0
    char cond, ch;
    do {
        cond = 0;
        scanf("%f%c", var, &ch);

        if(ch != '\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
        } else if(*var <= 0) {
            printf("This value must be higher than 0\n");
            cond = 1;
            fflush(stdin);
        } else if (*var > 1e10) {
            printf("This value must be lower than 1e10\n");
            cond = 1;
            fflush(stdin);
        }

    } while(cond);

}

void intInput(int *var) { //checking for characters and >0
    char cond, ch;
    do {
        cond = 0;
        scanf("%d%c", var, &ch);

        if(ch != '\n') {
            printf("Invalid data\n");
            cond = 1;
            fflush(stdin);
        } else if(*var <= 0) {
            printf("This value must be higher than 0\n");
            cond = 1;
            fflush(stdin);
        } else if (*var > 1e8) {
            printf("This value must be lower than 1e8\n");
            cond = 1;
            fflush(stdin);
        }

    } while(cond);

}
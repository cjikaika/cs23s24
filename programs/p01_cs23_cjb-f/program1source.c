// program1source.c
// C Source File
// CS23 Spring 2024 Assignment 1
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"program1header.h"


int maxSize(void) {
    int maxSize = ASIZE > BSIZE ? ASIZE : BSIZE;
    return maxSize;
};

void fillPrintRand(int randSets[][NUMSETS]) {

    int SIZE[] = {ASIZE, BSIZE};
    char setLet = 'A';
    srand(time(NULL));
    
    for (int i = 0; i < NUMSETS; i ++) {
        for (int j = 0; j < SIZE[i]; j++) {
            randSets[j][i] = rand()%10 + 1;
            printf("%2d  ",randSets[j][i]);
        }
        printf("\n");
        setLet++;
    }
}

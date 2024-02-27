// program1source.c
// C Source File
// CS23 Spring 2024 Assignment 1
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include<stdio.h>
#include<stdlib.h>
#include<program1header.h>


int maxSize(void) {
    int maxSize = ASIZE > BSIZE ? ASIZE : BSIZE;
    return maxSize;
};

int fillPrintRand(int randSets[]) {

    int SIZE[] = {ASIZE, BSIZE};
    srand(time(NULL));
    
    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < SIZE[i]; j++) {
            randSets[i][&j] = rand()%10 + 1;
            printf("%d ",randSets[i][&j]);
        }
        printf("\n");
    }
    
}

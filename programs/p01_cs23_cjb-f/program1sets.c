// program1sets.c
// CS23 Spring 2024 Assignment 1
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include<stdio.h>
#include<stdlib.h>
#include<program1header.h>

#define NUMSETS = 2;

int main(void){

    int SIZE[NUMSETS] = {5,3};
    
    int randn[max(SIZE)][2];

    for (int i = 0; i < 2; i ++) {
        for (int j = 0; j < SIZE[i]; j++) {
            srand(time(NULL));

        }

    }

    return 0;
}
// main.c
// C++ Main File for Program 1
// CS23 Spring 2024 Program 1
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include <iostream>
#include <set>
#include "header.h"


int main(void){

    std::set<int> A, B;

    fillSetRand(A, ASIZE);
    fillSetRand(B, BSIZE);
    std::cout << "\n";
    printSet(A, "A");
    printSet(B, "B");
    std::cout << "\n";
    printAsectB(A, B, "A - B");
    printAsectB(B, A, "B - A");
    std::cout << "\n";
    printIsAsubsB(A, B, "A", "B");
    printIsAsubsB(B, A, "B", "A");
    std::cout << "\n";
    printPofA(A, "A");
    printPofA(B, "B");
    std::cout << "\n";
    
    return 0;
}

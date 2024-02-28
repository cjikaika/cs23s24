// source.cpp
// C++ Source File for Program 1
// CS23 Spring 2024 Program 1
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include "header.h"


void fillSetRand(std::set<int>& set, int SIZE) {
    srand(time(NULL));
    
    for (int i = 0; i < SIZE; i ++) {
        set.insert(rand()%10 + 1);
    }
}


void printSet(const std::set<int>& set, std::string setID) {
    
    int c = 1;

    std::cout << setID << " = {";
    for (std::set<int>::iterator el = set.begin(); el != set.end(); ++el) {
        std::cout << " " << *el << (c < set.size() ? "," : "");
        c++;
    }
    std::cout << "}\n";
}


void printAsectB(const std::set<int>& A, const std::set<int>& B, std::string setID) {
    std::set<int> C;

    std::set_difference(A.begin(), A.end(), B.begin(), B.end(), 
        std::inserter(C, C.begin()));

    printSet(C, setID);
}


void printIsAsubsB(const std::set<int>& A, const std::set<int>& B, std::string idA, std::string idB){
    bool isSub = std::includes(B.begin(), B.end(), A.begin(), A.end());

    std::cout << idA << (isSub ? " is" : " is not") << " a subset of " << idB << ".\n";
}


void printPofA(const std::set<int>& set, std::string setID) {
   
    std::vector<int> vectorSet(set.begin(),set.end());
    int size = vectorSet.size();
    int pAsize = pow(2, size);

    std::cout << "P(" << setID << ") = {";
    for (int i = 0; i < pAsize; i++) {
        std::cout << "{";
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                std::cout << " " << vectorSet[j] << ",";
            }
        }
        std::cout << "}";
    }
    std::cout << "\n";

}

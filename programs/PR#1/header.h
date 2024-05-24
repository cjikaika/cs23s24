// header.h
// C++ Header File for Program 1
// CS23 Spring 2024 Program 1
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#ifndef HEADER_H
#define HEADER_H

#include <set>
#include <string>

// Function Prototypes //

void fillSets(std::set<int>&, std::set<int>&);
void fillSetRand(std::set<int>&, int);
void printSet(const std::set<int>&, std::string);
void printAsectB(const std::set<int>&, const std::set<int>&, std::string);
void printIsAsubsB(const std::set<int>&, const std::set<int>&, std::string, std::string);
void printPofA(const std::set<int>&, std::string);

#endif // HEADER_H

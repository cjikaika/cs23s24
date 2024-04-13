// counting_source.c
// C++ Source File for Program 2
// CS23 Spring 2024 Program 2
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include "counting_header.h"
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>

int mode(std::string line, int* argv) {
    std::istringstream input(line);
    std::string operation;
    int n, k;

    if (!(input >> n >> operation))
        return -1;
    
    if (operation == "choose") {
        if (input >> k) {
            argv[0] = n;
            argv[1] = k;
            return 1;
        }
        return -1;
    } else if (operation == "permute") {
        if (input >> k) {
            argv[0] = n;
            argv[1] = k;
            return 2;
        }
        return -1; 
    } else if (operation == "rderangement") {
        argv[0] = n;
        return 3;
    } else if (operation == "derangement") {
        argv[0] = n;
        return 4;
    } else {
        return -1;
    }
}

int calculate::choose(int n, int k) {
    if (n < 0 || n > 10000) {
        std::cerr << "Out of range. Please enter a value between 0 and 10000" << std::endl;
        exit;
    } else if (k > n) {
        return 0;
    }   

    int result = 1;
    
    for (int i = 1; i <= k; ++i) {
        result *= (n - 1 + i)/i;
    }

    return result;
}

int calculate::permute(int n, int k) {
   if (n < 0 || n > 10000) {
        std::cerr << "Out of range. Please enter a value between 0 and 10000" << std::endl;
        exit;
    } else if (k > n) {
        return 0;
    }

    int result = 1;
    
    for (int i = 1; i <= k; ++i) {
        result *= (n - i + 1);
    }

    return result;
}

int calculate::rderangement(int n) { // change output and input size
    if (n == 0)
        return 1;
    else if (n == 1)
        return 0;

    return (n - 1) * (calculate::rderangement(n - 1) + calculate::rderangement(n - 2));
}

std::string calculate::derangement(int n) {

    std::string dtable[] = {"1","0","1","2","9","44","265","1854","14833","133496","1334961",
        "14684570","176214841","2290792932","32071101049","481066515734","7697064251745",
        "130850092279664","2355301661033953","44750731559645106","895014631192902121",
        "18795307255050944540","413496759611120779881","9510425471055777937262"};

    if (n >= 0 && n <= 23)
        return dtable[n];
    return "Out of range. Please enter an integer input between 0 and 23";
}

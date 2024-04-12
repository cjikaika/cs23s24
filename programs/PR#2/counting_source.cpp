// counting_source.c
// C++ Source File for Program 2
// CS23 Spring 2024 Program 2
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include "counting_header.h"
#include <ctype.h>
#include <iostream>
#include <string>

void tools::argprint(int argc, char *argv[]) {
    std::cout << "Number of arguments: " << argc - 1 << std::endl; 

    for (int i = 1; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
}

int read::mode(int argc, char *argv[]) {
    switch (argc){
        case 3:
            if ((std::string)argv[1] == "rderangement")
                return 3;
            else if ((std::string)argv[1] == "derangement")
                return 4;
        case 4:
            if ((std::string)argv[2] == "choose")
                return 1;
            else if ((std::string)argv[2] == "permute")
                return 2;
    }
    return -1;
}

int calculate::factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n*calculate::factorial(n - 1);
}

int calculate::choose(char* nchar, char* kchar) {
    unsigned int n = std::stoi(nchar);
    unsigned int k = std::stoi(kchar);

    return calculate::factorial(n)/(calculate::factorial(k)*calculate::factorial(n-k));
}

int calculate::permute(char* nchar, char* kchar) {
    unsigned int n = std::stoi(nchar);
    unsigned int k = std::stoi(kchar);

    return calculate::factorial(n)/calculate::factorial(n-k);
}

int calculate::rderangement(int n) {
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
        "18795307255050944540","413496759611120779881","9510425471055777937262"
    };

    if (n >= 0 && n <= 23)
        return dtable[n];
    return "Out of range. Please choose an integer input between 1 and 23";
}

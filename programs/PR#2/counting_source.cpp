// counting_source.c
// C++ Source File for Program 2
// CS23 Spring 2024 Program 2
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include "counting_header.h"
#include <iostream>

void tools::argprint(int argc, char *argv[]) {
    std::cout << "Number of arguments: " << argc - 1 << std::endl; 

    for (int i = 1; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
}

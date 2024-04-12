// counting_main.c
// C++ Main File for Program 2
// CS23 Spring 2024 Program 2
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include "counting_header.h"
#include <iostream>

int main(int argc, char *argv[]) {

    tools::argprint(argc, argv);

    int intout = -1, n, mode = read::mode(argc, argv);
    std::string strout = "";

    switch (mode) {
        case 1: 
            {
            intout = calculate::choose(argv[1], argv[3]);
            break;
            }
        case 2:
            {
            intout = calculate::permute(argv[1], argv[3]);
            break;
            }
        case 3:
            {
            n = std::stoi(argv[2]);
            intout = calculate::rderangement(n);
            break;
            }
        case 4:
            {
            n = std::stoi(argv[2]);
            strout = calculate::derangement(n);
            break;
            }
        default:
            {
            std::cerr << "Please enter a valid set of input arguments";
            return -1;
            }
    }

    std::cout << (intout == -1 ? "" : std::to_string(intout)) << strout << std::endl;

    return 0;
}

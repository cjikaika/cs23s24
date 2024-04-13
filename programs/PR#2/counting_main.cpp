// counting_main.c
// C++ Main File for Program 2
// CS23 Spring 2024 Program 2
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include "counting_header.h"
#include <iostream>

int main() {

    std::string line;
    int argv[2], mode;
    
    while(getline(std::cin, line)) {
        mode = read::mode(line, argv);
        switch (mode) {
            case 1: {
                std::cout << calculate::choose(argv[0], argv[1]) << std::endl;
                break;
            }
            case 2: {
                std::cout << calculate::permute(argv[0], argv[1]) << std::endl;
                break;
            }
            case 3: {
                if (argv[0] < 0 || argv[0] > 15) {
                    std::cerr << "Out of range. Please enter a value between 0 and 15" << std::endl;
                    break;
                } else {
                    std::cout << calculate::rderangement(argv[0]) << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << calculate::derangement(argv[0]) << std::endl;
                break;
            }
            default: {
                std::cerr << "Please enter a valid set of input arguments";
                break;
            }
        }
    }

    return 0;
}

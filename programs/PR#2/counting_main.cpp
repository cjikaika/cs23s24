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
    unsigned long long output;
    
    while(getline(std::cin, line)) {
        mode = read::mode(line, argv);
        switch (mode) {
            case 1: {
                output = calculate::choose(argv[0], argv[1]);
                if (output == -1) {
                    std::cerr << "Output out of range. Please enter smaller input values" << std::endl;
                } else {
                    std::cout << argv[0] << " choose " << argv[1] << " = " << output << std::endl;
                    break;
                }
            }
            case 2: {
                output = calculate::permute(argv[0], argv[1]);
                if (output == -1) {
                    std::cerr << "Output out of range. Please enter smaller input values" << std::endl;
                } else {
                    std::cout << argv[0] << " permute " << argv[1] << " = " << output << std::endl;
                    break;
                }
            }
            case 3: {
                if (argv[0] < 0 || argv[0] > 20) {
                    std::cerr << "Out of range. Please enter a value between 0 and 20" << std::endl;
                    break;
                } else {
                    std::cout << "rderangement " << argv[0] << " = " << calculate::rderangement(argv[0]) << std::endl;
                }
                break;
            }
            case 4: {
                std::cout << "derangement " << argv[0] << " = " << calculate::derangement(argv[0]) << std::endl;
                break;
            }
            default: {
                std::cerr << "Please enter a valid set of input arguments" << std::endl;
                break;
            }
        }
    }

    return 0;
}

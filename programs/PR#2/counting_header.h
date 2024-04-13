// counting_header.h
// C++ Header File for Program 2
// CS23 Spring 2024 Program 2
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include <string>

namespace read {
    int mode(std::string, int*); // 1 = choose, 2 = permute, 3 = rederangement, 4 = derangement
}

namespace calculate {
    int choose(int, int);
    int permute(int, int);
    int rderangement(int);
    std::string derangement(int);
}

// counting_header.h
// C++ Header File for Program 2
// CS23 Spring 2024 Program 2
// Author: CJ Bridgman-Ford
// Email: cj.ikaika@gmail.com

#include <string>

namespace tools {
    void argprint(int, char *argv[]);
}

namespace read {
    int mode(int, char *argv[]); // 1 = choose, 2 = permute, 3 = rederangement, 4 = derangement
}

namespace calculate {
    int factorial(int);
    int choose(char*, char*);
    int permute(char*, char*);
    int rderangement(int);
    std::string derangement(int);
}

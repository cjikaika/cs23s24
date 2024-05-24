// Generates 27 possible dice rolls for problem 5a because no
// way I'm typing those aout and getting them all right.

#include<fstream>
#include<iostream>
#include<vector>

int main() {
    int lineCount = 0;
    std::string filename = "dicerolls.txt";
    char rolls[3] = {'R','G','B'};
    std::ofstream outfile(filename, std::ios::out | std::ios::trunc);

    if (outfile.is_open()) {

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    outfile << rolls[i] << rolls[j] << rolls[k] << ", ";
                    ++lineCount;
                }
            }
        }
        std::cout << "Successfully wrote " << lineCount <<
            " lines of code to " << filename << "!" << std::endl;
    } else {
        std::cerr << "Error opening file: " << filename << std::endl;
    }
}

// Significant portions of code generated from Google Gemini (Free Version).

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  string filename = "testfile.txt";

  ofstream outfile(filename, ios::out | ios::trunc);

  int lineCount = 0;

  if (outfile.is_open()) {
    for (int n = 1; n <= stoi(argv[1]); ++n) {
        for (int k = 1; k <= n; ++k) {
            string line = to_string(n) + " choose " + to_string(k);
            outfile << line << endl;
            ++lineCount;
        }
    }
    for (int n = 1; n <= stoi(argv[2]); ++n) {
        for (int k = 1; k <= n; ++k) {
            string line = to_string(n) + " permute " + to_string(k);
            outfile << line << endl;
            ++lineCount;
        }
    }
    for (int n = 0; n <= stoi(argv[3]); ++n) {
        string line = "rderangement " + to_string(n);
        outfile << line << endl;
        ++lineCount;
    }
    for (int n = 0; n <= stoi(argv[4]); ++n) {
        string line = "derangement " + to_string(n);
        outfile << line << endl;
        ++lineCount;
    }

    outfile.close();
    cout << lineCount << " lines written to " << filename << endl;
  } else {
    cerr << "Error opening file: " << filename << endl;
  }

  return 0;
}
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

bool NFA();
bool DFA();

int main(int argc, char*argv[]) {
  if (argc != 2) {
    std::cerr << "Please enter a proper number of input arguments: ./FSM <filepath>" << std::endl;
    return 1;
  }
  std::ifstream setup(argv[1]);
  if (!setup.is_open()) {
    std::cerr << "Error opening FSM Setup File: " << argv[1] << std::endl;
    return 1;
  }

  std::string line;
  std::vector<std::string> setupData;
  while (std::getline(setup, line)) {
    setupData.push_back(line);
  }
  int states = std::stoi(setupData[1].substr(7, setupData[1].length() - 7)),
    inputs = std::stoi(setupData[2].substr(7, setupData[1].length() - 7)),
    start = std::stoi(setupData[3].substr(6, setupData[1].length() - 7));
  std::map<int, bool> accepting;
  for (int i = 0; i < states; ++i) {
    accepting[i] = false;
  }
  std::vector<size_t> spacePos;
  spacePos.push_back(9);
  for (size_t i = 10; i < setupData[4].length(); ++i) {
    if (setupData[4][i] == ' ') {
      spacePos.push_back(i);
    }
  }
  for (size_t i = 1; i <= spacePos.size(); ++i) {
    accepting[std::stoi(setupData[4].substr(spacePos[i - 1] + 1,
      spacePos[i] - spacePos[i - 1] - 1))] = true;
  }

  int count, pos1, pos2;
  std::map<std::tuple<int, int>, std::vector<int>> transitions;
  for (size_t i = 6; i < setupData.size(); ++i) {
    pos1 = -1;
    pos2 = -1;
    count = 0;
    for (char c : setupData[i]) {
      if (c == ' ' ) {
        if (pos1 == -1) {
          pos1 = count;
        } else {
          pos2 = count;
        }
      }
      ++count;
    }
    transitions[std::tuple<int, int>{
      std::stoi(setupData[i].substr(0, pos1)),
      std::stoi(setupData[i].substr(pos2 + 1, setupData[i].length() - pos2 - 1))
      }].push_back(std::stoi(setupData[i].substr(pos1 + 1, pos2 - pos1 - 1)));
    std::cout <<  transitions[std::tuple<int, int>{
      std::stoi(setupData[i].substr(0, pos1)),
      std::stoi(setupData[i].substr(pos2 + 1, setupData[i].length() - pos2 - 1))
      }][0] << std::endl;
  }
  std::cout << std::endl;


  if (setupData[0] == "deterministic") {
    std::cout << "DFA | " << setupData[0] << std::endl;
  } else if (setupData[0] == "nondeterministic") {
    std::cout << "NFA | " << setupData[0] << std::endl;
  }

  std::cout << "States: | " << states << std::endl;
  std::cout << "Start: | " << start << std::endl;
  std::cout << "Inputs: | " << inputs << std::endl;
  std::cout << std::endl << "Accepting:" << std::endl;
  for (int i = 0; i < states; ++i) {
    std::cout << i << " | " << (accepting[i] ? "accepting" : "normie") << std::endl;
  }
  std::cout << std::endl << "Transitions" << " (size = " << transitions.size() << ")"
    << std::endl << std::endl;





  if (setupData[0] == "deterministic") {
    std::cout << "DFA | " << setupData[0] << std::endl;
  } else if (setupData[0] == "nondeterministic") {
    std::cout << "NFA | " << setupData[0] << std::endl;
  }


  return 0;
}
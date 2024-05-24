#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
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
  std::set<int> tMapSet;
  std::map<int, std::vector<std::set<int>>> transitions;

  while (std::getline(setup, line)) {
    setupData.push_back(line);
  }

  int states = std::stoi(setupData[1].substr(7, setupData[1].length() - 7)),
    inputs = std::stoi(setupData[2].substr(7, setupData[1].length() - 7)),
    start = std::stoi(setupData[3].substr(6, setupData[1].length() - 7));
  std::map<int, bool> accepting;

  for (int i = 6; i < setupData.size(); ++i) {
    
  }










  if (setupData[0] == "deterministic") {
    // build dfsm
  } else if (setupData[0] == "nondeterministic") {
    // build nfsm
  }

  while(std::getline(std::cin, line)) {

  }

  return 0;
}
/* 
* @file FSM.cpp
* @author CJ Bridgman-Ford | cj.ikaika@gmail.com
* CS23 Program #3 | Spring 2024
*/

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

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
      if (c == ' ') {
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
  }

  if (setupData[0] == "deterministic") {
    int currentState, input;
    while (getline(std::cin, line)) {
      currentState = start;
      pos1 = -1;
      pos2 = 0;
      count = 0;
      line += " ";
      for (char c : line) {
        if (c == ' ') {
          pos2 = count;
          if (pos2 - pos1 - 1 > 0) {
            input = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            if (input >= 0 && input < inputs) {
              currentState = transitions[std::tuple<int, int>{currentState, input}][0];
            } else {
              std::cerr << "Input " << input << " is out of range | ";
              break;
            }
          }
          pos1 = pos2;
        }
        ++count;
      }
      if (accepting[currentState]) {
        std::cout << "accepted" << std::endl;
      } else {
        std::cout << "rejected" << std::endl;
      }
    }
  } else if (setupData[0] == "nondeterministic") {
    std::vector<int> currentState, nextState;
    int input;
    bool accepted;
    while (getline(std::cin, line)) {
      if (transitions[std::tuple<int, int>{start, -1}].size() > 0) {
        for (int i : transitions[std::tuple<int, int>{start, -1}]) {
          currentState.push_back(i);
        }
      } else {
        currentState.push_back(start);
      }
      pos1 = -1;
      pos2 = 0;
      count = 0;
      accepted = false;
      line += " ";
      for (char c : line) {
        if (c == ' ') {
          pos2 = count;
          if (pos2 - pos1 - 1 > 0) {
            input = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            if (input >= 0 && input < inputs) {
              for (int i : currentState) {
                for (size_t j = 0; j < transitions[std::tuple<int, int>{currentState[i], input}].size(); ++j) {
                  nextState.push_back(transitions[std::tuple<int, int>{currentState[i], input}][j]);
                }
              }
              currentState = nextState;
              nextState.clear();
              for (int i : currentState) {
                if (transitions[std::tuple<int, int>{i, -1}].size() > 0) {
                  for (int j : transitions[std::tuple<int, int>{i, -1}]) {
                    nextState.push_back(j);
                  }
                } else {
                  nextState.push_back(i);
                }
              }
              currentState = nextState;
              nextState.clear();
            } else {
              std::cerr << "Input " << input << " is out of range | ";
              break;
            }
          }
          pos1 = pos2;
        }
        ++count;
      }
      for (int c : currentState) {
        if (accepting[c]) {
          accepted = true;
        }
      }
      if (accepted) {
        std::cout << "accepted" << std::endl;
      } else {
        std::cout << "rejected" << std::endl;
      }
    }
  } else {
    std::cerr << "Please configure either a deterministic or nondeterministic FSM."
      << std::endl;
    return 1;
  }

  return 0;
}

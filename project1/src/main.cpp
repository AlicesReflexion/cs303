#include "elevator.h"
#include "floors.h"
#include <iostream>
#include <iterator>
#include <sstream>

void prettyPrint(floors floors, std::vector<elevator> elevators);
void moveUsersToElevators(floors floors, std::vector<elevator> elevators);

void processSim(std::string simulateText);
void interactive(bool doPrint);

int main(int argc, char **argv) {
  bool doPrint = true;
  bool simulate = false;
  std::string simulateText;
  for (int i = 1; i < argc; i++){
    if ((std::string(argv[i]))=="--no-pretty")
      doPrint = false;
    if ((std::string(argv[i])).substr(0, 6) == "--sim=") {
      simulate = true;
      simulateText =  argv[i];
    }
  }
  if (simulate) {
    processSim(simulateText);
  }
  else
    interactive(doPrint);
  return 0;
}

void processSim(std::string simulateText) {
  // Convert the simulation text to an array of commands.
  simulateText = simulateText.substr(6, simulateText.length()-6);
  std::stringstream ss(simulateText);
  std::istream_iterator<std::string> begin(ss);
  std::istream_iterator<std::string> end;
  std::vector<std::string> steps(begin, end);

  std::vector<elevator> elevators;
  floors floors(stoi(steps[0]));

  // The code expects a final delimiting ':' at the end. This fixes that.
  if(steps[1][steps[1].length()-1] != ':')
    steps[1] += ":";
  // Push elevators at every number between the delimiting ':'
  int lastDelimiter = 0;
  for (int i = 0; i < steps[1].size(); i++) {
    if (steps[1][i] == ':'){
      elevators.push_back(elevator(stoi(steps[1].substr(lastDelimiter, i-lastDelimiter)), 0));
      lastDelimiter = i + 1;
    }
  }

  prettyPrint(floors, elevators);

  for (int i = 2; i < steps.size(); i++) {
    std::cout << steps[i] << std::endl;
  }
}

void interactive(bool doPrint) {
  floors floors(20);
  std::vector<elevator> elevators;
  if (doPrint)
    prettyPrint(floors, elevators);
}


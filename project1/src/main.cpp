#include "elevator.h"
#include "floors.h"
#include <iostream>

void prettyPrint(floors floors, std::vector<elevator> elevators);
void moveUsersToElevators(floors floors, std::vector<elevator> elevators);

int main(int argc, char **argv) {
  bool doPrint = true;
  bool simulate = false;
  for (int i = 1; i < argc; i++){
    if ((std::string(argv[i]))=="--no-pretty")
      doPrint = false;
    if ((std::string(argv[i])).find("--sim") != std::string::npos)
      simulate = true;
  }

  floors floors(20);
  std::vector<elevator> elevators;
  if (doPrint)
    prettyPrint(floors, elevators);
  return 0;
}

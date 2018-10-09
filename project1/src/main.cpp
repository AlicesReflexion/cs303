#include "elevator.h"
#include "floors.h"
#include <iostream>

void prettyPrint(floors floors, std::vector<elevator> elevators);

int main() {
  floors floors(20);
  std::vector<elevator> elevators;
  elevators.push_back(elevator(12, 0));
  elevators.push_back(elevator(3, 0));
  elevators.push_back(elevator(1,0));
  elevators.push_back(elevator(20,0));
  floors.addUser(12, 20);
  floors.addUser(12, 7);
  floors.addUser(12, 19);
  floors.addUser(7, 9);
  floors.addUser(19, 1);
  floors.addUser(19, 1);
  floors.addUser(19, 1);
  floors.addUser(19, 1);
  floors.addUser(19, 1);
  floors.addUser(1,3);
  floors.addUser(20,2);
  prettyPrint(floors, elevators);
  return 0;
}

#include "elevator.h"
#include "floors.h"
#include <iostream>

void prettyPrint(floors floors, std::vector<elevator> elevators);

int main() {
  floors floors(20);
  std::vector<elevator> elevators;
  elevators.push_back(elevator(12, 0));
  floors.addUser(12, 20);
  prettyPrint(floors, elevators);
  return 0;
}

void prettyPrint(floors floors, std::vector<elevator> elevators) {
  int maxWidthUsers;
  int maxWidthElevators;
  std::string userRow;
  std::cout << floors.size();
  for (int i = 0; i < floors.size(); i++) {
  } 
  std::cout << "+" << std::endl;
}

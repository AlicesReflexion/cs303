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

void prettyPrint(floors floors, std::vector<elevator> elevators) {
  int floorLength = std::to_string(floors.getSize()).length();
  int maxWidthUsers;
  int maxWidthElevators;
  std::string userRow;
  for (int i = 0; i < floors.getSize(); i++) {
    for(int j = 0; j < floors.listUsers(i).size(); j++) {
      userRow = userRow + std::to_string(floors.listUsers(i)[j]) + " ";
    }
    if (userRow.length() > maxWidthUsers)
      maxWidthUsers = userRow.length() - 1;
    userRow = "";
  }
  std::cout << "+" << std::string(floorLength, '-') << "+" << std::string(maxWidthUsers, '-') << "+" << std::endl;
  
  for(int i = floors.getSize()-1; i > -1; i--) {
    std::string elevatorText = "";
    for(int j = 0; j < floors.listUsers(i).size(); j++) {
      userRow = userRow + std::to_string(floors.listUsers(i)[j]) + " ";
    }
    if (userRow != "")
      userRow.pop_back();
    for(int k = 0; k < elevators.size(); k++){
      if (elevators[k].getCurrentLocation() == i+1)
        switch(elevators[k].getCurrentDirection()){
          case 0:
            elevatorText += "X";
            break;
          case 1:
              elevatorText += "^";
              break;
          case 2:
              elevatorText += "V";
              break;
        }
    }
    std::cout << "|"
      << i+1 
      << std::string(floorLength - std::to_string(i+1).length(), ' ')
      << "|" << userRow << std::string(maxWidthUsers - userRow.length(), ' ') << "|" << 
      elevatorText << std::endl;
    userRow = "";
  }
  std::cout << "+" << std::string(floorLength, '-') << "+" << std::string(maxWidthUsers, '-') << "+" << std::endl;
}

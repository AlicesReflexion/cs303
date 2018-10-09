#include "floors.h"
#include "elevator.h"
#include <iostream>

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

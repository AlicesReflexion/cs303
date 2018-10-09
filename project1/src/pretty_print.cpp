#include "floors.h"
#include "elevator.h"
#include <iostream>

//Prints out the elevators on a floor, including direction and users inside.
//For example, if there are two elevators on a floor, with users for 1, 2, 3
//in each, one going up, and one down, this would print
//'^ 1 2 3 | V 1 2 3` 
std::string printElevator(std::vector<elevator> elevators, int row) {
  std::string elevatorText = "";
  for(int i = 0; i < elevators.size(); i++){
      if (elevators[i].getCurrentLocation() == row+1)
        switch(elevators[i].getCurrentDirection()){
          case elevator::DIRECTION::STOP:
            elevatorText += "X";
            break;
          case elevator::DIRECTION::UP:
              elevatorText += "^";
              break;
          case elevator::DIRECTION::DOWN:
              elevatorText += "V";
              break;
        }
    }
  return elevatorText;
}

//Prints out the users waiting on a floor.
//Eg. If on a floor users are waiting to get to floors 17, 22 and 9
//this would print out '17 22 9'
std::string printUser(floors floors, int row) {
  std::string userRow = "";
  for(int j = 0; j < floors.listUsers(row).size(); j++) {
      userRow = userRow + std::to_string(floors.listUsers(row)[j]) + " ";
    }
  //Remove trailing space
    if (userRow != "")
      userRow.pop_back();
  return userRow;
}

//Prints out the text and the appropriate number of padding to fill out the column.
//eg. if our column is 14 characters wide, and our text is 7 characters, this would
//fill the remaining 7 characters with spaces.
std::string printSpaces(std::string orgText, int columnWidth){
return orgText + std::string(columnWidth - orgText.length(), ' ');
}

//Prints out the complete state of the elevator in a table.
void prettyPrint(floors floors, std::vector<elevator> elevators) {
  int columnWidthFloors = std::to_string(floors.getSize()).length();
  int columnWidthUsers = 0;
  int columnWidthElevators = 0;
  
  //find the widest group of users and set the column width appropriately.
  for (int i = 0; i < floors.getSize(); i++) {
    if(printUser(floors, i).length() > columnWidthUsers)
      columnWidthUsers = printUser(floors, i).length();
  }

  //The same for the elevator column.
  for(int i = 0; i < floors.getSize(); i++) {
    if(printElevator(elevators, i).length() > columnWidthElevators)
      columnWidthElevators = printElevator(elevators, i).length();
  }

  //The top row
  std::cout << 
    "+" << std::string(columnWidthFloors, '-') << 
    "+" << std::string(columnWidthUsers, '-') << 
    "+" << std::string(columnWidthElevators, '-') << "+" << std::endl;
  //The data
  for(int i = floors.getSize()-1; i > -1; i--) {
        
    std::cout << 
      "|" << printSpaces(std::to_string(i+1), columnWidthFloors) <<
      "|" << printSpaces(printUser(floors, i), columnWidthUsers) << 
      "|" << printSpaces(printElevator(elevators, i), columnWidthElevators) <<
      "|" << std::endl;
  }
  //The bottom row
  std::cout << 
    "+" << std::string(columnWidthFloors, '-') << 
    "+" << std::string(columnWidthUsers, '-') << 
    "+" << std::string(columnWidthElevators, '-') << "+" << std::endl;
}

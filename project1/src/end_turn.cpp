#include "floors.h" 
#include "elevator.h"
#include <iostream>

void moveUsersToElevators(floors floors, std::vector<elevator> elevators) {
  for(int i = 0; i < floors.getSize(); i++) {
    if (!floors.listUsers(i).empty()) {
      for(int j = 0; j < elevators.size(); j++) {
        if (elevators[j].getCurrentLocation() == i+1)
          std::cout << "Things to copy at " << i+1 << std::endl;
      }
    }
  }
}

void findNearestElevatorAndChangeDirection(int floor, elevator::DIRECTION direction, std::vector<elevator> elevators) {
  //the largest 32-bit signed int
  int distance = 2147483647;
  elevator* closest;
  for(int i = 0; i < elevators.size(); i++) {
    if(elevators[i].getCurrentDirection() ==  elevator::DIRECTION::STOP|| elevators[i].getCurrentDirection() == direction) {
      switch(direction) {
      }
    }
  }
}

void moveElevators(std::vector<elevator> elevators) {
  for (int i = 0; i < elevators.size(); i++)
    elevators[i].removeUsers();
}

void endTurn(floors floors, std::vector<elevator> elevators) {
  for(int i = 0; i < elevators.size(); i++)
    elevators[i].removeUsers();
  moveUsersToElevators(floors, elevators);
  moveElevators(elevators);
}

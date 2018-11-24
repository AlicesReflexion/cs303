#include "elevator.h"

void elevator::addUser(int requestedLocation) {
  users.push_back(requestedLocation);
}

void elevator::removeUsers() {
  for (int i = 0; i < users.size(); i++) {
    if (users[i] == location)
      users.erase(users.begin()+i);
  }
}

int elevator::getCurrentLocation() {
  return location;
}

elevator::DIRECTION elevator::getCurrentDirection() {
  return currentDirection;
}

std::vector<int> elevator::getCurrentUsers() {
  return users;
}

void elevator::moveElevator() {
  switch(currentDirection) {
    case elevator::DIRECTION::UP:
      location = location++;
      break;
    case elevator::DIRECTION::STOP:
      break;
    case elevator::DIRECTION::DOWN:
      location = location--;
      break;
  }
}

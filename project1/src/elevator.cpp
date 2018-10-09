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

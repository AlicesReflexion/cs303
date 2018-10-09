#include "floors.h"
#include <vector>

void floors::addUser(int location, int requestedLocation) {
  users[location-1].push_back(requestedLocation);
}

int floors::getSize() {
  return size;
}

std::vector<int> floors::listUpUsers(int location) {
  std::vector<int> upUsers;
  // Look at every item on this floor
  for (int i = 0; i < users[location].size(); i++) {
    // If the floor the user wants to go to is above the floor they're currently on.
    if (users[location][i] > location)
      upUsers.push_back(users[location][i]);
  }
  return upUsers;
}

std::vector<int> floors::listDownUsers(int location) {
  std::vector<int> downUsers;
  for (int i = 0; i < users[location].size(); i++) {
    if (users[location][i] < location)
      downUsers.push_back(users[location][i]);
  }
  return downUsers;
}

std::vector<int> floors::listUsers(int location) {
  return users[location];
}

void floors::removeUpUsers(int location) {
  for (int i = 0; i < users[location].size(); i++) {
    if (users[location][i] > location)
      users[location].erase(users[location].begin()+i);
  }
}

void floors::removeDownUsers(int location) {
  for (int i = 0; i < users[location].size(); i++) {
    if (users[location][i] < location)
      users[location].erase(users[location].begin()+i);
  }
}

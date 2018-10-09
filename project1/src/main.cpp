#include "elevator.h"
#include "floors.h"
#include <iostream>

int main() {
  floors word(20);
  word.addUser(12, 20);
  std::cout << word.listUpUsers(12)[0];
  return 0;
}

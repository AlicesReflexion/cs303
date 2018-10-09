#include <vector>
#ifndef ELEVATOR_H
#define ELEVATOR_H

class elevator{

  public:
    //A capacity of 0 indicates no limit
    elevator(int initLocation, int capacity) {
      //0 => not moving, 1 => up, 2 => down.
      direction = 0;
      location = initLocation;
    }
    int getCurrentLocation();
    int getCurrentDirection();
    void addUser(int requestedLocation);
    void removeUsers();

  private:
    int location;
    int direction;
    std::vector<int> users;
};

#endif

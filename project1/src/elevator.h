#include <vector>
#ifndef ELEVATOR_H
#define ELEVATOR_H

class elevator{

  
  public:
    //A capacity of 0 indicates no limit
    elevator(int initLocation, int capacity) {
      currentDirection = STOP;
      location = initLocation;
    }
    enum DIRECTION{STOP = 0, UP = 1, DOWN = 2};
    int getCurrentLocation();
    DIRECTION getCurrentDirection();
    void addUser(int requestedLocation);
    void removeUsers();
    std::vector<int> getCurrentUsers();
    void moveElevator();

  private:
    int location;
    DIRECTION currentDirection;
    std::vector<int> users;
};

#endif

#include <vector>
#include <array>

#ifndef FLOORS_H
#define FLOORS_H
class floors {

  public:
    floors(int initSize) {
      users = new std::vector<int>[initSize];
      size = initSize;
    }

    void addUser(int location, int requestedLocation);
    void removeUpUsers(int location);
    void removeDownUsers(int location);
    int getSize();
    std::vector<int> listUpUsers(int location);
    std::vector<int> listDownUsers(int location);
    std::vector<int> listUsers(int location);

  private:
    std::vector<int>* users;
    //We cannot get the size of C-arrays if we are using pointers.
    //And we cannot use std::Array with a variable size
    //So storing this is probably the best way to go.
    int size;
};

#endif

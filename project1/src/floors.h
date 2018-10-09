#include <vector>
#include <array>

#ifndef FLOORS_H
#define FLOORS_H
class floors {

  public:
    floors(int size) {
      users = new std::vector<int>[size];
    }

    void addUser(int location, int requestedLocation);
    void removeUpUsers(int location);
    void removeDownUsers(int location);
    std::vector<int> listUpUsers(int location);
    std::vector<int> listDownUsers(int location);

  private:
    std::vector<int>* users;
};

#endif

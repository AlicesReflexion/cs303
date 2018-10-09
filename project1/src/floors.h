#include <vector>
#include <array>

class floors {

  public:
    floors(int size) {
      users = new std::vector<int>[size];
    }

    void addUser(int location, int requestedLocation);
    void removeUpUsers();
    void remoeDownUsers();

  private:
    std::vector<int>* users;
};

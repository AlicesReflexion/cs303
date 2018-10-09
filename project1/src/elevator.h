#include <vector>

class Elevator{

  public:

    Elevator(int location);

    void addUser(int requestedLocation){
    
    }

    void removeUsers(int requestedLocation);

  private:
    int location;
    int direction;
    std::vector<int> users;
};

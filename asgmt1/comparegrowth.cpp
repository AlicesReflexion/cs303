#include <iostream>
using namespace std;

int main() 
{
    for(int n = 0; n <= 100; n += 10) {
      int y1 = 100 * n + 10;
      int y2 = 5 * n * n + 2;
      cout << "y1: " << y1 << endl;
      cout << "y2: " << y2 << endl;
    }
    return 0;
}

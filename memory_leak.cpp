#include <iostream>
using namespace std;

int main() {
    for(int i = 0; i < 200000000 ; i++){
        new int (10);
    }

    return 0;
}
//At the end of the program, all memory addresses are de-allocated, including leaked memory, managed by the operating system.

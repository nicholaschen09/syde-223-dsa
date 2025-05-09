#include <iostream>
int main() {
    int n = 4; 		// can change the value of n here.
    int result = 0; 	// to store the result, initial value is zero.
    // Unambiguously specified finite sequence of steps below

    switch (n){
        case 0: result = 0;
            break;
        case 1: result = 1;
            break;
        case 2: result = 3;
            break;
        case 3: result = 6;
            break;
        case 4: result = 10;
            break;
        default:
            std::cout<<"Error! I did not consider this yet. "<<std::endl;
            break;
    }

    std::cout<<"The result is: "<<result<<std::endl;
    return result;
}
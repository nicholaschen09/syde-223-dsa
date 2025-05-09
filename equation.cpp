#include <iostream>
int main() {
    int n = 4; 		// can change the value of n here.
    int result = 0; 	// to store the result, initial value is zero.
    // Unambiguously specified finite sequence of steps below

    result = n * (n+1) / 2;

    std::cout<<"The result is: "<<result<<std::endl;
    return result;
}
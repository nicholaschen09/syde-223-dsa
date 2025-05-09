#include <iostream>
int main() {
    int n = 4; 		// can change the value of n here.
    int result = 0; 	// to store the result, initial value is zero.
    // Unambiguously specified finite sequence of steps below

    for(int i = 1; i <= n; i++){
        result = result + i;
    }

    std::cout<<"The result is: "<<result<<std::endl;
    return result;
}
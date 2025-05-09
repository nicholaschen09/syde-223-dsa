#include <iostream>
using namespace std;

int main() {
    // Note that you will get a different address value each time you run this and on different machines
    // as it will get initialized differently and hence have a different memory address.

    // Case 1: Normal
    int normal_x;
    normal_x = 10;
    cout<< normal_x << endl; // Value: 10
    cout<< &normal_x << endl; // Address: 0x16bb83298
    cout<< sizeof(normal_x) << endl; // Size of value: 4 bytes (int)
    cout<< sizeof(&normal_x) << endl; // Size of memory address: 8 bytes (address)
    cout << endl;
    // Summary:
    // a. To get value of normal_x, call normal_x
    // b. To get address of normal_x, call &normal_x
    // c. Size of int is 4 bytes
    // d. Size of memory address is 8 bytes
    // Caveat for size of -> could depend on the operating system but these are the typical values

    // Case 2: Pointer to Integer
    int *pointer_y; // Notice how it's initialized with an * at the start
    pointer_y = &normal_x; // Here, we point to the address of normal_x; think: pointer_y -> normal_x = 10
    cout<< *pointer_y << endl; // Value: 10 (the value of what is located at the address)
    cout<< pointer_y << endl; // Address: 0x16bb83298 (where final value is stored)
    cout<< &pointer_y << endl; // Address: 0x16b5e3290 (notice that it's different here as the pointer itself has a different address)

    *pointer_y = 20; // Here we change the value of what is located at the address; think: pointer_y -> normal_x = 10
    cout<< *pointer_y << endl; // Value: 20 (the value of what is located at the address)
    cout<< pointer_y << endl; // Address: 0x16bb83298 (where final value is stored)
    cout<< normal_x << endl; // Value: 20 (because we changed the value stored at the address)
    cout<< &normal_x << endl; // Address: 0x16bb83298
    cout << endl;

    // Fun Extension: Chain of Pointers
    int x, *pointer_1, *pointer_2, *pointer_3, *pointer_4;
    x = 42;
    pointer_1 = &x;
    pointer_2 = pointer_1;
    pointer_3 = pointer_2;
    pointer_4 = pointer_3;

    cout<< x << endl; // Value: 42 (no changes)
    *pointer_4 = 100;
    cout<< x << endl; // Value: 100 (updated)
    cout << endl;
    // Why?
    // Because pointer_4 -> pointer_3 -> pointer_2 -> pointer_1 -> x
    // If we change the value at pointer_4, that's the same as changing the value at x because pointer_4 ultimately points to x

    // Pro Tip: When I print the variable (as it is initialized, I will always get the VALUE)
    // The moment, I change the original variable name; remove a * or add a &, I get the address.
    // Removing the * gives you the address of what it's pointing towards.
    // Adding a & gives you the actual address of that variable (pointers have addresses too!)
    // Elaborating -> int normal_x, *pointer_y; => printing normal_x, *pointer_y -> actual value
    // Doing &normal_x, &pointer_y => address of variable
    // Doing pointer_y => address of whatever it's pointing towards
    // Note *normal_x would generate an error.

    // Fun Extension 2: Chain of Pointers with more ****
    int y, *p1, **p2, ***p3;
    y = 1;
    p1 = &y;
    p2 = &p1;
    p3 = &p2;

    cout<<"y"<<endl;
    cout<< y << endl; // Value = 1
    cout<< &y << endl; // Address of y = 0x16f117264

    cout<<"*p1"<<endl;
    cout<< *p1 << endl; // Final value = 1
    cout<< p1 << endl; // Address of y (where final value is stored) = 0x16f117264
    cout<< &p1 << endl; // Address of p1 (0x16f117258)

    cout<<"**p2"<<endl;
    cout<< **p2 << endl; // Final value = 1
    cout<< *p2 << endl; // Address of y (where final value is stored) = 0x16f117264
    cout<< p2 << endl; // Address of p1 (where p2 is pointing at) = (0x16f117258)
    cout<< &p2 << endl; // Address of p2 = 0x16f117250

    cout<<"***p3"<<endl;
    cout<< ***p3 << endl; // Final value = 1
    cout<< **p3 << endl;  // Address of y (where final value is stored) = 0x16f117264
    cout<< *p3 << endl; // Address of p1 (working backwards -> what was pointing to final value) = 0x16f117258
    cout<< p3 << endl; // Address of p2 (where p3 was pointing) = 0x16f117250
    cout<< &p3 << endl; // Address of p3 = 0x16f117248

    return 0;
}
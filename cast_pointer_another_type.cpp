#include <iostream>
using namespace std;

// cast a pointer into a different type pointer

int main()
{
    int* p = new int(65);
    char* ch = (char *)p;
    double* d = (double *)p;

    cout << *p << endl;
    cout << *ch << endl;
    cout << *d << endl;
    cout << endl;

    cout << p << endl;
    cout << (void *)ch << endl;       //cout << ch << endl;     //cout prints out the characters until it hits a null terminating character
    cout << d << endl;
    cout << endl;

    cout << sizeof (*p) << endl;
    cout << sizeof (*ch) << endl;
    cout << sizeof (*d) << endl;

    return 0;
}
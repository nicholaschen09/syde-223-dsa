#include <iostream>

class MyClass {
public:
    MyClass() {std::cout <<"MyClass constructed\n";}
    ~MyClass() {std::cout <<"MyClass destructed\n";}
};

class MyClass2 {
public:
    MyClass2() {std::cout <<"MyClass2 constructed\n";}
    ~MyClass2() {std::cout <<"MyClass2 destructed\n";}
};

class ClassWithPointer {
private:
    int i;
    int *ip;
    MyClass *cp;
    MyClass2 m2;

public:
    ClassWithPointer();
    ~ClassWithPointer();
};

ClassWithPointer::ClassWithPointer() {
    i = 10;
    ip = new int(20);
    cp = new MyClass;
}

ClassWithPointer::~ClassWithPointer() {
    /*
        delete ip;
        ip = NULL; //not very necessary, because no code will use this pointer after this anyway
        delete cp;
        cp = NULL; //not very necessary, because no code will use this pointer after this anyway
    */
}


int main () {

    ClassWithPointer testObj;       // set a break point here and step into to see constructor and destructor called

    return 0;
}
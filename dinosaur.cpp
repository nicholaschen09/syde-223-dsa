#include <iostream>
#include <string>
using namespace std;

struct Dinosaur {
    //all members are public by default
    string name;
    string location;
    int age;
};

class DinosaurLibrary {
    //all members are private by default
    Dinosaur dinosaurLibrary[100];
    int size = 0;

public:
    void addDinosaur (string name, string location, int age);
    void printAll ();
};

void DinosaurLibrary::addDinosaur(string name, string location, int age) {
    dinosaurLibrary[size].name = name;
    dinosaurLibrary[size].location = location;
    dinosaurLibrary[size].age = age;
    size++;
}

void DinosaurLibrary::printAll() {
    for (int i = 0; i < size; i++){
        cout<<"Dinosaur #" << i << ": " << dinosaurLibrary[i].name << " " << dinosaurLibrary[i].location << ", age: " << dinosaurLibrary[i].age<< endl;
    }
}



int main() {
    DinosaurLibrary inventory;

    //add dinosaur
    inventory.addDinosaur("trex", "canada", 10);

    //print all
    inventory.printAll();

    return 0;
}
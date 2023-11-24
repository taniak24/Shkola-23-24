#include <iostream>

using namespace std;

int main()
{
    ///REFERENCE///
    string animal = "dog";
    string& refer = animal;

    cout << animal << endl;
    cout << refer << endl;

    animal = "cat";

    cout << "after change: " << endl;
    cout << animal << endl;
    cout << refer << endl;

    refer = "lion";

    cout << "after change: " << endl;
    cout << animal << endl;
    cout << refer << endl;

    ///POINTER///
    string* ptr = &animal;
    cout << "Pointer to animal: " << ptr << endl; //returns the address
    cout << "value of animal: " << *ptr << endl; //returns the value

    return 0;
}

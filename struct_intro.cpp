#include <iostream>

using namespace std;

int main()
{
    struct Person
    {
        string name;
        int age;
        char gender;
        float height;
        bool has_siblings;

        string siblings[5];
    };

    Person p1;

    p1.name = "Tania";
    p1.age = 17;
    p1.gender = 'F';
    p1.height = 160;
    p1.has_siblings = true;

    p1.siblings[0] = {"Aleks"}; ///to work the array it needs an adress

    cout << "Person 1 data: " << endl;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Gender: " << p1.gender << endl;
    cout << "Height: " << p1.height << endl;
    cout << "Has sibling: " << p1.has_siblings << endl;


    for(int i = 0; i < 1; i++)
    {
        cout << "Sibling's name: " << p1.siblings[i] << endl;
    }

    return 0;
}

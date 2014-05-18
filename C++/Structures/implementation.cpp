#include <iostream>
#include "header.h"
using namespace std;

void read(Person &p)
{
        cout << "Enter name" << endl;
        cin >> p.name;
        cout << "Enter age" << endl;
        cin >> p.age;
}

void write(const Person &p)
{
        cout << "Name: " << p.name << endl;
        cout << "Age: " << p.age << endl;
}


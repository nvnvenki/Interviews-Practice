#include <iostream>
#include <cstring>
#include "header.h"
using namespace std;

#if 0
Person::Person(char *s,int n):age(n)
{
        cout << "Called Person(char *,int)" << endl; 
        strcpy(name,s);
}

Person::Person():age(0)
{
        cout << age << endl;
        cout << "Called Person()" << endl; 
        name[0] = '\0';
}

Person::~Person()
{
        cout << "Destructor called" << endl; 
}
#endif


Person::Person(char *s,int n):age(n),name(new char[strlen(s) + 1])
{
        cout << "Called Person(char *,int)" << endl; 
        strcpy(name,s);
}

Person::Person():age(0),name(0)
{
        cout << "Called Person()" << endl; 
}

Person::~Person()
{
        cout << "Destructor called" << endl; 
}

Person::Person(const Person &other):name(new char[strlen(other.name) + 1]),age(other.age) // Copy constructor
{
        cout << "In Copy constructor" << endl; 
        strcpy(name,other.name);
}

Person& Person::operator=(const Person &other) // Overloaded assignment operator
{
        cout << "In assignment operator" << endl; 
        if(this == &other)
        {
                return *this;
        }
        delete []name;
        name = new char[strlen(other.name) + 1];
        strcpy(name,other.name);
        age = other.age;
        return *this;
}

void Person::read()
{
        char a[100];
        cout << "Enter the name and age" << endl;
        cin >> a >> age;
        delete []name;
        name = new char[strlen(a) + 1];
        strcpy(name,a);

}

void Person::write() const // Here 'const' syas the object through which the call is made is a constant
{
        cout << name << endl << age << endl;
}

void dosth(Person &p)
{
        p.age += 10;
}

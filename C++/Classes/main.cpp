#include <iostream>
#include "header.h"
using namespace std;

int main()
{
//        Person p;
//        p.read();
//        p.write();
//        cout << sizeof(p) << endl;
        Person p1("Venki",1);
//        p1.write();
//        Person p2(p1);
//        p2.write();
        Person p3;
        p3 = p1;
        p3.write();
        dosth(p3);
        p3.write();
        return 0;
}

#include <iostream>
#include "header.h"
using namespace std;

int main()
{
        queue q;
        q.add(10);
        q.add(20);
        cout << q.remove() << endl;
        return 0;
}

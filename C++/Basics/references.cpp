#include <iostream>
using namespace std;

void swap(int &a,int &b)
{
        int temp = a;
        a = b;
        b = temp;
}

int main()
{
        int a = 10;
        int b = 20;
        
        cout << "Before swapping" << endl;
        cout << "a: " << a << '\t' << "b: " << b  << endl;
        swap(a,b);

        cout << "After swapping" << endl; 
        cout << "a: " << a << '\t' << "b: " << b << endl;
        return 0;
}

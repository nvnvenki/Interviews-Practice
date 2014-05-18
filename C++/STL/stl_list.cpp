#include <iostream>
#include <list>
#include <numeric>
using namespace std;

void print(const list<int> &l)
{
        list<int>::const_iterator p; // list iterator
        for(p = l.begin(); p != l.end(); ++p)
        {
                cout << *p << '\t';
        }
        cout << endl;
}

int main()
{
        int a[] = {1, 7, 2, 9};
        list<int> l;
        for(int i = 0; i < 4; ++i)
        {
                l.push_front(a[i]); // generic method to push
        }
        print(l);
        l.sort();
        print(l);

        cout << "Sum is: " << accumulate(l.begin(),l.end(),0) << endl; // accumulate is a generic stl function in numeric package thaat uses 0 as an initial value & computes the sum from begin to end
        return 0;
}

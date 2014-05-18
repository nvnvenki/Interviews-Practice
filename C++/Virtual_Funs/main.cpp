#include <iostream>
using namespace std;

class A
{
        public:
#if 0
                void f()
                {
                        cout << "In base class" << endl; 
                }
#endif

                virtual void f()
                {
                        cout << "In base class" << endl; 
                }
};

class B: public A
{
        public:
                void f()
                {
                        cout << "In derived calss" << endl;
                }
};


int main()
{
        A oA,*pA;
        B oB,*pB;

        pA = &oA;
        pA -> f();

        pB = &oB;
        pB -> f();
        

        pA = &oB;
        pA -> f();
        
        return 0;
}

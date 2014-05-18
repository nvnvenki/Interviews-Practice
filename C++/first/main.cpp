//using namespace std;
#include <iostream>

int main()
{

        cout << "Devre olledu maadappa" << endl;
        cout << "Hello,World!" << endl;
        char name[10];
        cout << "Nin hesru helu" << endl;
        cin >> name;
        cout << "Hesru: " << name << endl;
        int *p = new int[5];
        for(int i = 0; i < 5; ++i)
        {
                p[i] = i * 2;
        }

        for(int i = 0; i < 5; ++i)
        {
                cout << p[i] << '\t';
        }
        cout  << endl;
        return 0;
}

#include <iostream>

class PrintMaadu
{
        private:
                static int i;
        public:
                PrintMaadu()
                {
                        std::cout  << i  << std::endl;
                        ++i;
                }

};

int PrintMaadu::i = 1;

int main()
{
        PrintMaadu printMaadute[100];
        return 0;
}

#include <stdio.h>

unsigned int swap(unsigned int n)
{
        unsigned int even_bits = n & 0xAAAAAAAA;
        unsigned int odd_bits = n & 0x55555555;

        even_bits >>= 1;
        odd_bits <<= 1;

        return (even_bits | odd_bits);
}

int main()
{
        unsigned int n = 2;
        printf("%u\n",swap(n));
        return 0;
}

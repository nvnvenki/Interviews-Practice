#include <stdio.h>
#include <stdlib.h>
#include "swap_odd.h"

int swap(int x)
{
	int odd_bits = x & 0x55555555;
	int even_bits = x & 0xAAAAAAAA;

	even_bits >>= 1;
	odd_bits <<=1 ;

	return (odd_bits | even_bits);
}
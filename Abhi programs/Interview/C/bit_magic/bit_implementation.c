s#include <stdio.h>
#include <stdlib.h>
#include "bit_magic.h"

int find_next_power(int n)
{
	int p = 1;

	// If n is a power of 2 already then return the number
	// If it is not then the number of bits that are used to represent the number is obtained
	// Then that number raised to the power of 2 is obtained and this is the number that is required


	if ( (n & (n-1)) == 0 )
	{
		return n;
	}

	while(p < n)
	{
		p <<= 1;
	}

	return p;
}


int is_multiple_3(int n)
{
	/*

	Algorithm

	1. Find the number of bits set in the odd position
	2. Find the number of bits set in the even position
	3. Then return the absolute value of the difference between the two
	4. If they have the same number of zeroes and ones then the number is a power of 3 else not

	*/

	int odd_count = 0;
	int even_count = 0;


	while(n)
	{
		if(n & 1)
		{
			even_count = even_count + 1;
		}
		n = n >>1;

		if(n & 1)
		{
			odd_count = odd_count + 1;
		}

		n = n >> 1;
	}

	return absolute(even_count - odd_count);
}


static int absolute(int n)
{
	if(n < 0)
	{
		return -n;
	}

	else
	{
		return n;
	}
}

int find_parity(int n)
{
	/*

	Algorithm
	1. Until the number is zero
			a. Change the parity
	 		b. Set the right most bit to 0

	*/

	int parity = 0;

	while(n)
	{
		parity = !parity;

		n = n & (n -1);
	}

	return parity;

}

int find_odd_occurence(int* array, int n)
{
	/*

	Algorithm
	1. Do xor of all the elements of the array
	2. The final result of xoring is the element we are interested in

	*/

	int i = 0;
	int res = 0;

	for(i = 0; i < n; i++ )
	{
		res = res ^ array[i];
	}


	return res;
}

void check_indian()
{
	unsigned int i = 1;
	char* c = (char*)&i;

	if(*c)
	{
		printf("Little endian \n");
	}

	else
	{
		printf("Big endian \n");
	}
}


int count_set_bits(int n)
{
	int count = 0;

	while(n)
	{
		n = n & (n-1);
		count++;
	}

	return count;
}

int left_rotate(int n, int d)
{
	return ( (n << d) | (n >> (64 -d)) );
}

int right_rotate(int n, int d)
{
	return ((n >> d) | ( n << (64 -d)));
}

int multiply_3_5(int n)
{
 	return ( (n << 3) - n ) >> 1;
}


int n_mod_d(int n, int d)
{
	return n & (d -1);
}

int add_one(int n)
{
	/*
		Algorithm:
		1. Till you find a zero from the rightmost positions unset all the set bits
		2. Then finally flip the rightmost 0 bit too

	*/

	int m = 1;

	while(n & m)
	{
		n = n ^ m;
		m = m << 1;
	}

	n = n ^ m;

	return n;
}

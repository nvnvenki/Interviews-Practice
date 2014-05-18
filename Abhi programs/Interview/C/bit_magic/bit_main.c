#include <stdio.h>
#include <stdlib.h>
#include "bit_magic.h"

int main()
{
	int choice;
	int n;
	int nextPowerOf2;
	int is_multiple3;
	int parity;
	int my_array[9] = {1,1,2,3,4,2,3,4,4};
	int countSetBits = 0;
	int leftRotate = 0;
	int d;
	int rightRotate = 0;
	int Multiply3Point5 = 0;
	int nModD = 0;


	while(1)
	{
			printf("-----------------------------------------------------------------------------------------------------------\n");
			printf("1. Find the next power of 2 \n");
			printf("2. Exit \n");
			printf("3. Find whether number is a multiple of 3 \n");
			printf("4. Find odd or even parity \n");
			printf("5. All the elements in the array occur even number of times and one occurs odd number of times. Find the odd occuring number \n");
			printf("6. Check whether the machine is little endian or big endian \n");
			printf("7. Count the number of set bits in a number \n");
			printf("8. Left rotate the bits of a number \n");
			printf("9. Right rotate the bits of a number \n");
			printf("10. Multiply a given number by 3.5 and dont use the division operation \n");
			printf("11. n mod d where d is a power of 2 and without using the modulus operation \n");
			printf("12. Add one to a number without using the arithmetic operators \n");
			printf("-----------------------------------------------------------------------------------------------------------\n");

			printf("Enter the choice \n");
			scanf("%d", &choice);

			switch(choice)
			{
				case 1:
						printf("Enter the number \n");
						scanf("%d", &n);
						nextPowerOf2 = find_next_power(n);
						printf("The next power of 2 of the given number is %d \n", nextPowerOf2);
						break;

				case 2:
						exit(1);

				case 3:
						printf("Enter the number \n");
						scanf("%d", &n);
						is_multiple3 = is_multiple_3(n);

						if(is_multiple3)
						{
							printf("The number is not a mutliple of 3 \n");
						}

						else
						{
							printf("The number is a mutiple of 3 \n");
						}

						break;

				case 4:
						printf("Enter the number \n");
						scanf("%d", &n);
						parity = find_parity(n);

						if(parity)
						{
							printf("The number has odd parity \n");
						}

						else
						{
							printf("The number has even parity \n");
						}

						break;

				case 5:

						n = find_odd_occurence(my_array,9);
						printf("The element that occurs odd number of times in the array is %d \n",n);
						break;

				case 6:
						check_indian();
						break;

				case 7:
						printf("Enter the number \n");
						scanf("%d", &n);
						countSetBits = count_set_bits(n);
						printf("The number of bits which are set is/are %d \n",countSetBits);
						break;

				case 8:
						printf("Enter the number \n");
						scanf("%d",&n);
						printf("Enter the rotation number \n");
						scanf("%d", &d);
						leftRotate = left_rotate(n,d);
						printf("The left roatated number is %d \n",leftRotate);
						break;

				case 9:
						printf("Enter the number \n");
						scanf("%d", &n);
						printf("Enter the rotation number \n");
						scanf("%d", &d);
						rightRotate = right_rotate(n,d);
						printf("The right rotated number is %d \n", rightRotate);
						break;

				case 10:
						printf("Enter the number \n");
						scanf("%d", &n);
						Multiply3Point5 = multiply_3_5(n);
						printf("The number wehn multiplied by 3.5 is %d \n",Multiply3Point5);
						break;

				case 11:
						printf("Enter a number \n");
						scanf("%d",&n);
						printf("Enter a power of 2 \n");
						scanf("%d", &d);
						nModD = n_mod_d(n,d);
						printf("The result is %d \n",nModD);
						break;

				case 12:
						printf("Enter a number \n");
						scanf("%d",&n);
						printf("The number after adding one is %d \n",add_one(n));
						break;


				
				default:

						break;

			}

	}
}

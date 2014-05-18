#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

int main()
{
	int choice;
	int max_index = 0;
	char string[] = "testing times and you have to be on top of your game";
	char* result = "";
	char my_string[] = "geekforgeeks";
	char a[] = "abc";
	int n;
	int index = 0;
	char* list[] = {"geekforgeeks","utensils","sunday"};
	char word[] = "sun";
	char run[] = "wwwwwaabbccddddeee";
	char* runEncoded;
	char pattern[] = "geeks";

	while(1)
	{
		printf("-----------------------------------------------------------------------------------------------------------\n");
		printf("1. Find the character occuring the maximum number of times in a string \n");
		printf("2. Exit \n");
		printf("3. Remove all duplicates from a string \n");
		printf("4. Print all the characters that have duplicates in the string \n");
		printf("5. Remove all the occurences of the characters in the second string from the first string \n");
		printf("6. Print a string recursively in the reverse order \n");
		printf("7. Print the permutations of the given string \n");
		printf("8. Divide the string into n equal parts \n");
		printf("9. Find the strings first non repeating character \n");
		printf("10. Print the strings that contain all the characters of the given word \n");
		printf("11. Given a sentence print the words in reverse \n");
		printf("12. Run length encoding of the given string \n");
		printf("13. Naive pattern searching algorithm \n");
		printf("14. Reverse a string \n");
		printf("15. Remove duplicates from the string without using additional space \n");
		printf("16. Replace the space with percent 20 \n");
		printf("-----------------------------------------------------------------------------------------------------------\n");

		printf("Enter a choice \n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
					max_index = getMaximumCount(string);
					printf("%c \n", max_index);
					break;

			case 2:
					exit(1);


			case 3:
					printf("The string after removing all the duplicates is %s \n",removeDuplicates(my_string));
					break;

			case 4:
					printDuplicates(my_string);
					break;

			case 5:
					printf("The masked string is %s \n",maskString(string, my_string));
					break;

			case 6:
					printReverseRecursively(string);
					printf("\n");

			case 7:
					permute(a,0,2);
					break;

			case 8:
					printf("Enter the value of n \n");
					scanf("%d", &n);
					divideToNParts(my_string, n);
					break;

			case 9:
					index = firstNonRepeatingCharacter(my_string);
					if(index == -1)
					{
						printf("There is no non repeating character.. every character is repeated atleast once \n");

					}

					else
					{
						printf("The character that is repeated is %c \n", my_string[index]);
					}

					break;

			case 10:
						printWords(list,word,3);
						break;

			case 11:
						printSentenceReverse(string);
						break;

			case 12:
						runEncoded = runLengthEncode(run);
						printf("Run encoded string of %s is %s \n",run,runEncoded);
						break;

			case 13:
						index = naivePatternSearch(my_string, pattern);

						if(index == -1)
						{
							printf("The pattern is not found in the string \n");
						}

						else
						{
							printf("The pattern is found at the position %d \n", index);
						}

						break;

			case 14:
						reverse(my_string);
						printf("The string after reversing is %s \n",my_string);
						break;

			case 15:
						removeDuplicatesWithoutAdditionalSpace(my_string);
						printf("The string after removing the duplicates is %s \n", my_string);
						break;

			case 16:
						replaceSpace(string);
						printf("The string after replacing all the spaces with percent 20 is %s \n",string);
						break;


			default:
					break;


		}

	}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"

int getMaximumCount(char* string)
{
	int* count = (int *)calloc(256, sizeof(int));
	int i = 0;
	int max_index = 0;

	for(i = 0 ; *(string + i); i++)
	{
		count[*(string + i)]++;
	}

	for(i = 1; i < 256; i++)
	{
		if(count[i] > count[max_index])
		{
			max_index = i;
		}
	}
	return max_index;
}	


char* removeDuplicates(char* string)
{
	/*

	Algortihm
		1. First make a boolean bool_array
		2. When you encounter a character check the boolean array and if the character is not encountered then set 1 in the boolean array and add that character to the string that is getting built in place
		3. Else dont do anything..check for the next character

	*/

	int bool_array[256] = {0};
	int i = 0;
	int end = 0;
	char temp;

	while(*(string + i))
	{
		temp = *(string + i);
		if(bool_array[temp] == 0)
		{
			bool_array[temp] = 1;
			*(string + end) = *(string + i);
			end++;
		}
		i++;
	}

	*(string + end) = '\0';
	printf("The string is %s \n",string);
	return string;

}


void printDuplicates(char* string)
{
	int* count = (int*)calloc(256, sizeof(int));
	int i  = 0;

	while(*(string + i))
	{
		count[*(string + i)]++;
		i++;
	}

	for(i = 0; i < 256; i++)
	{
		if(count[i] > 1)
		{
			printf("%c \n",i);
		}
	}

}

char* maskString(char* string1, char* string2)
{
	int* count = (int*)calloc(256, sizeof(int));
	int i = 0;
	int end = 0;

	while( *(string2+i) )
	{
		if(count[ *(string2 + i) ] == 0)
		{
			count[ *(string2 + i) ] = 1;
		}
		i++;
	}

	i = 0;

	while( *(string1 + i) )
	{
		char temp = *(string1 + i);

		if(count[ temp])
		{
			*(string1 + end) = *(string1 + i);
			end++;

		}


		i++;
	}

	*(string1 + end) = '\0';
	return string1;
}

void printReverseRecursively(char* string)
{
	if(*string)
	{
		printReverseRecursively(string + 1);
		printf("%c",*string);
	}
}


void permute(char* string, int start, int end)
{
	int j;

	if(start == end)
	{
		printf("%s \n", string);
	}

	else
	{
		for(j = start ; j <= end; j++)
		{
			swap((string + start), (string + j));
			permute(string, start + 1, end);
			swap((string + start), (string + j));

		}
	}

}

static void swap(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void divideToNParts(char* string, int n)
{
	int str_len = strlen(string);
	int part_size = str_len / n;
	int i = 0;

	for(i = 0; i < str_len; i++)
	{
		if((i % part_size) == 0)
		{
			printf("\n");
		}
		printf("%c",string[i]);

	}
	printf("\n");

}

int firstNonRepeatingCharacter(char* string)
{
	int* count = (int *)calloc(256, sizeof(int));
	int i = 0;
	int index = -1;
	int j = 0;

	while(*(string + i))
	{
		count[*(string + i)]++;
		i++;
	}

	while(*(string + j))
	{
		if(count[*(string + j)] == 1)
		{
			index = j;
			break;
		}
		j++;
	}

	return index;

}

void printWords(char* list[], char* word, int listSize)
{
	int i = 0;
	int* map = (int *)calloc(256, sizeof(int));
	int j = 0;
	int count;
	int wordSize = strlen(word);

	while(*(word + i))
	{
		map[*(word + i)]++;
		i++;
	}

	for(i = 0; i < listSize; i++)
	{
		count = 0;

		for(j = 0; *(list[i] + j); j++)
		{
			if( map[*( list[i] + j) ] )
			{
				count ++;

				map[*( list[i] + j )] = 0;
			}
		}

		if(count == wordSize )
		{
			printf("%s \n",list[i]);
		}

		for(j = 0; *(word + j); j++)
		{
			map[*(word + j)]++;
		}
	}
}

void printSentenceReverse(char* string)
{
	char list_words[1000][1000];
	int i = 0;
	int j = 0;
	int k = 0;

	while(*(string + j))
	{


		if(*(string + j) == ' ')
		{
			list_words[k][i] = '\0';
			k++;
			i = 0;

		}

		else
		{
			list_words[k][i++] = *(string + j);
		}

		j++;
	}

	for(i = k; i >= 0; i--)
	{
		printf("%s ",list_words[i]);
	}
	printf("\n");


	
}

char* runLengthEncode(char* string)
{
	int length = strlen(string);
	char* destination = (char*)malloc( sizeof((char*)(2*length + 1)) );
	int i = 0;
	int j = 0;
	int count = 0;

	for(i = 0; i < length; i++)
	{
		destination[j++] = string[i];
		count = 1;

		while( (i + 1) < length && (string[i] == string[i+1]))
		{
			count++;
			i++;
		}

		destination[j++] = 48 + count;

	}

	destination[j] = '\0';
	return destination;
}

int naivePatternSearch(char* string, char* pattern)
{
	int index = -1;
	int i = 0;
	int j = 0;
	int str_len = strlen(string);
	int pat_len = strlen(pattern);

	while(i < str_len - pat_len + 1)
	{
		for(j = 0 ; j < pat_len ; j++)
		{
			if(string[i+j] != pattern[j])
			{
				break;
			}
		}

		if(j == pat_len)
		{
			index = i;
			return index;
		}

		i += 1;
	}

	return -1;

}

void reverse(char* string)
{
	int len = strlen(string);
	int i = 0;

	for(i = 0; i < (len /2); i++)
	{
		char temp = string[i];
		string[i] = string[len - 1 - i];
		string[len - 1 - i] = temp;
	}
}

void removeDuplicatesWithoutAdditionalSpace(char* string)
{
	//but the string contains a run of duplicate characters only and with discontinuous duplicates the problem needs additional space
	int len = strlen(string);
	int start = 0;
	int end = len -1;
	int tail = start;
	int i = 0;

	while(start != end)
	{
		for(i = start + 1; i <= end; i++)
		{
			if( !( string[i] == string[start] ))
			{
				string[++tail] = string[i];
			}
		}

		end = tail;
		start++;
		tail = start;
	}

	string[++start] = '\0';

}

void replaceSpace(char* string)
{
	//They have given a space efficient solution in cracking the coding interview..doing that now
	int number_of_spaces = 0;
	int i = 0;

	while(*(string + i))
	{

		if(*(string + i) == ' ')
		{
			number_of_spaces++;
		}

		i++;
	}

	int length = strlen(string);
	int new_length = length + (number_of_spaces * 2);
	string[new_length] = '\0';

	for(i = length - 1; i >= 0; --i)
	{
			if(string[i] == ' ')
			{
				string[new_length - 1] = '%';
				string[new_length - 2] = '0';
				string[new_length - 3] = '2';
				new_length -= 3;
			}

			else
			{
				string[new_length - 1] = string[i];
				new_length -= 1;
			}
	}
}
#include <time.h>
#include <stdio.h>

int main()
{
	time_t biggest = 0x7FFFFFFF;

	// ctime gives the time according to the current locale
	printf("the biggest = %s \n",ctime(&biggest));


	/*to give the Greenwhich mean time use gtime
	but this returns a structure, to convert it into user readable use asctime*/

	printf("The actual biggest time is: %s \n",asctime(gmtime(&biggest)));
	return 0;
}
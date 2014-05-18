#include <stdio.h>

int main()
{
	char* p = "abhinav";
	const char* my_name = "";

	my_name = p;

	printf("My name is: %s \n",my_name);
}


// char* matches const char*

// This happens because of a rule in the standards
// left side..operand (const char* my_name) is a pointer to a character and has a qualifier const
// right side..operand (char* p) is a pointer to a character and is unqualified
// both are character pointers
// left hand side has all the qualifiers that the right side operand has


//try p = my_name and compiler generates a warning

// but char** doesnt match const char**
// strange???
// why??
// const char* is a pointer to a character qualified by a const
// but const char** is a pointer to a pointer of qualified type and thus is unqualified
// so is char**
// hence assigning one to another is not allowed



// AMAAZING POINT
// Consider a pointer p which points to a pointer -> pointing to a charcter which is const qualified
// Consider a pointer q which points to a pointer-> pointing to a character that is not qualified
// Although p and q are compatible what they point to are incompatible and hence assignment and function call is not allowed


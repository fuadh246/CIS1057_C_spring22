#include <stdio.h>
#include <string.h>

#define CLEAR 1

/*
	This source code demonstrates strings and related functions in c.
*/

void toUpper(char s[]);
int strLen(char s[]);
void strCat(char dest[], char src[]);
void strCpy(char dest[], char src[]);


int main(){

	// Iterators
	int i = 0;
	int j = 0;
	// Char to wait on
	char c;
	// File pointers
	FILE *file_in;
	FILE *file_out;

	// A srting in c is an array of char
	// hello is a pointer and points to "Hello World!" in memory
	char hello[] = {"Hello World!"};

	// Print char array with loop
	printf("Print a char array with a loop\n");
	for(i=0; i<12; i++)
		printf("%c ", hello[i]);
	printf("\n\n");
	//hello[12] = 'a';
	// Print array as a string
	printf("Print a char array as a string\n");
	printf("%s\n\n", hello);

	// An array of strings is an array of pointers
	char month[12][10] = {"January", "February", "March", "April", "May", "June",
				"July", "August", "September", "October", "November", "December"};

	// Print months
	printf("Print months\n");
	for(i=0; i<12; i++)
		printf("%s\n", month[i]);
	printf("\n");

	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");

	// Must use String library functions to manipulate strings
	// or write your own char-by-char functions
	// ***** Warn about overflow errors
	char aString[100];
	// Can't assign a aString = "Hello again!!!";
	// Must copy chars using strcpy()
	printf("Can't assign a aString = \"Hello again!!!\"\n");
	printf("Must use String library functions to manipulate strings\n");
	printf("   or write your own char-by-char functions\n\n");

	// Use strcpy()
	printf("Using strcpy() to copy \"Hello again!!!\"\n");
	// Copy string to aString
	strcpy(aString, "Hello again!!!");
	printf("aString  = |%s|\n\n", aString);

	// Use strncpy() to copy first n chars
	char bString[100];
	size_t n = 5; // Set n to 5 - size_t is an unsigned int
	printf("Copy first n = %d chars with strncpy()\n", n);
	// Copy first n chars to bString
	strncpy(bString, aString, n);
	// Append a null char to end of string
	//bString[n] = '\0';
	printf("bString  = |%s|\n\n", bString);

	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");

	// Concatenate strings
	n = 10;
	printf("Concatenate some strings\n\n");
	// Show initial aString
	printf("aString  = |%s|\n\n", aString);
	printf("Concatenate \" and again and again ...\" into aString using strcat()\n\n");
	// Concatenate string literal to end of aString
	strcat(aString, " and again and again ...");
	printf("aString  = |%s|\n\n", aString);
	printf("Concatenate first %d elements of \" and again and again ...\" \ninto aString using strncat()\n\n", n);
	// Concatenate first n elements of string literal to end of aString
	strncat(aString, " and again and again ...", n);
	printf("aString  = |%s|\n\n", aString);

	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");

	// Compare strings
	printf("Compare strings with strcmp()\n\n");
	strcpy(aString, "Bob");
	strcpy(bString, "bob");

	// Use strcmp() do compare strings
	// Returns -1 if aString is less than bString
	// Returns 0 if aString is equal to bString
	// Returns 1 if aString is greater than bString
	int b = strcmp(aString, bString);
	// Ask if strings are equal
	printf("Is %s equal to %s = %d\n\n", aString, bString, !b);
	// Ask if aString is less than bString
	printf("Is %s less than %s = %d (-1 means yes)\n\n", aString, bString, b);


	// Get the length of a string
	printf("Get the length of aString = %s\n", aString);
	b = strlen(aString);
	printf("%s is %d chars long\n\n", aString, b);

	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");


	// Tokenize a string
	printf("Use strtok() to tokenize a string\n\n");
	char *last, *first, *middle;
	strcpy(aString, "Adams, John Quincy");
	strcpy(bString, aString);
	last = strtok(bString, ", ");
	// Remember that strtok uses the original string as working
	// space and storage for the string pointers
	//printf("bString = %s\n", bString);
	first = strtok(NULL, ", ");
	middle = strtok(NULL, ", ");

	printf("Original string: %s\n", aString);
	printf("Rewritten as: %s %s %s\n\n", first, middle, last);

	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");


	return 0;
}

















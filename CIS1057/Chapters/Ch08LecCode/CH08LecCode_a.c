// Searching and sorting strings

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

#define CLEAR 1

// Basic string function prototypes
void toUpper(char s[]);
int strLen(char s[]);
void strCat(char dest[], char src[]);
void strCpy(char dest[], char src[]);
int strCmp(char s[], char t[]);
int strCmpIgnoreCase(char s[], char t[]);
int strEql(char s[], char t[]);
int strEqlIgnoreCase(char s[], char t[]);


// String array function prototypes
void print(char *list[], int count);
void print2(char *list[], int count);
int find(char *list[], int count, char *str);
void swap(char *list[], int i, int j);
void sort(char *list[], int count);

int main(){
	
	// Declare and initialize an array of pointers to strings
	// This is different from the momths example
	// Each string uses only enough bytes to store chars in string
	char *list[] = {"Sue", "Mat", "Bob", "Lilly", "Patty", "Mike", "Mary", "Dave", "Abby", "Patrick"};
	// Count of elements in list
	int count = 10;
	// Strings
	char aString[100];
	char bString[100];
	// Index or iterator
	int i = 0;
	char c;
	
	// Clear screen
	system("cls");
	
	// Write toUpper function
	printf("Use custom toUpper to convert a string to upper case\n\n");
	strcpy(aString, "AbCdEf");
	printf("aString = %s\n", aString);
	toUpper(aString);
	printf("aString = %s\n\n", aString);
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Use custon strLen()
	printf("Use custom strLen to count chars in a string\n\n");
	printf("aString = %s has %d chars\n\n", aString, strLen(aString));
	
	// Use custom strCpy()
	printf("Use custom strCpy to copy a string\n\n");
	strCpy(aString, "AbCdEf");
	printf("aString = %s\n", aString);
	strcpy(bString, "EfGhIj");
	printf("bString = %s\n\n", bString);
	
	// Use custom strCat()
	printf("Use custom strCat to concatenate strings\n\n");
	strCat(aString, bString);
	printf("aString = %s\n\n", aString);
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Use custom strCmp()
	printf("Use custom strCmp to compare strings\n\n");
	strCpy(aString, "AbCdEf");
	strcpy(bString, "EfGhIj");
	i = strCmp(aString, bString);
	printf("%s is %d compared to %s\n\n", aString, i, bString);
	i = strCmp(bString, aString);
	printf("%s is %d compared to %s\n\n", bString, i, aString);
	strCpy(bString, "AbCdEf");
	i = strCmp(aString, bString);
	printf("%s is %d compared to %s\n\n", aString, i, bString);
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Use custom strCmpIgnoreCase()
	printf("Use custom strCmp to compare strings\n\n");
	strCpy(aString, "AbCdEf");
	strcpy(bString, "ABCDEF");
	i = strCmp(aString, bString);
	printf("%s is %d compared to %s with strCmp()\n\n", aString, i, bString);
	printf("Use custom strCmpIgnoreCase to compare strings\n\n");
	i = strCmpIgnoreCase(aString, bString);
	printf("%s is %d compared to %s with strCmpIgnoreCase()\n\n", aString, i, bString);
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Use custom strEql
	printf("Test strings for equality using custom functions\n\n");
	printf("aString = %s\n", aString);
	printf("bString = %s\n\n", bString);
	printf("Use custom strEql to compare strings\n\n");
	i = strEql(aString, bString);
	if(i)
		printf("The strings %s and %s are equal with strEql (%d).\n\n", aString, bString, i);
	else
		printf("The strings %s and %s are NOT equal with strEql (%d).\n\n", aString, bString, i);
	
	
	// Use custom strEqlIgnoreCase
	printf("Use custom strEqlIgnoreCase to compare strings\n\n");
	i = strEqlIgnoreCase(aString, bString);
	if(i)
		printf("The strings %s and %s are equal with strEqlIgnoreCase (%d).\n\n", aString, bString, i);
	else
		printf("The strings %s and %s are NOT equal with strEqlIgnoreCase (%d).\n\n", aString, bString, i);
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Character operations
	// C has various char operations in the ctype.h library
	// to modify and test chars;
	printf("Character operations from ctype\n\n");
	c = 'a';
	printf("Is %c alphabet char = %d or a digit = %d\n", c, isalpha(c), isdigit(c));
	printf("Ts %c lower case = %d or upper case = %d\n", c, islower(c), isupper(c));
	printf("Is %c a punctuation = %d or a space = %d\n\n", c, ispunct(c), isspace(c));
	c = 'Z';
	printf("Is %c alphabet char = %d or a digit = %d\n", c, isalpha(c), isdigit(c));
	printf("Ts %c lower case = %d or upper case = %d\n", c, islower(c), isupper(c));
	printf("Is %c a punctuation = %d or a space = %d\n\n", c, ispunct(c), isspace(c));
	c = ' ';
	printf("Is %c alphabet char = %d or a digit = %d\n", c, isalpha(c), isdigit(c));
	printf("Ts %c lower case = %d or upper case = %d\n", c, islower(c), isupper(c));
	printf("Is %c a punctuation = %d or a space = %d\n\n", c, ispunct(c), isspace(c));
	c = 's';
	printf("%c as upper case is %c\n", c, toupper(c));
	c = 'T';
	printf("%c as lower case is %c\n\n", c, tolower(c));
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Function to only accept char keypresses
	printf("Only accept char keypresses\n\n");
	getKeys(aString);
	system("cls");
	printf("Only accept char keypresses\n\n");
	printf("The string is %s\n\n", aString);
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// String to number conversions
	printf("Convert strings to numbers\n\n");
	strCpy(aString, "100");
	i = atoi(aString);
	printf("The int value of \"%s\" is %d\n\n", aString, i);
	strCpy(aString, "12.56");
	float f = strtod(aString ,NULL); //atof(aString);
	printf("The float value of \"%s\" is %f\n\n", aString, f);
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	

	// Number to string conversions
	printf("Use sprintf to convert numbers to strings\n\n");
	i = 10;
	f = 25.5;
	printf("The numeric values are %d and %f\n\n", i, f);
	sprintf(aString, "Int: %d Float: %f", i, f);
	printf("aString is : %s\n\n", aString);
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Print an array of strings
	printf("Print an array of strings\n\n");
	print(list, count);
	printf("\n");
	
	
	// Use find function to determine if "Mike" is in array
	strcpy(aString, "Mike");
	printf("Is %s in array?\n", aString);
	i = find(list, count, aString);
	if(i >= 0)
		printf("Found %s at index %d\n", list[i], i);
	else
		printf("%s not found\n", aString);
	printf("\n");
	
	// Use find function to determine if "Mack" is in array
	strcpy(aString, "Mack");
	printf("Is %s in array?\n", aString);
	i = find(list, count, aString);
	if(i >= 0)
		printf("Found %s at index %d\n", list[i], i);
	else
		printf("%s not found\n", aString);
	printf("\n");
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Sort array lexicographically
	printf("Sort an array of strings\n\n");
	// Print unsorted array
	printf("The unsorted array.\n");
	print2(list, count);
	printf("\n");
	sort(list, count);
	// Print sorted array
	printf("The unsorted array.\n");
	print2(list, count);
	printf("\n");
	
	// Wait for keypress
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	return 0;
}


// Print an array of pointers to strings to screen
void print(char *list[], int count){
	int i = 0;
	for(i=0; i<count; i++)
		printf("%s\n", list[i]);
}


// Print an array of pointers to strings to screen
void print2(char *list[], int count){
	int i = 0;
	for(i=0; i<count; i++)
		printf("%s ", list[i]);
	printf("\n");
}


// Find a string in an array of pointers to strings
int find(char *list[], int count, char *str){
	int i = 0;
	for(i=0; i<count; i++)
		if(strcmp(list[i], str) == 0)
			return i;
	return -1;
}


// Sort an array of pointers to strings
void sort(char *list[], int count){
	int i = 0;
	int j = 0;
	int min = 0;
	
	for(i=0; i<count-1; i++){
		min = i;
		for(j=i+1; j<count; j++)
			if(strcmp(list[j], list[min]) < 0)
				min = j;
		swap(list, i, min);
	}

	return;
}


// Swap the addresses of two pointers to strings
void swap(char *list[], int i, int j){
	char *temp = list[i];
	list[i] = list[j];
	list[j] = temp;
	return;
}


// Convert all lower case char to upper case
void toUpper(char s[]){
	int i = 0;
	for(i=0; i<strlen(s); i++)
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	return;
}


// Find the length of a string
int strLen(char s[]){
	int i = 0;
	while(s[i] != '\0')
		i++;
	return i;
}



// Copy one string to another
void strCpy(char dest[], char src[]){
	int i = 0;
	while(src[i] != '\0')
		dest[i] = src[i++];
	dest[i] = '\0';
	return;
}



// Concatinate two strings
void strCat(char dest[], char src[]){
	int i = strLen(dest);
	int j = 0;
	while(src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return;
}



// Compare two strings
int strCmp(char s[], char t[]){
	int i = 0;
	while(s[i] != '\0' && t[i] != '\0'){
		if(s[i] < t[i])
			return -1;
		else if(s[i] > t[i])
			return 1;
		else
			i++;
	}
	if(s[i] != '\0')
		return 1;
	else if(t[i] != '\0')
		return -1;
	return 0;
}


// Compare two strings ignoring case
int strCmpIgnoreCase(char s[], char t[]){
	int i = 0;
	char a, b;
	while(s[i] != '\0' && t[i] != '\0'){
		a = toupper(s[i]);
		b = toupper(t[i]);
		if(a < b)
			return -1;
		else if(a > b)
			return 1;
		else
			i++;
	}
	if(s[i] != '\0')
		return 1;
	else if(t[i] != '\0')
		return -1;
	return 0;
}


// Are two strings equal
int strEql(char s[], char t[]){
	int i = 0;
	while(s[i] != '\0' && t[i] != '\0'){
		if(s[i] != t[i])
			return 0;
		i++;
	}
	if(s[i] != '\0')
		return 0;
	else if(t[i] != '\0')
		return 0;
	return 1;
}


// Are two strings equal ignoring case
int strEqlIgnoreCase(char s[], char t[]){
	int i = 0;
	char a, b;
	while(s[i] != '\0' && t[i] != '\0'){
		a = toupper(s[i]);
		b = toupper(t[i]);
		if(a != b)
			return 0;
		i++;
	}
	if(s[i] != '\0')
		return 0;
	else if(t[i] != '\0')
		return 0;
	return 1;
}


// Get only alpha char input
int getKeys(char aString[]){
	int i = 0;
	char c = '\0';
	aString[i] = '\0';
	while(c != '\r'){
		system("cls");
		printf("Enter a string (alpha chars only): %s", aString);
		c = getch();
		if(isalpha(c)){
			aString[i] = c;
			i++;
			aString[i] = '\0';
		}
	}
	return i;
}









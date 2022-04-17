#include <stdio.h>		// Include library for standard input and output
#include <math.h>		// Include library for math
#include <limits.h>		// Include library with data type limits
#include <float.h>		// Include library with float limits

#define PI 3.14159		// Define PI as a constant
#define ADD(a,b)(a+b)	// Define a macro to add two numbers

void intToBin(int, char[]);		// Prototype for int to binary conversion

// This is a single line comment

/*
	This
	is
	a
	multi-line
	comment
*/

// The main function is the entry point for the program
// There are three ways to declare a main function
//int main(){
//int main(void){
int main(int argc, char *argv[]){
	
	// Declare some variables
	int i=0, j=0, k=0;			// Some integers: i, j, and k are usually used as iterators
	double d = 0.0;				// Double for calculations
	char aChar = '\0';			// Declare an 8-bit ASCII character value
	short aShort = 0;			// Declare a 16-bit short
	unsigned short uShort = 0;	// Declare a 16-bit unsigned short
	int anInt = 0;				// Declare a 32-bit integer
	unsigned int uInt = 0;		// Declare an unsigned 32-bit integer
	float aFloat = 0.0;			// Declare a 32-bit floating point number
	double aDouble = 0.0;		// Declare a 64-bit floating point number
	char bin[33];				// To contain a 32-byte binary string
	char aString[50];			// Declare a string to contain 49 chars and a NULL
	char buffer[100];			// String buffer for sprintf
	char first, middle, last;	// To store initials
	//const double PI = 3.14159;// Another way to declare a constant
	
	// Print "Hello World!" to screen
	printf("Hello World!\n");
	
	// Print command line args to screen
	for(i=0; i<argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	
	// Convert a string to a integer
	if(argc >= 3){
		i = atoi(argv[2]);
		printf("The integer value of argv[2] is %d\n\n", i);
	}
	
	// Assign values to data and print to screen with formatting
	// A character
	aChar = 'A';
	printf("The value of the char is: \'%c\'\n\n", aChar);
	
	// Some shorts - note that signed numbers are %d and unsigned are %u
	aShort = SHRT_MIN;
	printf("The min value of a short is: %16d\n", aShort);
	aShort = SHRT_MAX;
	printf("The max value of a short is: %16d\n", aShort);
	uShort = USHRT_MAX;
	printf("The max value of an unsigned short is: %6u\n\n", uShort);
	
	// Some integers - note that signed numbers are %d and unsigned are %u
	anInt = INT_MIN;
	printf("The min value of an int is: %22d\n", anInt);
	anInt = INT_MAX;
	printf("The max value of an int is: %22d\n", anInt);
	uInt = UINT_MAX;
	printf("The max value of an unsigned int is: %13u\n\n", uInt);
	
	// Some floats - note that %e is scientific and %f is floating point
	aFloat = FLT_MIN;
	printf("The min value of a float is: %24e\n", aFloat);
	printf("The min value of a float is: %25.44f\n", aFloat);
	aFloat = FLT_MAX;
	printf("The max value of a float is: %24e\n", aFloat);
	printf("The max value of a float is: %25f\n\n", aFloat);
	
	// Some doubles - note that %e is scientific and %f is floating point
	aDouble = DBL_MIN;
	printf("The min value of a double is: %23e\n", aDouble);
	printf("The min value of a double is: %1.330f\n", aDouble);
	aDouble = DBL_MAX;
	printf("The max value of a double is: %23e\n", aDouble);
	printf("The max value of a double is: %25f\n\n", aDouble);

	// Some math expressions with limit values
	aShort = 4567;
	anInt = 1234567;
	// This stores addition of a short and an int in a float
	aFloat = aShort + anInt;
	printf("%d + %d = %f\n", aShort, anInt, aFloat);
	aFloat = 987654.321;
	// This stores addition of a short an int and a float in a double
	aDouble = aShort + anInt + aFloat;
	printf("%d + %d + %f = %f\n", aShort, anInt, aFloat, aDouble);
	// This stores addition of a float and an int in a double
	anInt = aFloat + aDouble;
	printf("%f + %f = %d\n", aFloat, aDouble, anInt);
	// This overflows the int
	anInt = aFloat * aDouble;
	printf("%f * %f = %d\n", aFloat, aDouble, anInt);
	// Add 1 to the max for an int - overflow warning
	anInt = INT_MAX + 1;
	printf("(INT_MAX) %d + 1 = %d\n", INT_MAX, anInt);
	aFloat = FLT_MAX + 1.0;
	printf("(FLT_MAX) %f + 1.0 = %f\n", FLT_MAX, aFloat);
	if(aFloat == FLT_MAX)
		printf("The values FLT_MAX and FLT_MAX+1 are the same\n\n");
	
	// Calculate area and circumference of a circle
	aFloat = 2.5;			// Store radius in a float
	// Calculate area of a circle
	aDouble = PI * aFloat * aFloat;
	printf("The area of a circle with a radius %f is %f\n", aFloat, aDouble);
	// Calculate circumference
	aDouble = 2.0 * PI * aFloat;
	printf("The circumference of a circle with a radius %f is %f\n\n", aFloat, aDouble);
	
	// Calculate 
	
	// Convert int to binary
	intToBin(16, bin);
	printf("16 in binary is %s\n", bin);
	intToBin(INT_MAX, bin);
	printf("INT_MAX in binary is %s\n", bin);
	intToBin((INT_MAX+1), bin);
	printf("INT_MAX+1 in binary is %s\n\n", bin);
	
	// Casting datatypes
	// Find the integer portion of a double
	anInt = (int)aDouble;
	printf("The integer portion of %f is %d\n", aDouble, anInt);
	// Find the fractional part of a double
	d = aDouble - ((int)aDouble);
	printf("The fractional portion of %f is %f\n\n", aDouble, d);
	
    // Operator precedence
    // First unary: +, -, !, ++ and --
    // Second:      *, / and %
    // Third:       + and  -
    // Last:        =
    anInt = 10;
    aShort = 20;
    aFloat = 5;
    aDouble = anInt + aShort * aFloat;
    printf("%d + %d * %f = %f\n", anInt, aShort, aFloat, aDouble);
    // Parenthesis override precedence
    aDouble = (anInt + aShort) * aFloat;
    printf("(%d + %d) * %f = %f\n", anInt, aShort, aFloat, aDouble);
    // parenthesis are useful for division
    aDouble = (anInt + aShort) / aFloat;
    printf("(%d + %d) / %f = %f\n\n", anInt, aShort, aFloat, aDouble);        
        
    // Specialized assignment statements
    // b = b + a; can be abbreviated to b += a;
    aDouble = 25;
    aDouble = aDouble + aFloat;
    printf("%f + %f = %f\n", aDouble, aFloat, aDouble);
    aDouble += aFloat;
    printf("%f += %f -> %f\n\n", aDouble, aFloat, aDouble);
	
	// Increment and decrement operators
	i = 0;
	j = 5;
	// Increment j before addition
	k = i + (++j);
	printf("For k = i + (++j): i=%d j=%d k=%d\n", i, j, k); // k is 6 and j is 6
	
	i = 0;
	j = 5;
	// Increment j after addition
	k = i + (j++);
	printf("For k = i + (j++): i=%d j=%d k=%d\n\n", i, j, k); // k is 5 and j is 6
	
	// Show input buffer example from book
	// Get an integer
	printf("Enter an integer: ");
	scanf("%d", &anInt);
	printf("You entered %d\n", anInt);
	
	// Get 3 chars
	printf("Enter your initials: ");
	scanf("%c%c%c", &first, &middle, &last);
	printf("You entered %c%c%c\n", first, middle, last);
	
	// Get 3 chars
	printf("Enter your initials: ");
	scanf("%c", &last);
	printf("The last scanf missed the %c\n", last);
	
	// To fix, flush the buffer;
	// Get an integer
	printf("Enter an integer: ");
	scanf("%d", &anInt);
	printf("You entered %d\n", anInt);
	
	fflush(stdin);
	
	// Get 3 chars
	printf("Enter your initials: ");
	scanf("%c%c%c", &first, &middle, &last);
	printf("You entered %c%c%c\n", first, middle, last);
	
	
	// Get data from user
	// Get user's name
	printf("Enter your name: ");
	scanf("%s", aString);
	printf("You entered %s\n", aString);
	
	// Get user's age
	printf("Enter your age: ");
	scanf("%d", &anInt);
	printf("You entered %d\n", anInt);
	
	// Get user's money
	printf("Enter the amount of money in your pocket: ");
	scanf("%lf", &aDouble);
	printf("You entered %f\n", aDouble);
	
	// Use sprintf to concatenate the data - sprintf returns the length of the concatenated string
	j = sprintf(buffer, "You entered %s %d %f\n", aString, anInt, aDouble);
	printf("buffer = %s has %d characters\n", buffer, j);	// Has extra carrage return from concatenation
	buffer[j-1] = '\0';						// Strip off extra carrage return
	printf("buffer = %s has %d characters\n", buffer, j);	// Prints on one line
	
	// Get all three from user
	printf("Enter your name, age and the amount of money in your pocket: ");
	scanf("%s %d %lf", aString, &anInt, &aDouble);
	printf("You entered %s %d %f\n", aString, anInt, aDouble);
	
	// The return statement returns control to OS
	return 0;
}


// Function to convert an int to binary
void intToBin(int n, char bin[33]){
	int i=0, j=0, k=0;
	bin[32] = '\0';
	// Iterate through bits in n
	j = 31;
	for (i = 0; i < 32; i++){
		k = n >> i;	// Shift i bits
		if (k & 1)
			bin[j] = '1';
		else
			bin[j] = '0';
		j--;
	}
	return;
}


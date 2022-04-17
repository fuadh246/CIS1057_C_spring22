#include <stdio.h>

#define PI 3.14159

int main(int argc, char *argv[]){
	int anInt; // Declare integer
	double aDouble = 25.5; // Declare double
	float aFloat = 0; // Declare float
	char aChar = 'a'; // Declare char
	char aString[] = "Hello World!"; // Declare string
	double tax_rate_1996; // Declare double
	unsigned int uInt = 1000; // Declare unsigned integer
	
	double sum = 0; // Declare double
	int n = 5; // Declare integer
	double x = 30.45; // Declare double
	
	// Perform division with double and float
	sum = aDouble/aFloat;
	printf("sum = %f\n", sum);
	// Perform division with int casted as double, a double and a double literal
	sum = (double)n + x * 5.0;
	printf("The sum is %f\n", sum);
	
	// These printf calls show the syntax for this function
	// Note that the placeholders are different for most data types 
	printf("anInt =  %d %f %f\n", anInt, aFloat, aDouble);
	printf("aFloat =  %1.3f\n", aFloat);
	printf("aDouble =  %1.3f\n", aDouble);
	printf("aChar =  %c\n", aChar);
	printf("aString =  %s\n", aString);
	printf("o =  %c\n", aString[4]);
	
	// Print string literal "Hello"
	printf("Hello\n");
	// Print command line arguments
	printf("argv[0] = %s\n", argv[0]);
	if(argc > 1)
		printf("argv[1] = %s\n", argv[1]);
	printf("There are %d arguments\n", argc);
	
	// Get a double from a user
	printf("Enter a double: ");
	scanf("%lf", &aDouble);
	printf("You entered %lf\n", aDouble);
	
	// Get two strings (words) from a user
	char aString2[100];
	printf("Enter two strings: ");
	scanf("%s %s", aString, aString2); // Get two words seperated by a space
	printf("You entered %s %s\n", aString, aString2);

	// Get a line of text from a user
	printf("Enter a line: ");
	fflush(stdin); // This clears the input data stream
	gets(aString2); // Get line of text
	printf("%s\n", aString2);
	
	// Perform division and modulus
	int w  = 37;
	int z = w / n;  // Perform division
	int y = w % n;	// Find remainder
	// Print results
	printf("z = %d y = %d\n", z, y);
	
	// Calculate coins to be given for change
	int amount = 0, init_amount = 0;
	int quarters, dimes, nickels, pennies;
	// Get amount from user
	printf("Enter a value between 1 and 99: ");
	scanf("%d", &amount);
	init_amount = amount;
	
	// Calculate coins
	quarters = amount / 25;
	amount = amount % 25;
	dimes = amount / 10;
	amount = amount % 10;
	nickels = amount / 5;
	amount = amount % 5;
	pennies = amount;
	
	// Print results
	printf("The change for %d cents is: \n %d quarters\n %d dimes\n %d nickels \n %d pennies\n",
	init_amount, quarters, dimes, nickels, pennies);
	
	// Read three ints from user
	printf("Enter 3 integers seperated by spaces: ");
	scanf("%d %d %d", &w, &y, &z);
	printf("%d %d %d\n", w, y, z);	// Print ints
	printf("%d\n", (w+y+z));		// Print sum
	
	// Change ints values
	w = 5;
	y = 4;
	z = 3;
	// Print ints
	printf("%d %d %d\n", w, y, z);
	
	return 0;
}


void func(){
	
}
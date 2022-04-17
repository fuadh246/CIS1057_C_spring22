#include <stdio.h>
#define PI 3.14159

// Function prototypes
void printHello();
void printSomething(char[]);
double calcAreaCircle(double);
double calcAreaBox(double, double, double);
char getCharInput();
int getIntInput();
float getFltInput();
double getDblInput();
void getIntNFloatInput(int*, float*);
int getIntBetween1And10(int*);


int main(){

	// Declare data variables
	int anInt = 0;
	float aFloat = 0.0;
	double aDouble = 0.0;
	int anotherInt = 0;

	// Call printHello 4 times
	printHello();
	printHello();
	printHello();
	printHello();

	// Pass "Something" to printSomething
	printSomething("Something");

	// Declare a double
	double radius = 5.5;
	// Print radius, pass radius and the result of the function call to calcAreaCircle
	printf("Radius = %f and area = %f\n", radius, calcAreaCircle(radius));
	// Print literal reals, pass them and print result of call to calcAreaBox
	printf("The sides are: %f %f %f and area = %f\n", 1.0, 2.0, 3.0, calcAreaBox(1.0,2.0,3.0));

	// Call functions to get data from user
	printf("The character is: %c\n", getCharInput());
	printf("The integer is: %d\n", getIntInput());
	printf("The float is: %f\n", getFltInput());
	printf("The double is: %f\n", getDblInput());

	// Get more than one datum from a function
	// This is passing variables by reference and is not covered until Ch 06
	getIntNFloatInput( &anInt, &aFloat);
	printf("The int is %d and the float is %f\n", anInt, aFloat);
	anotherInt = getIntBetween1And10(&anInt);
	printf("The int is %d and the is %d between 1 and 10\n", anInt, anotherInt);

	return 0;
}

// Function to print hello
void printHello(){
	// Print hello
	printf("Hello\n");
	return;
}

// Function to print a string parameter
void printSomething(char s[]){
	// Print s
	printf("%s\n", s);
	return;
}

// Function to calculate the area of a circle
double calcAreaCircle(double radius){
	// Return area of a circle
	return PI * radius * radius;
}

// Calculate the area of a 3D box
double calcAreaBox(double a, double b, double c){
	// Return area of a box
	return a*b*c;
}

// Get char input from user
char getCharInput(){
	// Char to get input
	char aChar = '\0'; 	// Initialize char to NULL
	// Get char from user
	printf("Enter a character: ");
	scanf("%c", &aChar);
	// Return char to calling function
	return aChar;
}

// Get integer input from user
int getIntInput(){
	// Integer to get input
	int anInt = 0; 		// Initiaize int to 0
	// Get integer from user
	printf("Enter an integer: ");
	scanf("%d", &anInt);
	// Return integer to calling function
	return anInt;
}

// Get float input from user
float getFltInput(){
	// Float to get input
	float aFloat = 0.0; 	// Initialize float to 0.0
	// Get float from user
	printf("Enter an float: ");
	scanf("%f", &aFloat);
	// Return float to user
	return aFloat;
}

// Get double input from user
double getDblInput(){
	// Double to get input
	double aDouble = 0; 	// Initialize double to 0.0
	// Get double from user
	printf("Enter an double: ");
	scanf("%lf", &aDouble);
	// Return double to user
	return aDouble;
}

// Get integer input from user
// Notice that this function gets an integer and a float from the user
// The '&' passes the variables by reference instead of value as in previous examples
void getIntNFloatInput(int *anInt, float *aFloat){
	// Get integer from user
	printf("Enter an integer: ");
	scanf("%d", anInt); 	// Note that there is no & because anInt is a reference
	// Get float from user
	printf("Enter an float: ");
	scanf("%f", aFloat);
	printf("In function %d %f\n", *anInt, *aFloat);
	// Return to calling function
	return;
}

// Get integer input from user
int getIntBetween1And10(int *anInt){
	*anInt = 0;
	// Loop will iterate until an int between 1 and 10
	// inclusive is entered
	while((*anInt < 1) || (*anInt > 10)){
		// Get integer from user
		printf("Enter an integer between 1 and 10: ");
		scanf("%d", anInt);
	}
	// Check that int is between 1 and 10
	if((*anInt >= 1) && (*anInt <= 10))
		return 1;
	else
		return 0;
}












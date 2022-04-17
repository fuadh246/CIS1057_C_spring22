#include <stdio.h>
#include <conio.h>


// Prototypes
void getFrac(int *num, int *den);
char getOp();
void add(int num1, int den1, int num2, int den2, int *num3, int *den3);
int gcd(int a, int b);
void red(int *num, int *den);


// Main function
int main(){
	
	int num1 = 0;
	int den1 = 0;
	int num2 = 0;
	int den2 = 0;
	int num3 = 0;  // Result num
	int den3 = 0;  // Result den
	char op = '\0';
	

	// Call getFrac() to get the first fraction
	getFrac(&num1, &den1);
	// Call getOp() to get operation
	op = getOp();
	// Call getFrac() to get the second fraction
	getFrac(&num2, &den2);
	// Call add() to add fractions
	add(num1, den1, num2, den2, &num3, &den3);
	printf("The sum of %d/%d and %d/%d is %d/%d\n", num1, den1, num2, den2, num3, den3);
	
	// Get gcd
	int n = gcd(6, 9);
	printf("gcd(%d, %d) = %d\n", 6, 9, n);

	return 0;
}


// Gets a fraction from a uesr
void getFrac(int *num, int *den){
	char slash = '\0';
	printf("Enter a fraction as a /b: ");
	scanf("%d %c%d", num, &slash, den);
	printf("Input: %d%c%d\n", *num, slash, *den);
	return;
}


// Gets an operation from a user
// Only accepts + - * or /
char getOp(){
	char op = '\0';
	while(op!='+' && op!='-' && op!='/' && op!='*'){
		printf("Enter an operation (+ - / *): ");
		scanf("%c", &op);
	}
	printf("Op: %c\n", op);
	return op;
}

// Adds a fraction
void add(int num1, int den1, int num2, int den2, int *num3, int *den3){
	// Variables
	int num = 0;
	int den = 0;
	int sign = 0;
	
	// Perform addition
	den = den1 * den2;
	num = (num1 * den2) + (num2 * den1);
	
	// Get sign of sum fraction
	if((num * den) >= 0){
		sign = 1;
	}
	else
		sign = -1;

	// Set fraction so that numerator has the sign
	*num3 = sign * abs(num);
	*den3 = abs(den);
	
	// Reduce to lowest terms
	red(num3, den3);
	
	return;
}


// Use the Euclidean formula for gcd
int gcd(int a, int b){
	int rem = 0;
	int num = 0;
	int den = 0;
	
	// Set numerator and denominator
	if(a < b){
		num = a;
		den = b;
	}
	else{
		num = b;
		den = a;
	}
	
	// Get remainder of a/b
	rem = a % b;
	
	// Reduce num and den until rem is 0
	while(rem != 0){
		num = den;
		den = rem;
		rem = num % den;
	}
	
	// Den is gcd
	return den;
	
}


// Reduce a fraction to lowest terms
void red(int *num, int *den){
	// Get gcd of num and den
	int n = gcd(*num, *den);
	// Divide both by gcd
	*num = *num / n;
	*den = *den / n
	return;
}









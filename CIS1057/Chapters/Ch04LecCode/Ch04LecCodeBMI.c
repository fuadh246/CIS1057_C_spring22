// This program calculates a person's BMI
// given his/her weight and height
#include <stdio.h>

int main(){
	// Declare variables for standard measures
	int pounds, feet, inches;
	// Declare variables for metric measures and BMI
	double heightMeters, mass, BMI;

	// Get standard measures for weight and height data from user
	printf("Enter your weight in pounds: ");
	scanf("%d", &pounds);
	printf("Enter your height in feet followed \nby a space then additional inches: ");
	scanf("%d %d", &feet, &inches);

	// Convert standard measures to meters and kilograms
	heightMeters = ((feet * 12) + inches) * 0.0254;
	mass = (pounds / 2.2);

	// Compute and print BMI
	BMI = mass / (heightMeters * heightMeters);
	printf("Your BMI is %f\n", BMI);
	
	// Evaluate and print health category
	printf("Your risk category is: " );
	if (BMI < 18.5)
		printf("Underweight\n");
	else if (BMI < 25)
		printf("Normal weight\n");
	else if (BMI < 30)
		printf("Overweight\n");
	else
		printf("Obese\n");

	// Return control to OS
	return 0;
}

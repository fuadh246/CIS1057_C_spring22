/*
	This program calculates the weight of a number of
	washers.  The number and dimensions of washers are
	entered at the command line by the user.
	Inputs:
		density of material
		number of washers
		diameter of washer
		diameter of hole
		height of washer
	Output
		total weight of washers
*/

// Preprocessor directives
#include <stdio.h>
#include <math.h>
#define PI 3.14159

// Function prototypes - declare functions that are defined after
// the main function
void getInput(double*, double*, double*, double*, double*);
void setInput(double*, double*, double*, double*, double*);
double calcTotalWeight(double, double, double, double, double);
double calcWeightWasher(double, double, double, double);
double calcVolumeWasher(double, double, double);
double calcAreaWasher(double, double);
double calcAreaCircle(double);

// Driver functions to test other functions
void driver();
void driver2(double, double, double, double, double);
// Function to set variables for testing
void setInput(double*, double*, double*, double*, double*);

// Main function - entry point for all C programs
int main(){

	// Declare variables for inputs
	double density=0.0, numWashers=0.0, diaWasher=0.0, diaHole=0.0, height=0.0;
	// Declare variable for output
	double totalWeight = 0.0;

	// Call driver function to test functions
	//driver();

	// To set variables for faster testing
	//setInput(&density, &numWashers, &diaWasher, &diaHole, &height);

    // Call driver function to test functions with input variables
	//driver2(density, numWashers, diaWasher, diaHole, height);

	// Code to call functions to calculate the
	// Get input
	getInput(&density, &numWashers, &diaWasher, &diaHole, &height);
	printf("The inputs are: %1.2f %1.2f %1.2f %1.2f %1.2f\n",
		density, numWashers, diaWasher, diaHole, height);
	// Calc weight
	totalWeight = calcTotalWeight(density, numWashers, diaWasher, diaHole, height);
	// Print output
	printf("The total weight if %1.0f is %1.3f", numWashers, totalWeight);

	return 0;
}


// Get input from user
void getInput(double *density, double *numWashers, double *diaWasher, double *diaHole, double *height){
	printf("Enter density: ");
	scanf("%lf", density);
	printf("Enter number of washers: ");
	scanf("%lf", numWashers);
	printf("Enter diameter of washer: ");
	scanf("%lf", diaWasher);\
	printf("Enter diameter of hole: ");
	scanf("%lf", diaHole);
	printf("Enter height if washer: ");
	scanf("%lf", height);
	return;
}

// Calculate the total weight of a number of washers
double calcTotalWeight(double density, double numWashers, double diaWasher, double diaHole, double height){
	// Return total weight of washers
	return numWashers * calcWeightWasher(density, diaWasher, diaHole, height);
}

// Calculate the weight of a washer
double calcWeightWasher(double density, double diaWasher, double diaHole, double height){
	// Return the weight of a washer
	return density * calcVolumeWasher(diaWasher, diaHole, height);
}

// Calculate the volume of a washer
double calcVolumeWasher(double diaWasher, double diaHole, double height){
	// Return the volume of a washer
	return height * calcAreaWasher(diaWasher, diaHole);
}

// Calculate the area of a washer
double calcAreaWasher(double diaWasher, double diaHole){
	// Return the area of a washer
	return calcAreaCircle(diaWasher) - calcAreaCircle(diaHole);
}

// Calculate the area of a circle
double calcAreaCircle(double diameter){
	// Return the area of a circle
	return (PI * pow((diameter/2),2));
}

// Driver function to test calculations
void driver(){

	// Test area of a circle - answer should be 3.14
	printf("Area of a 2.0 circle: %1.2f\n", calcAreaCircle(2.0));
	// Test area of a circle - answer should be 0.2
	printf("Area of a 0.5 circle: %1.2f\n", calcAreaCircle(0.5));
	// Test area of a washer - answer should be 2.35
	printf("Area of a 2.0 washer with a 0.5 hole: %1.2f\n", calcAreaWasher(2.0, 0.5));
	// Test volume of a washer - answer should be 0.58
	printf("Volume of a 2.0 washer with a 0.5 hole and a 0.2 height: %1.2f\n",
		calcVolumeWasher(2.0, 0.5, 0.2));
	// Test density of a washer - answer should be 4.65
	printf("Density of a 2.0 washer with a 0.5 hole, a 0.2 height and density 7.9: %1.2f\n",
		calcWeightWasher(7.9, 2.0, 0.5, 0.2));
	// Test total weight of washers -  answer should be 23.27
	printf("Total weight of 5 washers with 2.0 washer diameter, 0.5 diameter hole, 0.2 height and 7.9 density: %1.2f\n",
		calcTotalWeight(7.9, 5.0, 2.0, 0.5, 0.2));
	return;
}

// Driver function to test calculations
void driver2(double density, double numWashers, double diaWasher, double diaHole, double height){

	// Test area of a circle
	printf("Area of a 2.0 circle: %1.2f\n",
		calcAreaCircle(diaWasher));
	// Test area of a circle
	printf("Area of a 0.5 circle: %1.2f\n",
		calcAreaCircle(diaHole));
	// Test area of a washer
	printf("Area of a 2.0 washer with a 0.5 hole: %1.2f\n",
		calcAreaWasher(diaWasher, diaHole));
	// Test volume of a washer
	printf("Volume of a 2.0 washer with a 0.5 hole and a 0.2 height: %1.2f\n",
		calcVolumeWasher(diaWasher, diaHole, height));
	// Test density of a washer
	printf("Density of a 2.0 washer with a 0.5 hole, a 0.2 height and density 7.9: %1.2f\n",
		calcWeightWasher(density, diaWasher, diaHole, height));
	// Test total weight of washers
	printf("Total weight of 5 washers with 2.0 washer diameter, 0.5 diameter hole, 0.2 height and 7.9 density: %1.2f\n",
		calcTotalWeight(density, numWashers, diaWasher, diaHole, height));
	return;
}

// Function to set values for testing and faster program execution
void setInput(double *density, double *numWashers, double *diaWasher, double *diaHole, double *height){
	*density = 7.9;
	*numWashers = 5;
	*diaWasher = 2.0;
	*diaHole = 0.5;
	*height = 0.2;
	return;
}





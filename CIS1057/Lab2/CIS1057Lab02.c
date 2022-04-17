/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in the area below designated inside of the main function. When
    completed, the main function should run the code for both problems.

    1. Write code that calculates mileage reimbursement for a salesperson at
    a rate of $.48 per mile. Your program should get the mileage from the user
    in this manner:
        MILEAGE REIMBURSEMENT CALCULATOR
        Enter beginning odometer reading: 13505.2
        Enter ending odometer reading: 13810.6
        You traveled 305.4 miles. At $0.48 per mile, your reimbursement is $146.59.

    2. Write code to convert a temperature in degrees Fahrenheit to degrees
    Celsius. Your program should get the temperature Fahrenheit from the user and
    print the result as:
        FAHRENHEIT TO CELSIUS CALCULATOR
        Enter temperature Fahrenheit: 100.0
        100.0 degrees Fahrenheit is 37.78 degrees Celsius

*/

// Preprocessor directives
#include <stdio.h>
#define cost_per_miles 0.48
// Main function
int main(){
    double beginningMiles = 0.0;
    double endingMiles = 0.0;
    double totalTraveled = 0.0;
    double totalCost = 0.0;
    double fahrenheit = 0.0, calsius = 0.0;

    // Coding Problem 1
    printf("MILEAGE REIMBURSEMENT CALCULATOR \n");
    //Get the beginning odometer
    printf("Enter beginning odometer reading: ");
    scanf("%lf", &beginningMiles);
    //Get the end odometer
    printf("Enter ending odometer reading: ");
    scanf("%lf", &endingMiles);

    //Calculate the total traveled 
    totalTraveled = endingMiles - beginningMiles;
    //Calculate the cost
    totalCost = cost_per_miles * totalTraveled;
    //Print the out put and round up
    //%0.2f round the number to 2 decimal point
    printf("You traveled %0.2f miles. At $0.48 per mile, your reimbursement is $%0.2f. \n" , totalTraveled, totalCost);

    // Coding Problem 2
    printf("FAHRENHEIT TO CELSIUS CALCULATOR \n");
    //Get the fahrenheit
    printf("Enter temperature Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    //Calculate the calsius 
    calsius = (fahrenheit - 32) * 5/9;
    //Print the out put and round up
    //%0.2f round the number to 2 decimal point
    printf("%0.2f degrees Fahrenheit is %0.2f degrees Celsius", fahrenheit,calsius);

// End main function
return 0;
}

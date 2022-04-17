// This program calculates an account balance
// after adjusting for interest and penalties
#include <stdio.h>

// Constant data for interest and penalties
const double OVERDRAWN_PENALTY = 8.00;
const double INTEREST_RATE = 0.02;		//2% annually 

int main(){
	// Balance of account
    double balance;
	
	// Get balance from user
    printf("Enter your checking account balance: $");
	scanf("%lf", &balance);
    printf("Original balance $%.2f\n", balance);
	
	// If balance > 0 pay interest else charge penalty
    if (balance >= 0)
        balance = balance + (INTEREST_RATE * balance) / 12;
    else
        balance = balance - OVERDRAWN_PENALTY;
	
	// Print resulting balance to user
    printf("After adjusting for one month of interest and penalties,\n");
    printf("your new balance is $%.2f\n", balance);
	
	// Return control to OS
	return 0;
}
 
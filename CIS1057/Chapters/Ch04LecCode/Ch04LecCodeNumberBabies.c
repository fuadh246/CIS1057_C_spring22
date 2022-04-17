// This program calculates a person's BMI
// given his/her weight and height
#include <stdio.h>

int main(){
	// Declare variable for number of babies
    int numberOfBabies;
	
	// Get number of babies from user
	do{
		printf("Enter number of babies: ");
		scanf("%d", &numberOfBabies);
	while((numberOfBabies < 1) && (numberOfBabies > 10));
	
	// Use switch-case to evaluete a response
    switch (numberOfBabies)
    {
        case 1:
            printf("Congratulations.\n");
            break;
        case 2:
            printf("Wow. Twins.\n");
            break;
        case 3:
            printf("Wow. Triplets.\n");
            break;
        case 4:
        case 5:
            printf("Unbelieveable! ");
			printf("%d babies.\n", numberOfBabies);
            break;
        default:
            printf("I don't believe you.\n");
            break;
    }

	// Return control to OS
	return 0;
}

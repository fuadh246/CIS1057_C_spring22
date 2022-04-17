// This program determines a student's letter
// grade considering his/her numerical score
#include <stdio.h>

int main(){
	// Variables for score and grade
    double score;
    char grade;
	
	// Get score from user
    printf("Enter your score: ");
	scanf("%lf", &score);
	
	// Determine letter grade based on score
    if (score >= 90)
        grade = 'A';
    else if (score >= 80)
        grade = 'B';
    else if (score >= 70)
        grade = 'C';
    else if (score >= 60)
        grade = 'D';
    else
        grade = 'F';
	
	// Print score and grade to screen
    printf("Score = %f\n", score);
    printf("Grade = %c\n", grade);
	
	// Return control to OS
	return 0;
}
 
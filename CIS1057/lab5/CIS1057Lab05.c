/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in functions below the main function and call both from the main
    function.  The functions should accept data from main, calculate and return
    the result to main.  Getting data from the user and printing the results
    should be done in main.  When completed, the main function should get input
    data from the user, call the functions, receive the results of the function
    calls, and print their results to screen.



    1. An integer n is divisible by 9 if the sum of its digits is divisible by 9.
    Develop a function to display each digit, starting with the rightmost digit.
    Your program should also determine whether or not the number is divisible by
    9. Write a function that calculates the sum of the digits in an int, checks to
    see if the sum is evenly divisible by 9 and returns 1 for yes and 0 for no.
    Test it on the following numbers:

        n = 154368
        n = 621594
        n = 123456

    Hint: Use the % and 10 operator to get the least significant digit and use /
    and 10 to remove the least significant digit.  Sample output:

    Run 1:
        IS IT DIVISIBLE BY 9
        Enter an integer: 154368
        154368 is divisible by 9

    Run 2:
        IS IT DIVISIBLE BY 9
        Enter an integer: 123456
        123456 is NOT divisible by 9



    2. The value for PI can be determined by the series equation:

        PI = 4(1/1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 ...)

    Write a function using a loop to approximate the value of PI using the formula
    given including terms up through 1/99, 1/999 and 1/9999.  As the number of
    iterations increase, the estimate gets closer to the value of PI. The function
    should accept the number of iterations and return the estimate of PI.

    Hint: To flip the sign from + to -, declare a variable and multiply it by -1
    inside the loop.  Sample output:

    Run 1:
        ESTIMATE PI
        Enter number of iterations: 99
        Estimated PI is 3.121595

    Run 2:
        ESTIMATE PI
        Enter number of iterations: 9999
        Estimated PI is 3.141393



*/

// Preprocessor directives


// Function prototypes
#include <stdio.h>
#include <math.h>
// Main function
int divisible(int num);
int estPI(int num2);
#define RED "\e[0;31m"
#define RESET   "\x1b[0m"
int main(){

    //problem 1
    int num =0;
    printf("IS IT DIVISIBLE BY 9 \n");
    printf("Enter integer \n");
    scanf("%d", &num);
    if (divisible(num) == 1){
        printf(RED"%d "RESET" is divisible by 9\n", num);
    }
    else{
        printf(RED"%d "RESET"is NOT divisible by 9\n", num);
    }
    // problem 2
    int num2 = 0;
    printf("ESTIMATE PI\n");
    printf("Enter number of iterations: \n");
    scanf("%d", &num2);
    estPI(num2);

    // this part is used to ask the user to run again without stopping the run
    char c;
    printf("Do you want to run the code again? \nif YES type 'y' else 'n' or any other char \n");
    scanf(" %c", &c);
    if (c == 'y'){
        main();
    } else {
        printf("DONE :)");
        return 0;
    }
return 0;
}

// Function for Coding Problem 1
//this function takes an intager an add all the digit of the 
int divisible(int num){
    int last=0, sum = 0;
    while(num>0){
    last=num%10;
    sum=sum+last;
    num=num/10;
    }
    int result = sum % 9;
    if(result == 0){
        return 1;
    }
    else{
        return 0;
    }
}
// Function for Coding Problem 2
int estPI(int num2){
    double PI = 0;
    double singFliper = 1;
    for (double i = 1; i <= num2; i+=2)
    {
        PI += singFliper*(1/i);
        singFliper = singFliper * -1;
    }
    printf(RED"%f\n"RESET,4*PI);
    return 0;
}



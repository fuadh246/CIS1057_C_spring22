/*

   Please write your code in the designated lines below.

*/

/* Add necessary libraries here. */
#include <stdio.h>
#define RED "\e[0;31m"
#define RESET "\x1b[0m"
#define GREEN "\033[0;32m"
/* Add function prototypes here. */
void atm(int dollars,int *fifties,int *twenties, int *tens);
void test7_11_13(int number, int *multiple, int *sum_odd_or_even, int *prime);
double my_sqrt(double N);

/* Add main function here. The function calls from the problems below should be
   called in main.
*/
int main (){
   int fifties = 0; int twenties = 0; int tens = 0;
   int multiple = 0; int sum_odd_or_even = 0; int prime = 0;
   int dollars = 0;
   int number = 0;
   double whole_num = 0; 
//problem 1
   printf("problem 1 \n");
   printf("Enter the number: ");
   do{
      scanf("%d", &dollars);
      if(dollars%10 != 0 || dollars <0){
         printf("Your input is" RED" invlid 🙁"RESET "\nEnter a amount that is multiple of 10 dollars and larger than 9 dollar \nReenter the number: ");
      }
   }while (dollars%10 != 0 ||  dollars <0);
   
   atm(dollars, &fifties, &twenties, &tens);
   printf("Number of bills dispensed for %d\n💵 Fifty: %d\n💵 Twenty: %d\n💵 Ten: %d\n", dollars, fifties, twenties, tens);

   //problem 2
   printf("problem 2 \n");
   printf("Enter the number: ");
   scanf("%d", &number);
   test7_11_13(number, &multiple, &sum_odd_or_even, &prime);
   if(multiple == 1){
      printf("a. "GREEN"YES"RESET" the value is a multiple of 7, 11, or 13 😀.\n");
   }else{printf("a. "RED"NO"RESET" the value is "RED"NOT"RESET" a multiple of 7, 11, or 13 🥲.\n");}
   if(sum_odd_or_even == 1){
      printf("b. The sum of the digits "GREEN"EVEN"RESET" 😀.\n");
   }else{printf("b. The sum of the digits "GREEN"ODD"RESET" 😀.\n");}
   if(prime == 0){
      printf("c. "GREEN"YES"RESET" the value is a prime number 😀.\n");
   }else{printf("c. "RED"NO"RESET" the value is "RED"NOT"RESET" a prime number 🥲.\n");}

// problem 3
   printf("problem 3\n");
   printf("Enter number to get square root: ");
   scanf("%lf",&whole_num);
   if(whole_num == 0)
   {
      printf(RED"YOU ENTERED ZERO\nRun again\n"RESET);
   }else{
      double square_root = my_sqrt(whole_num);
      printf("The square root of %.2lf is approximatly %.2lf\n",whole_num,square_root);
   }

// this part is used to ask the user to run again without stopping the run
    char c;
    printf("Do you want to run the code again? \nif YES type 'y' else 'n' or any other char \n");
    scanf(" %c", &c);
    if (c == 'y'){
        main();
    } else {
        printf("DONE 🙂\n");
        return 0;
    }
   return 0;
}


/*
   Add function for problem 1 here.

   1. Write a function for an automatic teller machine that dispenses money.
   The user should enter the amount desired (a multiple of 10 dollars) and the
   machine dispenses this amount using the least number of bills. The bills dispensed
   are 50s, 20s, and 10s. The function determines how many of each kind of bill to
   dispense.  The function should be named atm, accept an integer named dollars,
   integer pointer fifties, integer pointer twenties, integer pointer tens and return
   nothing.  When the function completes, the pointers should be set with the number
   of 50s, 20s and tens that are necessary to equal dollars.  Call atm from the main
   function to test it with a few dollar values.  When atm works properly, comment out
   the function call and start problem 2.
*/
void atm(int dollars,int *fifties,int *twenties, int *tens){
   if(dollars>=50){
      *fifties = dollars/50;
      dollars = dollars%50;
   }
   if(dollars>=20){
      *twenties = dollars/20;
      dollars = dollars%20;
   }
   if(dollars>=10){
      *tens =  dollars/10;
      dollars = dollars%10;
   }
}


/*
   Add function for problem 2 here.

   2. Determine the following information about each value in a list of positive integers.
      a. Is the value a multiple of 7, 11, or 13?
      b. Is the sum of the digits odd or even?
      c. Is the value a prime number?
   You should write a function named test7_11_13 with an integer input parameter and three type
   int output parameters (aka pointers) that send back the answers to these three questions. If the
   integer is evenly divisible by 7, 11 or 13, its respective output parameter should be set to 1,
   otherwise zero. Some sample input data might be:

   104 3773 13 121 77 30751

   Call test7_11_13 from the main function to test it.  When test7_11_13 works properly, comment out
   the function call and start problem 3.
*/

void test7_11_13(int number,int *multiple, int *sum_odd_or_even, int *prime){
   int sum = 0; int last_dig = 0;
   if(number%7 ==0 && number%11 ==0 && number%13){
      *multiple = 1;
   }else{
      *multiple = 0;
   }
   if(number == 2){
      *prime = 0;
   }else if(number == 1){*prime = 1;}
   else{
      for(int i = 2; i<number; i++){
         if(number%i == 0){
            *prime = 1;
            break;
         }else{
            *prime = 0;
         }
      }
   }
   do{
      last_dig = number%10;
      sum += last_dig;
      number = number/10;
   } while (number>0);
   if(sum%2 == 0){
      *sum_odd_or_even = 1;
   }else{
      *sum_odd_or_even = 0;
   }
}



/*
   3. Add functions for problem 3 here.

   The square root of a number N can be approximated by repeated calculation
   using the formula:

      NG = 0.5(LG + N/LG)

   where NG stands for next guess and LG stands for last guess. Write a function
   that calculates the square root of a number using this method.  Write a function
   called my_sqrt that accepts an double N, which is the number to find the square root
   and returns the square root found.  There are no pointers in this problem.  You do
   have to compare doubles, which requires an approximate match with an allowable error.

   The initial guess will be the starting value of LG . The program will compute
   a value for NG using the formula given. The difference between NG
   and LG is checked to see whether these two guesses are almost identical. If
   they are, NG is accepted as the square root; otherwise, the next guess ( NG )
   becomes the last guess ( LG ) and the process is repeated (another value is
   computed for NG, the difference is checked, and so on). The loop should be
   repeated until the difference is less than 0.005. Use an initial guess of 1.0.
   Write a driver function and test your square root function for the numbers
   4, 120.5, 88, 36.01, 10,000, and 0.25.

1. 
*/

double my_sqrt(double N){
    double LG = 1;
    double NG = (0.5*(LG + N/LG)); 
    while (NG - LG > 0.005 || NG - LG < 0){
        LG = NG;
        NG = (0.5*(LG + N/LG));
    }
    return NG;
}


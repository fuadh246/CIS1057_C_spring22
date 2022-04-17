#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Function prototypes
void whileLoop();
void doWhileLoop();
void forLoop();
int whileLoop2(int);
int doWhileLoop2(int);
int forLoop2(int);
int forLoop3(int);
int whileLoopToGetIntGrt1();
int isInt(const char *);
int doWhileLoopToGetIntGrt1();
int doWhileLoopToGetIntGrt1b();
void pickWinners();


// Main function
int main(){
	
    // Call a simple while loop
    whileLoop();
    printf("\n");
    doWhileLoop();
    printf("\n");
    forLoop();
    printf("\n");
        
    // Call a simple do-while loop
    doWhileLoop();
    printf("\n");
        
    // Declare int n
    int n = 5;
    // Call loops to calc sum of first n ints
    printf("The sum of the first %d ints using a while loop is: %d\n", n, whileLoop2(n));
    printf("The sum of the first %d ints using a do-while loop is: %d\n", n, doWhileLoop2(n));
    printf("The sum of the first %d ints using a for loop is: %d\n", n, forLoop2(n));
	printf("The sum of the first %d ints using a for loop is: %d\n", n, forLoop3(n));
    printf("\n");
         
    // Get int from user greater than 0 - Data validation
    n = whileLoopToGetIntGrt1();
    printf("The user entered: %d\n", n);
    n = doWhileLoopToGetIntGrt1();
    printf("The user entered: %d\n", n);
    n = doWhileLoopToGetIntGrt1b();
    printf("The user entered: %d\n", n);
    printf("\n");
	
	// Call to pick 3 of 10 winners
	pickWinners();

	return 0;
}


//**************************************************************************
// While loop example
void whileLoop(){
    // Declare counter variable i
    int i = 1;
    // Calculate the sum of the first n ints
    while(i <= 3)
        printf("This is line %d\n", ++i);
}
   
    
//**************************************************************************
// Do-while loop example
void doWhileLoop(){
    // Declare counter variable i
    int i = 1;
    // Calculate the sum of the first n ints
    do
        printf("This is line %d\n", ++i);
    while(i <= 3);
}
    
    
//**************************************************************************
// For loop example
void forLoop(){
    // Declare counter variable i
    int i = 1;
    // Calculate the sum of the first n ints
    for(i=0; i <= 3; i++)
        printf("This is line %d\n", i);
}
    
    
//**************************************************************************
// While loop example
int whileLoop2(int n){
    // Declare counter variable i
    int i = 1;
    // Declare accumulator variable sum
    int sum = 0;
    // Calculate the sum of the first n ints
    while(i <= n){
        sum += i;
        i++;
    }
    // Return sum to calling method
    return sum;
}
   
    
//**************************************************************************
// While loop example
int doWhileLoop2(int n){
    // Declare counter variable i
    int i = 0; // Note that i is zero
    // Declare accumulator variable sum
    int sum = 0;
    // Calculate the sum of the first n ints
    do{
        sum += i;
        i++;
    }while(i <= n);
    // Return sum to calling method
    return sum;
}
    
    
//**************************************************************************
// While loop example
int forLoop2(int n){
    // Declare accumulator variable sum
    int sum = 0;
	int i = 0;
    // Calculate the sum of the first n ints
    // Note that counter variable i is declared in loop
    for(i = 1; i <= n; i++)
        sum += i;
    // Return sum to calling method
    return sum;
}


//**************************************************************************
// For loop example
int forLoop3(int n){
    // Declare accumulator variable sum
    int sum = 0;
	int i = 1;
	int m = n/2 + 1;
    // Calculate the sum of the first n ints
    // Note that counter variable i is declared in loop
    for(; ;i++){
		if(i % 2 == 1)
			continue;
		sum += i;
		if(i > m)
			break;
	}
    // Return sum to calling method
    return sum;
}    
    
//**************************************************************************
// While loop example to get an int < 1
int whileLoopToGetIntGrt1(){
    // Declare variable n
    int n = 0;	  // Note n needs to be initialized
    // Get n from user
    while(n <= 0){
        printf("Enter an int greater than 0: ");
        scanf("%d", &n);
    }
    // Return n to calling method
    return n;
}


//**************************************************************************
// Do-while loop example to get an int < 1
int doWhileLoopToGetIntGrt1(){
    // Declare variable n
    int n = 0;    // Note n need not be initialized
    // Get n from user
    do{
        printf("Enter an int greater than 0: ");
        scanf("%d", &n);
    }while(n <= 0);
    // Return n to calling method
    return n;
}


//**************************************************************************
// Test string input for a valid integer
int isInt(const char *s)
{
   // Handle negative numbers.
   if (*s == '-')
      ++s;
   // Handle empty string or just "-".
   if (!*s)
      return 0;
   // Check for non-digit chars stirng.
   while (*s){
      if (!isdigit(*s))
         return 0;
      else
         ++s;
   }
   return 1;
}
    
    
//**************************************************************************
// D0-while loop example to get an int < 1 - checks for valid int
int doWhileLoopToGetIntGrt1b(){
    // Declare variable n
    int n = 0;    // Note n needs to be initialized
    char s[50];
    // Get n from user
    do{
        printf("Enter an int greater than 0: ");
        scanf("%s", s);
        if(isInt(s))
            n = atoi(s);
    }while(n <= 0);
    // Return n to calling method
    return n;
}


//**************************************************************************
// While loops to pick numbers between 1 1nd 10 not previously picked
void pickWinners(){
    // Declare ints for numbers
    int w1=0, w2=0, w3=0;
    int i = 0;
	
	// Seed rand function
	srand(time(NULL));
     
    // Pick first number
    w1 = (int) (rand() % 10) + 1;
    // Pick second number != first
    do{
        w2 = (int) (rand() % 10) + 1;
    }while(w2 == w1);
    // Pick third number != first or second
    do{
        w3 = (int) (rand() % 10) + 1;
    }while((w3 == w1) || (w3 == w2));
    // Print winners
    printf("The winners are %d, %d and %d\n", w1, w2, w3);
        
}


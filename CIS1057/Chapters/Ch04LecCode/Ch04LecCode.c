#include <stdio.h>

int main(){
	
	// Begin Chapter 4.1 - Compound Statements ***********************************************
	/*
		Compound statements group blocks of code containing statements and expressions into 
		containers with there own scope of influence over data variables.  These compound 
		statements are typically used to group multiple statements and expressions to 
		facilitate their use in control or loop structures.
	*/
	// This j has scope inside and outside of compound statements 
	int j = 1;
	
	// Compound statements can contain statements or expressions
	{
		// This i has scope inside the compound statement but not outside
		int i = 0;
		printf("This is line %d inside of a compound statement. j = %d\n", ++i, j++);
		printf("This is line %d inside of a compound statement. j = %d\n", ++i, j++);
		printf("This is line %d inside of a compound statement. j = %d\n", ++i, j++);
	}
	// This i has scope outside the compound statement
	int i = 0;
	printf("This is line %d outside of a compound statement. j = %d\n", ++i, j++);
	// End Chapter 4.1 ***********************************************************************
	
	
	
	// Begin Chapter 4.2 - Conditions ********************************************************
	/*
		Conditions are the expressions that are evaluated to determine whether or not code is
		executed in if statements and when loops are terminated.  
	*/
	// Variables to compare in conditional expressions
	double x = 15.0, y = 25.0;
	// Variable to contain result of condition
	
	/*
		Conditional statements use relational operators (<, >, <=, >=) and equality operators (==, !=) 
		are used to ask questions about data to decide whether a condition is true (non-zero) or false 
		(zero). 
	*/
	// Is x not equal to y
	i = x != y;
	printf("%.1f != %.1f is %d\n", x, y, i);
	// Is x less than x
	i = x < x;
	printf("%.1f < %.1f is %d\n", x, x, i);
	// Is x greater than or equal to y - x
	i = x >= y - x;
	printf("%.1f >= %.1f - %.1f is %d\n", x, y, x, i);
	// Is x equal to y + x - y
	i = x == y + x - y;
	printf("%.1f == %.1f + %.1f - %.1f is %d\n", x, y, x, y, i);
	
	/*
		Logical operators AND (&&) and OR (||) are used to expand conditional statements to logical 
		expressions.  The negation operator NOT (!) reverses the true or false decision for a conditional
		statement or logical expression.
		
		Operator precedence
		Highest		! + - &
					* / %
					+ -
					< <= > >=
					== !=
					&&
					||
		Lowest		=
	*/
	// Variables to compare logical expressions
	int a = 6, b = 9, c = 14, flag = 1;
	// Is c equal to a + b OR not flag
	i = c == a + b || !flag;
	printf("%d == %d + %d || %d is %d\n", c, a, b, !flag, i);
	// Is a not equal to 7 AND flag OR c greater than or equal to 6
	i = a != 7 && flag || c >= 6;
	printf("%d != 7 && %d || %d >= 6 is %d\n", a, flag, c, i);
	// Is NOT (b greater than or equal to 12) AND the remainder of a/2 equal to 0
	i = !(b <= 12) && a % 2 == 0;
	printf("!(%d <= 12) && %d %% 2 == 0 is %d\n", b, a, i);
	// Is NOT (b greater than or equal to 12) AND the remainder of a/2 equal to 0
	i = !(a > 5 || c < a + b);
	printf("!(%d > 5 || %d  < %d + %d) is %d\n", a, c, a, b, i);
	
	// Exclusive OR
	a = 1;
	b = 1;
	i = (a == 1 || b == 1) && !((a == 1) && (b == 1));
	printf("(%d == 1 || %d == 1) && !((%d == 1) && (%d == 1)) is %d\n", a, b, a, b, i);
	b = 0;
	i = (a == 1 || b == 1) && !((a == 1) && (b == 1));
	printf("(%d == 1 || %d == 1) && !((%d == 1) && (%d == 1)) is %d\n", a, b, a, b, i);
	
	// End Chapter 4.2 ***********************************************************************



	// Begin Chapter 4.3 - The if Statement **************************************************
	/*
		The if statement decides whether or not to execute certain code statements and expressions.
	*/
	a = 1;
	b = 2;
	c = 3;
	
	// if with single relational statement
	if(a < b)
		printf("%d is less than %d\n", a, b);
	
	// if-else with logical AND
	if(a < b && b > c)
		printf("%d is less than %d AND b is greater than c is true\n", a, b);
	else
		printf("%d is less than %d AND %d is greater than %d is false\n", a, b, b, c);
	
	// End Chapter 4.3 ***********************************************************************



	// Begin Chapter 4.4 - if Statements with Compound Statements ****************************
	/*
		if statements can contain compound statements.
	*/
	a = 1;
	b = 2;
	c = 3;
	
	// if statement with one relational statement but 3 statements in a compound statement
	if(a < b){
		printf("%d is less than %d\n", a, b);
		printf("%d is less than %d\n", a, b);
		printf("%d is less than %d\n", a, b);
	}
	
	// if-else with logical AND and compound statements
	if(a < b && b > c){
		printf("%d is less than %d AND b is greater than c is true\n", a, b);
		printf("%d is less than %d AND b is greater than c is true\n", a, b);
		printf("%d is less than %d AND b is greater than c is true\n", a, b);
	}
	else{
		printf("%d is less than %d AND %d is greater than %d is false\n", a, b, b, c);
		printf("%d is less than %d AND %d is greater than %d is false\n", a, b, b, c);
		printf("%d is less than %d AND %d is greater than %d is false\n", a, b, b, c);
	}
	
	// End Chapter 4.4 ************************************************************************



	// Begin Chapter 4.5 - Decision Steps in Algorithms ***************************************
	/*
		
	*/
	// End Chapter 4.5 ************************************************************************



	// Begin Chapter 4.6 - More Problem Solving ***********************************************
	/*
		
	*/
	// End Chapter 4.6 ************************************************************************



	// Begin Chapter 4.7 - Nested if Statements and Multiple-Alternative Decisions ************
	/*
		switch-case statements can also select from a group of multiple alternatives.
	*/
	a = 1;
	b = 2;
	c = 3;
	
	// 
	if(a < b)
		if(b < c)
			printf("%d is less than %d AND %d is greater than %d is true\n", a, b, b, c);
		else
			printf("%d is less than %d AND %d is greater than %d is false\n", a, b, b, c);
	
	// 
	if(a < b){
		printf("%d is less than %d\n", a, b);
		if(b < c)
			printf("%d is less than %d AND %d is greater than %d is true\n", a, b, b, c);
	}
	else
			printf("%d is not less than %d\n", a, b);
	
	//
	if(a < 1)
		printf("%d is less than 1\n", a);
	else if(a < 5)
		printf("%d is less than 5\n", a);
	else if(a < 10)
		printf("%d is less than 10\n", a);
	else
		printf("%d is not less than 10\n", a);
	
	//
	if(a < 1){
		printf("%d is less than 1\n", a);
		printf("%d is less than 1\n", a);
	}
	else if(a < 5){
		printf("%d is less than 5\n", a);
		printf("%d is less than 5\n", a);
	}
	else if(a < 10){
		printf("%d is less than 10\n", a);
		printf("%d is less than 10\n", a);
	}
	else{
		printf("%d is not less than 10\n", a);
		printf("%d is not less than 10\n", a);
	}
			
	// End Chapter 4.7 ************************************************************************



	// Begin Chapter 4.8 - The switch Statement ***********************************************
	/*
		
	*/
	a = 1;
	b = 2;
	c = 3;
	
	// switch with int
	switch (a){
		case 0:
			printf("a is 0: %d\n", a);
			break;
		case 1:
			printf("a is 1: %d\n", a);
			break;
		case 2:
			printf("a is 2: %d\n", a);
			break;
		default:
			printf("a is not in case: %d\n", a);
			break;			
	}
	
	char d = 'd';
	
	// switch with char
	switch (d){
		case 'A':
		case 'a':
			printf("d is A or a: %c\n", d);
			break;
		case 'B':
		case 'b':
			printf("d is B or b: %c\n", d);
			break;
		case 'C':
		case 'c':
			printf("d is C or c: %c\n", d);
			break;
		case 'D':
		case 'd':
			printf("d is D or d: %c\n", d);
			break;
		default:
			printf("d is not in case: %c\n", d);
			break;			
	}
	
	
	// End Chapter 4.8 *************************************************************************



	// Begin Chapter 4.9 - Common Programming Errors *******************************************
	/*
		
	*/
	// End Chapter 4.9 ************************************************************************
	
	// Return control to OS
	return 0;
}
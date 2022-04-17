/*
    This program shows some array functions, including:
	Declaring an array
	Initializing an array during declaration
	Initializing an array with a loop
	Printing an array with a loop
	Finding an element in an array by value with a selection search
	Sorting an array with selection sort
	
	There is a step-by-step example of the construction of a function
	to perform the selection sort.
*/


#include <stdio.h>

#define COUNT 10
#define COUNT_ROWS 3
#define COUNT_COLS 4
#define CLEAR 1

// Prototypes
int sum(int array[], int count);
int find(int array[], int n, int count);
void sort(int array[], int count);
void swap(int *a, int *b);
void sort1(int array[], int count);
void sort2(int array[], int count);
void sort3(int array[], int count);


// Main function
int main(){
	
	// Arrays for examples - Note that they are declared with brackets[]
	int array1[COUNT];  // There are count elements in this array
	int array2[COUNT];
	int array3[COUNT];
	int array4[] = {4, 9, 0, 6, 5, 2, 1, 3, 7, 8}; // Brackets can be empty for these declarations
	int array5[] = {3, 4, 1, 2};
	int array6[] = {3, 4, 1, 2};
	int array7[] = {3, 4, 1, 2};
	// Iterator/index
	int i = 0, j = 0;
	char c;
	// Declare a matrix (2D array)
	int matrix[COUNT_ROWS][COUNT_COLS] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
	
	// Other data types
	double array_dbl[5];
	char array_char[10];
	double array_dbl2[] = {1.23, 2.34, 3.45, 4.56, 5.67};
	char array_char2[] = "Hello World!";
	
	// Clear screen
	system("cls");
	
	printf("**** Declaring, initializing, adding and printing arrays\n\n");
	
	// Initialize array1
	printf("Initialize array1\n");
	for(i=0; i<COUNT; i++)
		array1[i] = i;
	
	// Initialize array2
	printf("Initialize array2\n\n");
	for(i=0; i<COUNT; i++)
		array2[i] = i;
	
	// Sum array1 and array2 into array3
	printf("Sum array1 and array2 into array3\n");
	for(i=0; i<COUNT; i++)
		array3[i] = array1[i] + array2[i];
	
	// Print array1
	printf("array1 ");
	for(i=0; i<COUNT; i++)
		printf("%d ", array1[i]);
	printf("\n");
	
	// Print array2
	printf("array2: ");
	for(i=0; i<COUNT; i++)
		printf("%d ", array2[i]);
	printf("\n");

	// Print array3
	printf("array3: ");
	for(i=0; i<COUNT; i++)
		printf("%d ", array3[i]);
	printf("\n\n");
	
	// Get sum of array1
	int n = sum(array1, COUNT);
	printf("Sum of array1 = %d\n\n", n);
	
	// Print double array
	printf("Print a double array\n");
	for(i=0; i<5; i++)
		printf("%1.2f ", array_dbl2[i]);
	printf("\n\n");
	
	// Print a char array
	printf("Print a char array\n");
	for(i=0; i<12; i++)
		printf("%c ", array_char2[i]);
	printf("\n\n");
	
	// Print char array as a string - Note the %s placeholder
	printf("Print char array as a string\n");
	printf("%s\n\n", array_char2);
	
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// ****************************
	// Selection search
	printf("**** This is a selection search\n\n");
	
	// Print array4
	printf("array4: ");
	for(i=0; i<COUNT; i++)
		printf("%d ", array4[i]);
	printf("\n");
	
	// Find 2 in array4
	n = 2;
	i = find(array4, n, COUNT);
	printf("The index is %d for %d\n", i, n);

	// Find 10 in array4
	n = 10;
	i = find(array4, n, COUNT);
	printf("The index is %d for %d\n\n", i, n);
	
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// ****************************
	// Selection sort
	/*
	    The functions called in this section show the construction of
		a selection sort function.  Each new construction adds another
		feature to the sort.  The final version of the sort is shown
		last.
	*/
	printf("**** This shows the results of code for constructing a selection sort\n\n");
	
	// Sort array5 with sort1 - Just prints values to screen
	printf("The first step is to make sure that the inner \nloop is comparing the correct elements\n\n");
	printf("array5 in main: ");
	for(i=0; i<4; i++)
		printf("%d ", array5[i]);
	printf("\n");
	printf("Sorting array5\n");
	sort1(array5, 4);
	printf("Array5 in main: ");
	for(i=0; i<4; i++)
		printf("%d ", array5[i]);
	printf("\n\n");
	
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Test the swap function for sort functions
	printf("Need a swap function to continue\n\n");
	i = 10, j = 20;
	printf("Swap %d and %d\n", i, j);
	printf("In main: i = %d n = %d\n", i, j);
	swap(&i, &j);
	printf("In main: i = %d n = %d\n\n", i, j);
	
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Sort array6 with sort2 - Uses swap to find first min
	printf("This construction finds the min value and swaps \nit with the 0 element\n\n");
	printf("array6 in main: ");
	for(i=0; i<4; i++)
		printf("%d ", array6[i]);
	printf("\n");
	printf("Sorting array6\n");
	sort2(array6, 4);
	printf("Array6 in main: ");
	for(i=0; i<4; i++)
		printf("%d ", array6[i]);
	printf("\n\n");
	
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Sort array7 with sort3 - Add the outer loop to find the remaining mins
	printf("The last construction adds the outer loop and \ncompletely sorts the array\n\n");
	printf("array7 in main: ");
	for(i=0; i<4; i++)
		printf("%d ", array7[i]);
	printf("\n");
	printf("Sorting array7\n");
	sort3(array7, 4);
	printf("Array7 in main: ");
	for(i=0; i<4; i++)
		printf("%d ", array7[i]);
	printf("\n\n");
	
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	printf("This shows the results of code for the final sort code\n\n");
	// Sort array4 with final sort version
	printf("array4: ");
	for(i=0; i<COUNT; i++)
		printf("%d ", array4[i]);
	printf("\n");
	printf("Sorting array4\n");
	sort(array4, COUNT);
	printf("array4: ");
	for(i=0; i<COUNT; i++)
		printf("%d ", array4[i]);
	printf("\n\n");
	
	printf("Press a key to continue\n\n");
	c = getchar();
	if(CLEAR)
		system("cls");
	
	
	// Matrix examples
	// Print a matrix to screen
	printf("Print matrix\n");
	for(i=0; i<COUNT_ROWS; i++){
		for(j=0; j<COUNT_COLS; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
	
	
	// Multiply elements in an array by 2
	printf("Multiply elements in an array by 2\n\n");
	for(i=0; i<COUNT_ROWS; i++){
		for(j=0; j<COUNT_COLS; j++)
			matrix[i][j] = matrix[i][j] * 2;
	}
	
	// Print a matrix to screen
	printf("Print matrix\n");
	for(i=0; i<COUNT_ROWS; i++){
		for(j=0; j<COUNT_COLS; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
	
	// Print matrix indices to screen
	printf("Print matrix indices as (i,j)\n");
	for(i=0; i<COUNT_ROWS; i++){
		for(j=0; j<COUNT_COLS; j++)
			printf("(%d,%d) ", i, j);
		printf("\n");
	}
	printf("\n");
	
	return 0;
}

// Calc the sim of the elements in an array
int sum(int array[], int count){
	//printf("array[0] = %d count = %d\n", array[0], count);
	int n = 0;  // Accumulator for sum
	int i = 0;  // Index counter
	for(i=0; i<10; i++){
		n = n + array[i];
		//printf("i = %d array[i] = %d n = %d\n", i, array[i], n);
	}	
	return n;  // The sum
}

// Find a value n in an array
int find(int array[], int n, int count){
	int i = 0;  // Index counter
	// Loop through array
	for(i=0; i<count; i++)
		if(array[i] == n)
			return i;  // Found at i
	return -1;  // Not found
}


// This section is to show the construction of the selection sort
/*
  A selection sort sorts an array of elements.  If we have an int array = {3, 4, 1, 2}, we need to
  have the sort complete with the array sorted as {1, 2, 3, 4}.  Initially, select the first element 
  as the min element and find one that is less.  If index 0 or the value 3 is assume to be min, you 
  need to check from 1 to 3 for the least value.
*/

// Selection sort construction 1
// Notice that the array includes empty brackets after the identifier [] and that the count is included
// to ensure that only the array elements are processed, no more and no less.
void sort1(int array[], int count){
	int min_idx = 0;  // Assume that the 0th element is min
	int i = 0;        // Index for outer loop of nested loop
	int j = 0;        // Index for inner loop of nested loop
	// Loop from index j = 1 to n-1 - this is the inner loop
	i = 1; // Will be set in each iteration of outer loop
	printf("array in sort1: min = %d and remaining = ", array[min_idx]);
	for(j=i; j<count; j++)
		printf("%d ", array[j]); // Should print from 1 to n-1
	printf("\n");
}


// Need a swap for the next function
// Swaps two integers
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


// Selection sort construction 2
// This function will swap the least with the assumed min.
void sort2(int array[], int count){
	int min_idx = 0;  // Assume that the 0th element is min
	int i = 0;        // Index for outer loop of nested loop
	int j = 0;        // Index for inner loop of nested loop
	printf("array in sort2: min = %d and remaining = ", array[min_idx]);
	i = 1; // Will be set in each iteration of outer loop
	// Loop from index j = 1 to n-1 - this is the inner loop
	for(j=i; j<count; j++){
		if(array[j] < array[min_idx]){ // Check for new min
			min_idx = j; // A min less than the previous is found
		}
		printf("%d ", array[j]); // Should print from j to n-1
	}
	printf("\nMin found at array[%d] = %d\n", min_idx, array[min_idx]);
	// Swap the new min with the assumed min value
	printf("Swaping %d and %d\n", array[min_idx], array[i-1]);
	swap(&array[min_idx], &array[i-1]);  // This will swap min_idx with index 0
}


// Selection sort construction 3
// This function will add the outer loop.
void sort3(int array[], int count){
	int min_idx = 0;  // Assume that the 0th element is min
	int i = 0;        // Index for outer loop of nested loop
	int j = 0;        // Index for inner loop of nested loop
	// Nested loop
	// Loop starts at index 1 to n-1 - this is the outer loop
	for(i=1; i<count; i++){
		// Loop from index j = 1 to n-1 - this is the inner loop
		printf("array in sort3: min = %d and remaining = ", array[min_idx]);
		for(j=i; j<count; j++){
			if(array[j] < array[min_idx]){ // Check for new min
				min_idx = j; // A min less than the previous is found
			}
			printf("%d ", array[j]); // Should print from j to n-1
		}
		printf("\nMin found at array[%d] = %d\n", min_idx, array[min_idx]);
		// Swap the new min with the assumed min value
		printf("Swaping %d and %d\n", array[min_idx], array[i-1]);
		swap(&array[min_idx], &array[i-1]);  // This will swap min_idx with index 0
		// Set min_idx to next assumed min
		min_idx = i;
	}
}


// Selection sort final version
// This function will add the outer loop.
void sort(int array[], int count){
	int min_idx = 0;  // Assume that the 0th element is min
	int i = 0;        // Index for outer loop of nested loop
	int j = 0;        // Index for inner loop of nested loop
	// Nested loop
	// Loop starts at index 1 to n-1 - this is the outer loop
	for(i=1; i<count; i++){
		// Loop from index j = 1 to n-1 - this is the inner loop
		for(j=i; j<count; j++){
			if(array[j] < array[min_idx]){ // Check for new min
				min_idx = j; // A min less than the previous is found
			}
		}
		// Swap the new min with the assumed min value
		swap(&array[min_idx], &array[i-1]);  // This will swap min_idx with index 0
		// Set min_idx to next assumed min
		min_idx = i;
	}
}

















/*
    This problem requires:
        1. The data from a file to be read into an array of sport_t
        2. Print the array to screen
        3. Increase all prices by 20% (multiply by 1.2) and print updated array to screen
        4. Write the updated data to file

*/

/*
    Step 1: Import libraries for standard input/output library, standard library
    and the string library
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
/*
    Step 2:Create a constants   CHANGE = 1.2 (to increase prices by 20%)
                                ID_SIZE = 5 (number of chars in a sports_t id)
                                DESC_SIZE = 25 (number of chars in a sports_t description)
                                MAX = 50 (length of sports_t array)
*/
#define CHANGE 1.2
#define ID_SIZE  5
#define DESC_SIZE 25
#define MAX 50
/*
    Step 3: Create a struct called sports_t that contains data:
        a string of ID_SIZE characters called id
        a string of DESC_SIZE characters called description
        an integer called quantity
        a double called price
*/
typedef struct{
    char id[ID_SIZE];
    char description[DESC_SIZE];
    int quantity;
    double price;
    int count;
}sports_t;

/*
    Add prototypes here.
*/
int read_sports_t(sports_t *sa,char file_name[]);
void print_sports_t(sports_t sa);
void print_all_sports_t(sports_t *sa);
int calc_sports_t(sports_t *sa,sports_t *incresed_price_array);
/*
    Step 4: Create main function here.
    Step 8: Declare an array of MAX sports_t called sa and an int length (set length to 0)
    Step 9: Call function to read file contents to sa and accept length from return
    Step 10: Print all the elements of sa to screen (see sample output below)
    Step 12: Call calc_sports_t to increase prices by 20% and print the updated data in sa to screen
    Step 14: Call write_sports_t to write updated file (write to file sporting_update.txt)
*/
int main(){
    sports_t sa[MAX];
    sports_t increased_price_array[MAX];
    read_sports_t(sa,"sporting.txt");
    print_all_sports_t(sa);
    calc_sports_t(sa,increased_price_array);
    print_all_sports_t(increased_price_array);

    return 0;
}


/*
    Step 5: Write a function called read_sports_t that accepts an array of sports_t
    called sa and a string called filename.
    Add code to open the file, check that the file opened successfully and
    a loop to read the data from the file into sa.
    Return the number of records read.
    The file has a blank space for a delimiter.  You can use either scanf or fgets.
*/
int read_sports_t(sports_t *sa,char file_name[]){
    FILE *file=fopen(file_name,"r");
    if(file==NULL){
        perror("Read file failed to open\n");
    }
    sa->count = 0;
    //if any file has spaces then use this fscanf
    while(fscanf(file,"%s %s %d %lf",sa[sa->count].id,sa[sa->count].description,&sa[sa->count].quantity,&sa[sa->count].price)!=EOF){
        sa->count++;
    }
    fclose(file);
    return sa->count;
}


/*
    Step 6: Write a function called print_sports_t to print a sports_t to screen.
    The last datum printed on the line should be the line total of an item.  Multiply
    quantity by price to get the value of inventory for the current item.  Sample output:

                                                        This is the line total
    FB01 Football                     37      19.99     739.63
*/
void print_sports_t(sports_t sa){
    double total = sa.quantity*sa.price;
    printf("%5s %15s %10d %10.2f %10.2f\n",sa.id,sa.description,sa.quantity,sa.price,total);
}


/*
    Step 7: Write a function called print_all_sports_t to print an array of sports_t to screen.
    Make sure to add the column titles and format the data as shown in the sample output.  Declare
    a double called total to accumulate the total value of inventory to print after all items have
    been printed.  See output below.
    Hint: call print_sports_t in a loop, passing each element. (see sample output below)
    TEST your code by printing the array from main.
*/
void print_all_sports_t(sports_t *sa){
    char s1[] = "ID";
    char s2[] = "Description";
    char s3[] = "Quantity";
    char s4[] = "Price";
    char s5[] = "Total";
    printf("%5s %15s %10s %10s %10s\n", s1, s2, s3, s4, s5);
    double totalinvantory = 0;
    for(int i=0;i<sa->count;i++){
        print_sports_t(sa[i]);
        totalinvantory += sa[i].quantity*sa[i].price;
    }
    printf("The total value of inventory is:    %.2f\n",totalinvantory);
}

/*
    Step 11: Write a function called calc_sports_t that accepts an array of sports_t and the length
    of the array to increase all prices by CHANGE.
    TEST your code by calling calc_sports_t in main.
*/
int calc_sports_t(sports_t *sa,sports_t *incresed_price_array){
    incresed_price_array->count=0;
    for(int i=0;i<sa->count;i++){
        strcpy(incresed_price_array[i].id,sa[i].id);
        strcpy(incresed_price_array[i].description,sa[i].description);
        incresed_price_array[i].quantity = sa[i].quantity;
        incresed_price_array[i].price=1.2*(sa[i].price);
        incresed_price_array->count++;
    }
    return incresed_price_array->count;
}

/*
    Step 13: Write a function called write_sports_t to write the data to a new file.
    TEST your program and submit ONLY the c file to Canvas.
*/




// Sample screen output
/*
 ID Description             Quantity      Price      Total
FB01 Football                     37      19.99     739.63
BB02 Baseball                     68       5.99     407.32
FB03 FootballHelmet               13      39.99     519.87
BB04 CatchersMit                   7      49.99     349.93
BB05 BaseballBat                  42      24.99    1049.58
The total value of inventory is:    3066.33

 ID Description             Quantity      Price      Total
FB01 Football                     37      23.99     887.56
BB02 Baseball                     68       7.19     488.78
FB03 FootballHelmet               13      47.99     623.84
BB04 CatchersMit                   7      59.99     419.92
BB05 BaseballBat                  42      29.99    1259.50
The total value of inventory is:    3679.60
*/

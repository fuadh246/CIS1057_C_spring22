/*
    This problem requires:
        1. The data from a file to be read into an array of clothes_t
        2. Print the array to screen
        3. Update the clothing in stock by subtracting items sold and print the updated array to screen
        4. Write the updated data to file

*/

/*
    Step 1: Import libraries for standard input/output library, standard library
    and the string library
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*
    Step 2: Create a constants  MAX = 45
                                ITEM_LENGTH 30
*/
#define max 45
#define ITEM_LENGTH 30
/*
    Step 3: Create a struct called clothes_t that contains data:
        an integer called code
        a string of ITEM_LENGTH characters called description
        an integer called quantity
        a double called price
*/
typedef struct{
    int code;
    char description[ITEM_LENGTH];
    int quantity;
    double price;
    int count;
}clothes_t;


/*
    Add prototypes here.
*/
int read_clothes_t(clothes_t *ca,char file_name[]);
void print_clothes_t(clothes_t ca);
void print_all_clothes_t(clothes_t *ca);
int calc_clothes_t(clothes_t *ca,int sold[]);
int write_clothes_t(clothes_t *ca,char file_name[]);
int read_clothes_t_using_buffer(clothes_t *ca, char file_name[]);

/*
    Step 4: Create main function here.
    Step 8: Declare an array of MAX clothes_t called ca, an int length (set length to 0)
        and an array of integers called sold with values: 5, 8, 3, 6 and 4.
    Step 9: Call function to read file contents to ca and accept length from return
    Step 10: Print all the elements of ca to screen (see sample output below)
    Step 12: Call calc_clothes_t to subtract the sold clothes from inventory. The arrays
        ca and sold are parallel arrays.  The i^th value in change updates the i^th price.
        Print the updated data in ca to screen
    Step 14: Call write_clothes_t to write the updated data to file named clothes_update.txt
*/
int main(){
    clothes_t ca[10];
    int sold[]={8, 8, 8, 8, 8};
    read_clothes_t_using_buffer(ca,"clothes.txt");
    
    //printf("%d",ca->quantity);
    print_all_clothes_t(ca);
    calc_clothes_t(ca,sold);
    print_all_clothes_t(ca);
    write_clothes_t(ca,"outputfileforproblem1.txt");

    return 0;
}


/*
    Step 5: Write a function called read_clothes_t that accepts an array of clothes_t
    called ca and a string called filename.
    Add code to open the file, check that the file opened successfully and
    a loop to read the data from the file into ca.
    Return the number of records read.
    The file has a blank space for a delimiter.  You can use either scanf or fgets.
*/
int read_clothes_t(clothes_t *ca, char file_name[]){
    FILE *file = fopen(file_name,"r");
    if(file == NULL){
        perror("Cloth data file failed to open");
        exit(1);
    }
    while(fscanf(file,"%d %s %d %lf",&ca[ca->count].code,ca[ca->count].description,&ca[ca->count].quantity,&ca[ca->count].price)!=EOF){
        ca->count++;
    }
    fclose(file);
    return ca->count;
}
int read_clothes_t_using_buffer(clothes_t *ca, char file_name[]){
    FILE *file = fopen(file_name,"r");
    char buffer[200];
    if(file == NULL){
        perror("Cloth data file failed to open");
        exit(1);
    }
    while(fgets(buffer,200,file)!=NULL){
        ca[ca->count].code=atoi(strtok(buffer," "));
        strcpy(ca[ca->count].description,strtok(NULL," "));
        ca[ca->count].quantity=atoi(strtok(NULL," "));
        ca[ca->count].price=atoi(strtok(NULL," "));
        ca->count++;
    }
    fclose(file);
    return ca->count;
}

/*
    Step 6: Write a function called print_clothes_t to print a clothes_t to screen with a line total.
    The line total is quantity x price, the value of an item in stock.  Sample line:

                                                          This is the line total
    1      BlueJeans                    40      19.99     799.60
*/
void print_clothes_t(clothes_t ca){
    double totalprice = ca.price*ca.quantity;
    printf("%3d %20s %10d %10.2f %10.2f\n",ca.code,ca.description,ca.quantity,ca.price,totalprice);
}


/*
    Step 7: Write a function called print_all_clothes_t to print an array of clothes_t to screen.
    Make sure to add the column titles and format the data as shown in the sample output.  Declare
    a double called total to accumulate the total value of inventory, accumulate it in the loop and
    print the total after the loop.
    Hint: call print_clothes_t in a loop, passing each element. (see sample output below)
    TEST your code by printing the array in main.
*/
void print_all_clothes_t(clothes_t *ca){
    char s1[] = "ID";
    char s2[] = "Description";
    char s3[] = "Quantity";
    char s4[] = "Price";
    char s5[] = "Total";
    double totalinvantory = 0;
    printf("%3s %20s %10s %10s %10s\n", s1, s2, s3, s4, s5);
    for(int i=0;i<ca->count;i++){
        totalinvantory += ca[i].quantity*ca[i].price;
        print_clothes_t(ca[i]);
    }
    printf("The total value of inventory is:    %.2f\n",totalinvantory);
    printf("\n");
}
/*
    Step 11: Write a function called calc_clothes_t that accepts an array of clothes_t, the length
    of the array to subtract the sold items from inventory and an array called sold that contains
    the number of each item sold. (see sample output below)
    TEST your code by calling calc_clothes_t in main.
*/
int calc_clothes_t(clothes_t *ca,int sold[]){
    printf("%d\n",ca[ca->count].quantity);
    for(int i=0;i<ca->count;i++){
        ca[i].quantity = ca[i].quantity-sold[i];
    }
    return 0;
}


/*
    Step 13: Write a function called write_clothes_t to write the data to a new file.
    TEST your program and submit ONLY the c file to Canvas.
*/
int write_clothes_t(clothes_t *ca,char file_name[]){
    FILE *file = fopen(file_name,"w");
    double totalprice = ca->price*ca->quantity;
    for(int i=0;i<ca->count;i++){
        fprintf(file,"%3d %20s %10d %10.2f %10.2f\n",ca[i].code,ca[i].description,ca[i].quantity,ca[i].price,totalprice);
    }
    fclose(file);
    return 0;
}
/*
int write_with_fput(){
    FILE *file = fopen(file_name,"w");
    double totalprice = ca->price*ca->quantity;
    for(int i=0;i<ca->count;i++){
        
    }
    return 0;
}
*/

// Sample screen output
/*
Code   Item                   Quantity      Price     Total
1      BlueJeans                    40      19.99     799.60
2      Shorts                       51      12.99     662.49
3      LongSleeveShirt              32       9.99     319.68
4      ShortSleeveShirt             63       7.99     503.37
5      Shoes                        24      29.99     719.76
The total value of clothing is:    3004.90

Code   Item                   Quantity      Price     Total
1      BlueJeans                    32      19.99     639.68
2      Shorts                       43      12.99     558.57
3      LongSleeveShirt              24       9.99     239.76
4      ShortSleeveShirt             55       7.99     439.45
5      Shoes                        16      29.99     479.84
The total value of clothing is:    2357.30
*/

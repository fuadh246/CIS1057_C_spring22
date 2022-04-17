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



/*
    Step 2: Create a constants  MAX = 45
                                ITEM_LENGTH 30
*/



/*
    Step 3: Create a struct called clothes_t that contains data:
        an integer called code
        a string of ITEM_LENGTH characters called description
        an integer called quantity
        a double called price
*/



/*
    Add prototypes here.
*/



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



/*
    Step 5: Write a function called read_clothes_t that accepts an array of clothes_t
    called ca and a string called filename.
    Add code to open the file, check that the file opened successfully and
    a loop to read the data from the file into ca.
    Return the number of records read.
    The file has a blank space for a delimiter.  You can use either scanf or fgets.
*/



/*
    Step 6: Write a function called print_clothes_t to print a clothes_t to screen with a line total.
    The line total is quantity x price, the value of an item in stock.  Sample line:

                                                          This is the line total
    1      BlueJeans                    40      19.99     799.60
*/



/*
    Step 7: Write a function called print_all_clothes_t to print an array of clothes_t to screen.
    Make sure to add the column titles and format the data as shown in the sample output.  Declare
    a double called total to accumulate the total value of inventory, accumulate it in the loop and
    print the total after the loop.
    Hint: call print_clothes_t in a loop, passing each element. (see sample output below)
    TEST your code by printing the array in main.
*/



/*
    Step 11: Write a function called calc_clothes_t that accepts an array of clothes_t, the length
    of the array to subtract the sold items from inventory and an array called sold that contains
    the number of each item sold. (see sample output below)
    TEST your code by calling calc_clothes_t in main.
*/



/*
    Step 13: Write a function called write_clothes_t to write the data to a new file.
    TEST your program and submit ONLY the c file to Canvas.
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

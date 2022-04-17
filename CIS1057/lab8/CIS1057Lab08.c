/*
    Please code solutions for the problems below.  You should only have one main function
    and call the required functions for each problem.  Sample output:

    Enter the colors of the resistor's three bands, beginning with
    the band nearest the end. Type the colors in lowercase letters
    only, NO CAPS.
    Band 1 => green
    Band 2 => black
    Band 3 => yellow
    Resistance value: 500 kilo-ohm(s)
    Do you want to decode another resistor: y

    Enter the colors of the resistor's three bands, beginning with
    the band nearest the end. Type the colors in lowercase letters
    only, NO CAPS.
    Band 1 => brown
    Band 2 => vilet
    Band 3 => gray
    Resistance value: -1 kilo-ohm(s)
    Do you want to decode another resistor: n

    Enter a string: chair
    The plural of chair is chairs
    Do you want to convert another string: y

    Enter a string: dairy
    The plural of dairy is dairies
    Do you want to convert another string: y

    Enter a string: boss
    The plural of boss is bosses
    Do you want to convert another string: n

    Enter first string: procrastination
    Enter second string: destination
    The suffix of procrastination and destination is stination
    Do you want to find another suffix: y

    Enter first string: globally
    Enter second string: internally
    The suffix of globally and internally is ally
    Do you want to find another suffix: y

    Enter first string: gloves
    Enter second string: dove
    The suffix of gloves and dove is
    Do you want to find another suffix: n


    Process returned 0 (0x0)   execution time : 124.085 s
    Press any key to continue.


*/

// Import standard input/output library
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
// Function prototypes go here
void StoPcoverter(long int length, char Snoun[100]);
char *compare_two_common_suffix(char firstword[100],long int firstword_length, char secword[100],long int sectword_length,char *common);
char *strrev(char *str);
void resist_decode(char COLOR_CODES[10][7],int power[10],int value[10]);
int search(char brand[],char COLOR_CODES[10][7]);

// Main function goes here
// Main, libraries and prototypes: 5 points
int main(){
    char Snoun[100];
    char firstword[100];
    char secword[100];
    //problem 1
    char COLOR_CODES[10][7] = {"black", "brown", "red",
        "orange", "yellow", "green", "blue", "violet", "gray",
        "white"};
    int power[10] = {1,10,100,1000,10000,100000,1000000,1000000,100000000,1000000000};
    int value[10]={0,1,2,3,4,5,6,7,8,9};
    resist_decode(COLOR_CODES,power,value);
    //problem 2
    char c;
    do{
        printf("enter a noun: ");
        scanf("%s",Snoun);
        unsigned long length = strlen(Snoun);
        StoPcoverter(length,Snoun);
        printf("Do you want to run the code again? \nif YES type 'y' else 'n' or any other char \n");
        scanf(" %c", &c);
    }while(c=='y');
    //problem 3
    char problem3;
    do{
        printf("enter a first word: ");
        scanf("%s",firstword);
        printf("enter a first word: ");
        scanf("%s",secword);
        unsigned long firstword_length = strlen(firstword);
        unsigned long secword_length = strlen(secword);
        size_t size = 80;
        char *common = malloc(sizeof(char) * size);
        char *returnedcommon = compare_two_common_suffix(firstword,firstword_length,secword,secword_length,common);
        if(returnedcommon == NULL){
            printf("NO MATHCES!\n");
        }else{
            printf("Common suffix of this word is '%s'\n",returnedcommon);
        }
        printf("Do you want to run the code again? \nif YES type 'y' else 'n' or any other char \n");
        scanf(" %c", &problem3);
    }while(problem3=='y');

    return 0;
}


/*

Problem 1: 10 points

A resistor is a circuit device designed to have a specific resistance value
between its ends. Resistance values are expressed in ohms or kilo-ohms.
Resistors are frequently marked with colored bands that encode their
resistance values, as shown below. The first two bands are digits, and the
third is a power-of-ten multiplier.

The table below shows the meanings of each band color. For example, if the
first band is green, the second is black, and the third is yellow, the resistor has a
value of 50 x 10^4 or 500k.  The 50 is 10 x green(index 5) + black(index 0)).  The
10^4 is 10^yellow(index 4).  The information in the table can be stored in a C program
as an array of strings.

    char COLOR_CODES[10][7] = {"black", "brown", "red",
    "orange", "yellow", "green", "blue", "violet", "gray",
    "white"};

Notice that "red" is COLOR_CODES[2] and has a digit value of 2 and a multiplier
value of 10 2 . In general, COLOR_CODES[ n ] has digit value n and multiplier value 10 n .
Write a function that accepts the colors of Band 1, Band 2, and Band 3,
and then returns the resistance in kilo-ohms. Include a helper function search
that takes three parameters--the list of strings, the size of the list, and a target
string, and returns the subscript of the list element that matches the target or
returns -1 if the target is not in the list.

Color Codes for Resistors*
    Color Value     Digit Value     Multiplier
    Black           0               10^0
    Brown           1               10^1
    Red             2               10^2
    Orange          3               10^3
    Yellow          4               10^4
    Green           5               10^5
    Blue            6               10^6
    Violet          7               10^7
    Gray            8               10^8
    White           9               10^9

*Adapted from Sears and Zemansky�s University Physics , 10th edited by Hugh D. Young and Roger A.
Freedman (Boston: Addison-Wesley, 2000), p. 807.

*/

// resistor function goes here
void resist_decode(char COLOR_CODES[10][7],int power[10],int value[10])
{
    printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end. Type the colors in lowercase letters only, NO CAPS.\n");
    char brand1[10],brand2[10],brand3[10];
    printf("Brand1 = ");
    scanf(" %s",brand1);
    printf("Brand2 = ");
    scanf(" %s",brand2);
    printf("Brand3 = ");
    scanf(" %s",brand3);
    if(search(brand1,COLOR_CODES)!=-1 && search(brand2,COLOR_CODES)!=-1 && search(brand3,COLOR_CODES)!=-1)
    {
         int a=search(brand1,COLOR_CODES);
         int b=search(brand2,COLOR_CODES);
         int c=search(brand3,COLOR_CODES);
         long result=((value[a]*10+value[b])*power[c])/1000;
         printf("Resistance value: %ld kilo-ohm(s)\n",result );
  
    }
    else{
        printf("Resistance value: -1 kilo-ohm(s)\n");
    }
}

// search function goes here
int search(char brand[],char COLOR_CODES[10][7]){
    for(int i = 0; i<10;i++){
        if(strcmp(brand,COLOR_CODES[i])==0){
            return i;
        }
    }
    return -1;
}

/*

Problem 2: 5 points

Write a function that takes nouns and forms their plurals on the basis of
these rules:

    a. If noun ends in "y", remove the "y" and add "ies".
    b. If noun ends in "s", "ch", or "sh", add "es".
    c. In all other cases, just add "s".

Print each noun and its plural. Try the following data:
    chair   dairy   boss    circus  fly dog church  clue    dish

*/

// plural function goes here
void StoPcoverter(long int length, char Snoun[100]){
    char lastLetter = Snoun[length - 1];
    char secLastLetter = Snoun[length - 2];
    //char twolast[2] = secLastLetter+lastLetter;
    if(lastLetter == 'y'){
        Snoun[length - 1] = '\0';
        strcat(Snoun,"ies");
        printf("%s\n",Snoun);
    }
    else if (lastLetter == 's'||
    (secLastLetter == 'c' && lastLetter == 'h')||
    (secLastLetter == 's' && lastLetter == 'h')){
        //Snoun[length - 1] = '\0';
        //Snoun[length - 2] = '\0';
        strcat(Snoun,"es");
        printf("%s\n",Snoun);
    }else{
        strcat(Snoun,"s");
        printf("%s\n",Snoun);
    }
}

/*

Problem 3: 5 points

Write and test a function that finds and returns through an output parameter
the longest c of two words (e.g., the longest common suffix of
"procrastination" and "destination" is "stination", of "globally" and "internally"
is "ally", and of "gloves" and "dove" is the empty string).

*/

// suffix function goes here
char *compare_two_common_suffix(char firstword[100],long int firstword_length, char secword[100],long int sectword_length,char *common){
    size_t  length = 0;
    firstword_length = firstword_length-1;
    sectword_length = sectword_length-1;
    if(strcmp(&firstword[firstword_length], &secword[sectword_length])!=0){
        return NULL;
    }
    else{
        while(strcmp(&firstword[firstword_length], &secword[sectword_length])==0){
            common[length]=secword[sectword_length];
            firstword_length--;
            sectword_length--;
            length++;
        }
        common[length] = '\0';
        strrev(common);
    }
    return common;
}

//from google
char *strrev(char *str)
{
    if (!str || ! *str)
        return str;
    int i = strlen(str) - 1, j = 0;
    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}
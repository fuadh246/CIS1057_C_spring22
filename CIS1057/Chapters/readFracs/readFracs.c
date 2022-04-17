#include <stdio.h>
#include <string.h>

// Define the size of an array of Fractions
#define SIZE 100


// This defines a new user-defined data type to
// contain data about a fraction
typedef struct{
    int sign;   // Sign of Fraction 1 for positive -1 for negative
    int num;    // Numerator
    int den;    // Denominator
} Fraction;


// This defines a new user defined data type to
// contain an array of Fraction with the count of
// Fraction data types in the array
typedef struct{
    Fraction array[SIZE];   // Array of Fraction
    int count;              // Count of Fraction in array
} FractionArray;


// Prints a Fraction data to screen
void printFrac(Fraction f){
    // If sign is negative print - for negative Fraction
    if(f.sign<0)
        printf("-%d/%d\n", f.num, f.den);
    // Print positive Fraction
    else
        printf("%d/%d\n", f.num, f.den);
}


// Uses a loop to iterate through an array of
// Fraction data types.  Calls printFrac to
// print each Fraction in the array.
void printFracArray(FractionArray fa){
    int i = 0;
    for(i=0; i<fa.count; i++)
        printFrac(fa.array[i]);
}


// Accepts an array of char containing a fraction
// and converts it to a Fraction data type.
// Note that Fraction is passed by reference and
// the pointer notation (->) to set Fraction data.
void fracString(char s[], Fraction *f){
    int i = 0, j = 0;   // Iterators
    // Char array to contain values to be converted
    // to int
    char nstr[10];

    // Get sign
    if(s[i] == '-'){
        f->sign = -1;
        i++;
    }
    else
        f->sign = 1;

    // Initialize j to first element in nstr
    j = 0;
    // Copy chars until / into nstr
    while(s[i] != '/')
        nstr[j++] = s[i++];
    // Append null to end of nstr
    nstr[j] = '\0';
    // Convert nstr to int value and store in
    // Fraction numerator
    f->num = atoi(nstr);

    // Initialize j to first element in nstr
    j = 0;
    // Increment i to char after /
    i++;
    // Copy chars until null
    while(s[i] != '\0')
        nstr[j++] = s[i++];
        // Append null to end of nstr
    nstr[j] = '\0';
    // Convert nstr to int value and store in
    // Fraction denominator
    f->den = atoi(nstr);
}


// Get the decimal value of a Fraction data type
double fracDouble(Fraction f){
    return (double)f.sign * (double)f.num / (double)f.den;
}


// Swap two Fraction data types.  Note that both
// Fractions are passed by reference.
void swap(Fraction *f1, Fraction *f2){
    Fraction temp;  // Temp Fraction
    // Copy f1 to temp
    temp.sign = f1->sign;
    temp.num = f1->num;
    temp.den = f1->den;
    // Copy f2 to f1
    f1->sign = f2->sign;
    f1->num = f2->num;
    f1->den = f2->den;
    // Copy temp to f2
    f2->sign = temp.sign;
    f2->num = temp.num;
    f2->den = temp.den;
}


// Sort an FractionArray array from low to high.
// Note that the FractionArray is passed by reference
// and that use of pointer notation.
void sort(FractionArray *fa){
    // Iterators and min index
    int i, j, min;
    // Loop from 0 to next to last element
    for(i=0; i<fa->count-1; i++){
        // Initially assume that i is min
        min = i;
        // Loop from one after i to last element
        for(j=i+1; j<fa->count; j++){
            // If the Fraction value at j is less than the value at min
            if(fracDouble(fa->array[j]) < fracDouble(fa->array[min]))
                min = j;    // Set min to j
        }
        // Swap the Fraction data for i and min
        swap(&(fa->array[i]), &(fa->array[min]));
    }
}


// Main function
int main(){

    FractionArray fa;   // FractionArray has an array of Fraction
    fa.count = 0;       // Set initial count of Fraction in fa to zero
    char buffer[201];   // Buffer for file reads
    char *pch;          // Char array pointer for strtok
    // Open filr containing a csv for fractions
    FILE *file = fopen("fractions.csv", "r");

    // While file has data to read
    while(fgets(buffer, 200, file) != NULL){
        // Put null over \n read from file
        buffer[strlen(buffer)-1] = '\0';
        // Show line read from file
        printf("Read: |%s|\n", buffer);
        // Print length of buffer char array
        printf("Length: %d\n", strlen(buffer));
        pch = strtok(buffer, ",");

        // Use strtok to split fractions into FractionArray
        // While more fractions in buffer
        while(pch != NULL){
            //printf("%s\n", pch);
            // Convert pch to a Fraction data type
            // Note that the Fraction in the
            // FractionArray is passed by reference
            fracString(pch, &(fa.array[fa.count]));
            //printFrac(fa.array[fa.count]);
            // Increment the count of Fractions in
            // FractionArray
            fa.count++;
            // Get next fraction from buffer
            pch = strtok(NULL, ",");
        }
    }

    // Print FractionArray
    printf("\nNot sorted\n");
    printFracArray(fa);
    // Sort FractionArray
    sort(&fa);
    // Print FractionArray
    printf("\nSorted\n");
    printFracArray(fa);

    return 0;
}

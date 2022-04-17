/* Coding Problems (25 points) */

/*
    Please write code for the two problems below.  Write the code for both
    problems in functions below the main function and call both from the main
    function.  The functions should accept data from main, calculate and return
    the result to main (Problem 2 should print the results for the substance to
    screen.  See below.).  Getting data from the user and printing the results
    should be done in main.  When completed, the main function should get input
    data from the user, call the functions, receive the results of the function
    calls, and print their results to screen.
    1. Write a function that determines the day number (1 to 366) in a year for a
    date that is provided as input data. As an example, January 1, 1994, is day 1.
    December 31, 1993, is day 365. December 31, 1996, is day 366, since 1996 is
    a leap year. A year is a leap year if it is divisible by four, except that any year
    divisible by 100 is a leap year only if it is divisible by 400. Your function should
    accept the month, day, and year as integers from main as arguments. Include an
    additional function leap that returns 1 if called with a leap year, 0 otherwise.
    Sample screen output:
        CALCULATE DAY OF YEAR
        Enter a date: 12 31 2004
        12/31/2004 is the 366th day of 2004
    Note that a leap year is a year that is divisible by 4 but not by 100 or divisible
    by 400.  1900 was not a leap year because it's divisible by 4 but is also divisible
    by 100.  2000 was a leap year because it's divisible by 400.  1904 was a leap year
    because it's divisible by 4 but not divisible by 100.
    2. The table below shows the normal boiling points of several substances. Write
    a function that accepts an argument the observed boiling point of a substance
    in degrees Celsius and identifies the substance if the observed boiling point
    is within 5% of the expected boiling point. If the data input is more than 5%
    higher or lower than any of the boiling points in the table, the function should
    output the message Substance unknown.  Note that the function should print the
    substance and not main.  This will simplify the function call in main.  You need
    to test each substance in an else if chain for the temperature passed from main.
        Substance   Normal boiling point (Celsius)
        Water       100
        Mercury     357
        Copper      1187
        Silver      2193
        Gold        2660
    Your function should define and call a function within_x_percent that takes
    as parameters a reference value ref , a data value data , and a percentage value
    x and returns 1 meaning true if data is within x % of ref -that is, (ref - x%
    * ref) <= data <= (ref + x % * ref) . Otherwise within_x_percent would
    return zero, meaning false. For example, the call within_x_percent(357,
    323, 10) would return true, since 10% of 357 is 35.7, and 323 falls between
    321.3 and 392.7. Sample screen output:
        FIND SUBSTANCE FOR BOILING POINT
        Enter a temperature: 360
        The substance is Mercury
*/

#include <stdio.h>
#include <math.h>
// Prototypes
int leap(int year);
int problem_1(int year, int month, int day);
int within_x_percent(double boiling_point, double temperature, double percentage);
void problem_2(double temperature);

// main function
int main()
{
    // problem 1
    int yy, mm, dd;
    printf("CALCULATE DAY OF YEAR\n");
    printf("Enter a date: ");
    scanf("%d %d %d", &dd, &mm, &yy);
    int result_p1 = problem_1(yy, mm, dd);
    printf("%d/%d/%d is the %dth day of %d\n", dd, mm, yy, result_p1, yy);
    printf("\n");

    // problem 2
    double temperature;
    printf("FIND SUBSTANCE FOR BOILING POINT\n");
    printf("Enter a temperature: ");
    scanf("%lf", &temperature);
    // call the problem_2 function and pass temperature into it
    problem_2(temperature);
    return 0;
}

int leap(int year)
{
    // tell if the year is leap year

    // Psuedocode:
    // if ((year can be divided by 4) and ((year can be divided by 400) or (year cannot be divided by 100)))
    //      then return 1
    // else
    //      then return 0

    if (year == 2000)
        return 1;
    else if (year == 1900)
        return 0;
    return 0;
}

int problem_1(int year, int month, int day)
{
    int days = 0;
    if (leap(year) == 1)
    { // if the year is leap year
        int jan = 0;
        int feb = 31;
        int mar = feb + 28;
        int apr = mar + 31;
        int may = apr + 30;
        int jun = may + 31;
        int jul = jun + 30;
        int aug = jul + 31;
        int sep = aug + 31;
        int oct = sep + 30;
        int nov = oct + 31;
        int dec = nov + 30;
        // using a array to store all the months in order then
        // geting the month by using property of arrays
        int months[] = {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
        // using the arguments geting the the month and day.
        // subtracting -1 from the months because array start from 0 the adding the day with the array value.
        days = (day + months[month - 1]);
    }
    else
    { // if the year is not leap year
        int jan = 0;
        int feb = 31;
        int mar = feb + 28;
        int apr = mar + 31;
        int may = apr + 30;
        int jun = may + 31;
        int jul = jun + 30;
        int aug = jul + 31;
        int sep = aug + 31;
        int oct = sep + 30;
        int nov = oct + 31;
        int dec = nov + 30;
        // using a array to store all the months in order then
        // geting the month by using property of arrays
        int months[] = {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
        // using the arguments geting the the month and day.
        // subtracting -1 from the months because array start from 0 the adding the day with the array value.
        days = (day + months[month - 1]);
    }

    return days;
}

int within_x_percent(double boiling_point, double temperature, double percentage)
{
    // if the temperature is within the range, then return 1
    // else then return 0
    percentage = percentage / 100;
    if (boiling_point - percentage * boiling_point <= temperature && boiling_point + percentage * boiling_point >= temperature)
    {
        return 1;
    }
    return 0;
}

void problem_2(double temperature)
{
    // call within_x_percent function to tell if it is any substance in the list.
    // You will have a series of if statement to test if the substance is one of the substances on the list

    // if it returns 1 then
    int Water = 100;
    int Mercury = 357;
    int Copper = 1187;
    int Silver = 2193;
    int Gold = 2660;

    if (within_x_percent(Water, temperature, 5) == 1)
    {
        printf("The substance is Water.\n");
    }
    else if (within_x_percent(Mercury, temperature, 5) == 1)
    {
        printf("The substance is Mercury.\n");
    }
    else if (within_x_percent(Copper, temperature, 5) == 1)
    {
        printf("The substance is Copper.\n");
    }
    else if (within_x_percent(Silver, temperature, 5) == 1)
    {
        printf("The substance is Silver.\n");
    }
    else if (within_x_percent(Gold, temperature, 5) == 1)
    {
        printf("The substance is Gold.\n");
    }
    else
    {
        printf("none \n");
    }
}

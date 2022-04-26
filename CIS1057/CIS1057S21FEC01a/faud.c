#include <stdio.h>

int main(){
    char s1[] = "ID";
    char s2[] = "Description";
    char s3[] = "Quantity";
    char s4[] = "Price";
    char s5[] = "Total";

    char id[] = "FB01";
    char de[] = "Football";
    int qt = 37;
    double pr = 19.99;
    double to = qt * pr;

    printf("%5s %12s %10s %10s %10s\n", s1, s2, s3, s4, s5);
    printf("%5s %12s %10d %10.2f %10.2f\n", id, de, qt, pr, to);



    return 0;
}

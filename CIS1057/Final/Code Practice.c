#include <stdio.h>
#include <math.h>
#include <string.h>


void decisions();
void whatsTheSum();
int whatIsIt(int array[], int count);
void whatAgain();
void whatMatrix();
void whatCubed();
void whatsThis();
void whereIsIt(int a[]);
void whereIsIt2(int a[]);
void whatsPrinted1(int a, int b);
void whatsPrinted2(int c, int d);
int whatsPrinted3(int b, int a);
void whatsPrinted4(int arr[], int count, int a);
void whatsPrinted5();
void whatChars(char s[], char contents[], int length);

int main(){

	char z;
	int i = 0;

	decisions();
	printf("\n");
	z = getch();

	whatsTheSum();
	printf("\n");
	z = getch();

	int array1[] = {4, 8};
	int array2[] = {7, 9, 2};
	int array3[] = {4, 7, 3, 8, 1, 4};
	int array4[] = {1, 2, 3, 4, 5, 6};
	int array5[] = {8, 6, 5, 4, 0};
	printf("whatIsIt(array1) = %d\n", whatIsIt(array1, 2));
	printf("whatIsIt(array2) = %d\n", whatIsIt(array2, 3));
	printf("whatIsIt(array3) = %d\n", whatIsIt(array3, 6));
	printf("whatIsIt(array4) = %d\n", whatIsIt(array4, 6));
	printf("whatIsIt(array5) = %d\n", whatIsIt(array5, 5));
	printf("\n");
	z = getch();

	whatAgain();
	printf("\n");
	z = getch();

	whatMatrix();
	printf("\n");
	z = getch();

	whatCubed();
	printf("\n");
	z = getch();

	whatsThis();
	printf("\n");
	z = getch();

	int vector[] = {1, 2, 3, 4, 5};
	whereIsIt(vector);
	for(i=0; i<5; i++)
		printf("%d ", vector[i]);
	printf("\n\n");
	z = getch();

	int vector2[] = {1, 2, 3, 4, 5};
	whereIsIt2(vector2);
	for(i=0; i<5; i++)
		printf("%d ", vector2[i]);
	printf("\n\n");
	z = getch();

	int a = 1, b = 10;
	whatsPrinted1(b, a);
	printf("\n");
	z = getch();

	int c = 15, d = 5;
	whatsPrinted2(c, d);
	printf("\n");
	z = getch();

	a = 50;
	b = 20;
	c = whatsPrinted3(b, a);
	printf("c = %d\n\n", c);
	z = getch();

	int vector3[] = {8, 0, 2, 1, 3};
	b = 2;
	whatsPrinted4(vector3, 5, b);
	printf("%d\n\n", (vector3[2] + vector3[4]));
	z = getch();

	whatsPrinted5();
	printf("\n");
	z = getch();

	char t[20];
	char s[] = "2152046789";
	whatChars(s, t, 10);
	printf("t = %s\n\n", t);

	return 0;
}


void decisions(){
    int crowded = 1;
    int noisy = 0;
    int booze = 1;
    int food = 0;

    if((crowded && !noisy) || (!food || booze))
        printf("Let's go to this club!\n");
    else
        printf("What do you want to do?\n");

    if((!crowded && !noisy) && (food && booze))
        printf("Let's go to the bar.\n");
    else
        printf("Let's stay home.\n");

    if(!(crowded || noisy) || !(food || booze))
        printf("Let's go to the football game.\n");
    else
        printf("Let's bbq.\n");

    if((!crowded && !noisy) || !(food && booze))
        printf("Let's go here.\n");
    else
        printf("Let's play pool.\n");

}


void whatsTheSum(){
    int sum = 1;
    int i = 1, j = 0;
    while(i < 5){
        for(j = i; j > 0; j--)
            {sum += (j - i); printf("i = %d j = %d sum = %d\n", i, j, sum);}
        i++;
        //printf("i = %d j = %d sum = %d\n", i, j, sum);
    }
    printf("The sum is: %d\n", sum);
}


int whatIsIt(int array[], int count){
    int i = 0, total = 0;
    for(i=1; i<count-1; i+=1)
        {total += array[i];printf("i = %d total = %d\n", i, total);}
    printf("Done i = %d total = %d\n", i, total);
    return total;
}


void whatAgain(){
	int i = 0;
    int array[] = {9, 5, 3, 1, 0, 4, 2, 6};
    int something = 7;
    for(i=1; i<8; i++){
        if(array[something] < array[i])
             something = i;
        printf("i = %d array[i] = %d something = %d array[something] = %d\n",
               i, array[i], something, array[something]);
    }
    printf("i = %d array[i] = %d something = %d\n", i, array[i], something);
    printf("something is %d\n", array[something]);
}


 void whatMatrix(){
    int i=0, j=0;
    int matrix[][4] = {{1, 2, 1, 2},
                       {2, 1, 2, 1},
                       {1, 2, 1, 2},
					   {2, 1, 2, 1}};
    for(i=1; i<3; i++)
        for(j=1; j<3; j++)
            if(matrix[i][j] % 2 == 0)
                printf("%d ", matrix[i][j]);
    printf("%d\n", (matrix[0][0] + matrix[1][1] +
					matrix[2][2] + matrix[3][3]));
}


void whatCubed(){
    char cube[2][3][4];
    int i=0, j=0, k=0;
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            for(k=0; k<4; k++){
                cube[i][j][k] = 'X';
                printf("%c ", cube[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}


void whatsThis(){
	int i = 0;
    float thing1[] = {3.7f, 7.4f, 4.3f, 3.5f, 6.2f, 4.6f};
    double thing2 = 6;
    for(i = 5; i>0; i--){
        if(thing2 < thing1[i])
            thing2 = thing1[i];
        printf("i = %d thing1[i] = %1.2f thing2 = %1.2f\n", i, thing1[i], thing2);
    }
    printf("i = %d thing1[i] = %1.2f thing2 = %1.2f\n", i, thing1[i], thing2);
    printf("thing2 = %1.1f\n", thing2);
}


void whereIsIt(int a[]){
    int b[] = {5, 4, 3, 2, 1};
    a = b;
}


void whereIsIt2(int a[]){
    a[2] = a[3];
}


// Call with a = 10 and b = 1
void whatsPrinted1(int a, int b){
    a += (20 * b);
    printf("a = %d\n", a);
    a /= (b * 2);
    printf("a = %d\n", a);
    b = a * 5;
    printf("b = %d\n", b);
}


// Call with c = 15 and d = 5
void whatsPrinted2(int c, int d){
    c %= d;
    printf("c = %d\n", c);
    d += c + 4;
    printf("d = %d\n", d);
    c = (int)sqrt(d);
    printf("c = %d\n", c);
}


// Call with a = 50 and b = 20
int whatsPrinted3(int b, int a){
    a -= (2 * b);
    printf("a = %d\n", a);
    a *= b;
    printf("a = %d\n", a);
    b = a / 10;
    return b;
}


// Call array3[] = {8, 0, 2, 1, 3} - get arr[2]
void whatsPrinted4(int arr[], int count, int a){
	int i = 0;
    for(i=0; i<count; i++){
        if(i % 2 == 1)
            arr[i] *= a;
        printf("i = %d arr[i] = %d count = %d a = %d\n", i, arr[i], count, a);
    }
    printf("i = %d arr[i] = %d count = %d a = %d\n", i, arr[i], count, a);
}


//
void whatsPrinted5(){
	int i = 0;
    char str[] = {'j', 'w', 'a', 'o', 'v', 'r', 'a', 'l', '!', 'd'};
    for(i=0; i<5; i++)
        printf("%c", str[i*2]);
    printf("\n");
}


//
void whatChars(char s[], char t[], int length){
	int i = 0;
    for(i=0; i<length; i++)
        if(s[i] < '3')
            t[i] = 'A';
        else if(s[i] < '6')
            t[i] = 'B';
        else if(s[i] < '9')
            t[i] = 'C';
        else
            t[i] = 'D';
		t[length] = '\0';
}



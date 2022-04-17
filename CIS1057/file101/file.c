#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int id;
	char make[50];
	char model[50];
	int year;
	int miles;
	double price;
}car;

int read_text(char *file_name,int i_array[],double d_array[]);
int write_text(char *file_name,int i_array[],double d_array[],int count);
int read_car(char file_name[], car cars[]);
int write_binary(char file_name[],int count, int i_array[], double d_array[]);
int read_binary(char *file_name,int i_array[],double d_array[],int count);

int main(){
    //how to read file with spaces.
    int i_array[5];
    double d_array[5];
    int count = 0;
    double total;

    count = read_text("nums.txt",i_array,d_array);
    //int i = write_text("num2.csv",i_array,d_array,count);
    //for (int i = 0; i < count; i++)
    //{
    //    total += d_array[i];
    //}
    //printf("total = %.2f\n",total);
    //text file with coma
    car cars[10];
    //read_car("cars.txt",cars);

    //binary file 
    write_binary("binaryfile.bin",count,i_array,d_array);
    read_binary("binaryfile.bin",i_array,d_array,count);
    return 0;
}

int read_text(char *file_name,int i_array[],double d_array[]){
    int count = 0;
    FILE *file = fopen(file_name,"r");
    if(file == NULL){
        perror("Input file failed to open");
        exit(1);
    }
    while(fscanf(file,"%d %lf",&i_array[count],&d_array[count]) != EOF){
        printf("%d %.2f\n",i_array[count],d_array[count]);
        count++;
    }
    fclose(file);
    return count;
}

int write_text(char *file_name,int i_array[],double d_array[],int count){
    int i = 0;
    FILE *file;
        file = fopen(file_name,"w");
        if(file == NULL){
            perror("Output file failed to open");
            exit(2);
        }
        for(i = 0 ;i <count;i++){
            fprintf(file,"%d,%f\n",i_array[i],d_array[i]);
        }
        fclose(file);
        return i;
}

int read_car(char file_name[], car cars[]){
    int count = 0; 
    FILE *file = fopen(file_name,"r");
    char buffer[200];
        if(file == NULL){
            perror("Intput car file failed to open");
            exit(3);
        }
        while(fgets(buffer,200,file)!=NULL){
            cars[count].id = atoi(strtok(buffer,","));
            strcpy( cars[count].make, strtok(NULL,","));
            printf("%d\n",cars[count].id);
            printf("%s\n",cars[count].make);
            count++;
        }
    fclose(file);
    return count;
}

int write_binary(char file_name[],int count, int i_array[], double d_array[]){
    int i = 0;
    FILE *file = fopen(file_name,"wb");
    if(file == NULL){
        perror("Output file failed to open");
        exit(5);
    }
    fwrite(i_array,count,sizeof(int),file);
    fwrite(d_array,count,sizeof(double),file);
    fclose(file);
    return count;
}
int read_binary(char *file_name,int i_array[],double d_array[],int count){
    FILE *file = fopen(file_name,"rb");
    if(file == NULL){
        perror("Input file failed to open");
        exit(6);
    }
    fread(i_array,count,sizeof(int),file);
    fread(d_array,count,sizeof(double),file);
    fclose(file);
    return count;
}

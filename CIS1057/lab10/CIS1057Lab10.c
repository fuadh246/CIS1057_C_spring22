/// Intro
/*
    Your task for this lab is to write an app that creates an expense report
    for The International Secret Intelligence Service (I.S.I.S.) and print it
    to screen.  Suggested sequence of work:

        1. Include necessary libraries/
        2. Write empty main() function/
        3. Write the Employee struct/
        4. Write the EmployeeList struct/
        5. Write create_employee_list() function/
        6. Test create_employee_list() in main/
        7. Write the read_employees(...)/
        8. Test read_employees(...) in main/
        9. Write print_employee(...)/
        10. Write print_employee_list(...)/
        11. Test print_employee_list(...) in main/

        *You should be able to read the employees into the list and print it
        to screen.

        12. Write the Expense struct/
        13. Write the ExpenseList struct/
        14. Write create_expense_list() function/
        15. Test create_expense_list() in main/
        16. Write the read_expenses(...)/
        17. Test read_expenses(...) in main/
        18. Write print_expense(...)/
        19. Write print_expense_list(...)/
        20. Test print_expense_list(...) in main/

        *You should be able to read the expenses into the list and print it
        to screen.

        21. Write the calc_expenses(...) function/
        22. Text calc_expenses(...) in main/

        *You should see the necessary output shown at the end of this file.
*/

/// Preprocessor statements
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100;

/// Structs
/*
    Note: that terms in '' are suggestions for variable names.
    The Employee struct stores data:
        The employee's 'id' as an integer
        The employee's 'name' as a string
        The employees 'position' (job title) as a string
        The employee's 'salary' as a double

    Also note: that all structs should be declared like:
        Employee e;
        NOT
        struct Employee e;

*/
typedef struct {
    int id;
    char name[20];
    char position[25];
    double salary;
} employee;
/*
    The EmployeeList struct stores a list of Employee:
        An 'array' of Employee
        The preallocated 'length' of the Employee array as integer
        The 'count' of the Employee inserted into array as integer
*/
typedef struct{
    employee employeeList[100];
    int length;
    int count;
}employeeList;
/*
    The Expense struct stores data:
        The expense line's 'employee_id' as an integer
        The expense's 'description' as a string
        The expense's 'cost' as a double
*/
typedef struct{
    int employee_id;
    char description[200];
    double cost;
}expense;

/*
    The ExpenseList struct stores a list of Expense:
        An 'array' of Expense
        The preallocated 'length' of the Expense array as integer
        The 'count' of the Expense inserted into array as integer
*/
typedef struct{
    expense expenseList[100];
    int length;
    int count;
}expenseList;
/// Prototypes
employeeList create_employee_list();
int read_employees(employeeList *firstList);
void employee_print(employee employee);
void print_employee_list(employeeList firstList);
expenseList create_expense_list();
int read_expenses(expenseList *firstexpenselist);
void expense_print(expense expense);
void print_expense_list(expenseList firstexpenselist);
void calc_expenses(employeeList *firstlist,expenseList *firstexpenselist);
/// Main
/*
    The main function should:
        Create an EmployeeList by calling create_employee_list()
        Read employees into EmployeeList by calling read_employees(...)
        Print the EmployeeList by calling print_employee_list(...)

        Create an ExpenseList by calling create_expense_list()
        Read expenses into ExpenseList by calling read_expenses(...)
        Print the ExpenseList by calling print_expense_list(...)

        Call calc_expenses(...) to compile and print expense report to screen
*/
int main(){
    //crate employeeList using create_employee_list function.
    employeeList firstList = create_employee_list();
    //read_employees method: read the employee info from a array into the our employeeList.
    read_employees(&firstList);
    printf("I.S.I.S. Employees\n");
    //print_employee_list method: print the employeeList.
    print_employee_list(firstList);
    //crate expenseList using create_expense_list function.
    expenseList firstexpenselist = create_expense_list();
    //rread_expenses method: read the expense info from a array into the our expenseList.
    read_expenses(&firstexpenselist);
    printf("I.S.I.S. Expenses\n");
    //print_expense_list method: print the employeeList.
    print_expense_list(firstexpenselist);
    //calc_expenses method: calculate the total expese for each and employee and print
    calc_expenses(&firstList,&firstexpenselist);
    return 0;
}


/// Create employee list
/*
    The create_employee_list() function accepts no arguments and
    returns an EmployeeList to the calling function.
    It should set the 'length' and 'count' to correct values.
*/
employeeList create_employee_list(){
    employeeList emList;
    emList.length=MAX;
    emList.count=0;
    return emList;
}


/// Read employees into list
/*
    The read_employees(...) function should accept an EmployeeList reference
    as an argument and return an integer with the correct count of employees
    in the list. The data below needs to be copied to an array if strings
    and then copied to the EmployeeList reference.

    "1|Archer, Malory|CEO|500000.0"
    "2|Archer, Sterling|Agent|250000.0"
    "3|Kane, Lana|Agent|300000.0"
    "4|Figus, Ceril|Accountant|100000.0"
    "5|Tunt, Cheryl|Secretary|65000.0"
    "6|Poovey, Pam|HR|85000.0"
*/
int read_employees(employeeList *firstList){
    char read_employees[10][100];
    int length = 6;
    stpcpy(read_employees[0],"1|Archer, Malory|CEO|500000.0");
    stpcpy(read_employees[1],"2|Archer, Sterling|Agent|250000.0");
    stpcpy(read_employees[2],"3|Kane, Lana|Agent|300000.0");
    stpcpy(read_employees[3],"4|Figus, Ceril|Accountant|100000.0");
    stpcpy(read_employees[4],"5|Tunt, Cheryl|Secretary|65000.0");
    stpcpy(read_employees[5],"6|Poovey, Pam|HR|85000.0");

    for (int i = 0; i <length; i++)
    {
        firstList->employeeList[i].id = atoi(strtok(read_employees[i], "|"));
        strcpy(firstList->employeeList[i].name, strtok(NULL, "|"));
        strcpy(firstList->employeeList[i].position, strtok(NULL, "|"));
        firstList->employeeList[i].salary = atof(strtok(NULL, "|"));
        firstList->count += 1;
    }
    return firstList->count;
}



/// Print employee to screen
/*
    The print_employee(...) function accepts an Employee as an argument and
    returns nothing.  It should prints the data as (for record 1):

        ID:        1
        Name:      Archer, Malory
        Position:  CEO
        Salary:    $500000.00
*/
void employee_print(employee employee){
    printf("ID:        %d\n",employee.id);
    printf("Name:      %s\n",employee.name);
    printf("Position:  %s\n",employee.position);
    printf("Salary:    $%.2f\n",employee.salary);
}


/// Print all employees to screen
/*
    The print_employee_list(...) function accepts an EmployeeList as an argument
    and returns nothing. It should print the list as:

        I.S.I.S. Employees

        ID:        1
        Name:      Archer, Malory
        Position:  CEO
        Salary:    $500000.00

        ID:        2
        Name:      Archer, Sterling
        Position:  Agent
        Salary:    $250000.00

        ID:        3
        Name:      Kane, Lana
        ...
*/
void print_employee_list(employeeList firstList){
	for(int i=0;i<6;i++){
		employee_print(firstList.employeeList[i]);
        printf("\n");
	}
    printf("\n");
}

/// Create expense list
/*
    The create_expense_list() function accepts no arguments and
    returns an ExpenseList to the calling function.
    It should set the 'length' and 'count' to correct values.
*/
expenseList create_expense_list(){
    expenseList exList;
    exList.length=MAX;
    exList.count=0;
    return exList;
}

/// Read expenses into list
/*
    The read_expenses(...) function should accept an ExpenseList reference
    as an argument and return an integer with the correct count of expenses
    in the list. The data below needs to be copied to an array if strings
    and then copied to the ExpenseList reference.

    "1,Dinner,456.23"
    "1,Air Travel,692.12"
    "1,Spa Day,725.00"
    "2,Bar Bill,392.34"
    "2,Glenghoulie Blue,320.00"
    "2,Bar Bill,523.54"
    "3,Explosives,550.00"
    "3,Firearms,2343.56"
    "3,Amunition,245.98"
    "4,Lunch,52.45"
    "4,Ledger,23.45"
    "5,Copy Paper,56.23"
    "5,Staples,12.09"
    "6,Milk,4.50"
    "6,Cheese,7.89"
*/
int read_expenses(expenseList *firstexpenselist){
    char read_expense[20][100];
    int length = 15;
    stpcpy(read_expense[0],"1,Dinner,456.23");
    stpcpy(read_expense[1],"1,Air Travel,692.12");
    stpcpy(read_expense[2],"1,Spa Day,725.00");
    stpcpy(read_expense[3],"2,Bar Bill,392.34");
    stpcpy(read_expense[4],"2,Glenghoulie Blue,320.00");
    stpcpy(read_expense[5],"2,Bar Bill,523.54");
    stpcpy(read_expense[6],"3,Explosives,550.00");
    stpcpy(read_expense[7],"3,Firearms,2343.56");
    stpcpy(read_expense[8],"3,Amunition,245.98");
    stpcpy(read_expense[9],"4,Lunch,52.45");
    stpcpy(read_expense[10],"4,Ledger,23.45");
    stpcpy(read_expense[11],"5,Copy Paper,56.23");
    stpcpy(read_expense[12],"5,Staples,12.09");
    stpcpy(read_expense[13],"6,Milk,4.50");
    stpcpy(read_expense[14],"6,Cheese,7.89");
    for (int i = 0; i <length; i++){
        firstexpenselist->expenseList[i].employee_id=atoi(strtok(read_expense[i], ","));
        strcpy(firstexpenselist->expenseList[i].description,strtok(NULL, ","));
        firstexpenselist->expenseList[i].cost=atof(strtok(NULL,","));
        firstexpenselist->count +=1;
    }
    return firstexpenselist->count;
}



/// Print expense to screen
/*
    The print_expense(...) function accepts an Expense as an argument and
    returns nothing.  It should prints the data as (for record 1):

        Employee ID:  1
        Description:  Air Travel
        Cost:         $692.12
*/
void expense_print(expense expense){
    printf("Employee ID:  %d\n",expense.employee_id);
    printf("Name:         %s\n",expense.description);
    printf("Salary:       $%.2f\n",expense.cost);
}



/// Print all expenses to screen
/*
    The print_expense_list(...) function accepts an ExpenseList as an argument
    and returns nothing. It should print the list as:

        I.S.I.S. Expenses

        Employee ID:  1
        Description:  Dinner
        Cost:         $456.23

        Employee ID:  1
        Description:  Air Travel
        Cost:         $692.12

        Employee ID:  1
        Description:  Spa Day
        ...
*/
void print_expense_list(expenseList firstexpenselist){
	for(int i=0;i<15;i++){
		expense_print(firstexpenselist.expenseList[i]);
        printf("\n");
	}
    printf("\n");
}


/// Calculate the expenses for each employee
/*
    The calc_expenses(...) function accepts the EmployeeList and ExpenseList as
    arguments and returns nothing. It should print an expense report for each
    employee.  It should loop through each employee, printing the employee's
    stated expenses and the total as shown below:

        1 Archer, Malory CEO $500000.00
                Dinner $456.23
                Air Travel $692.12
                Spa Day $725.00
        Total: $1873.35

        2 Archer, Sterling Agent $250000.00
                Bar Bill $392.34
                Glenghoulie Blue $320.00
                Bar Bill $523.54
        Total: $1235.88

        3 Kane, Lana Agent $300000.00
                Explosives $550.00
        ...
*/
void calc_expenses(employeeList *firstlist,expenseList *firstexpenselist){
    double totalcost = 0;
    for(int i=0;i<firstlist->count;i++){
        printf("%d %s %s $%.2f\n",firstlist->employeeList[i].id,firstlist->employeeList[i].name,firstlist->employeeList[i].position,firstlist->employeeList[i].salary);
        double totalcost = 0;
        for(int j=0;j<firstexpenselist->count;j++){
            if(firstlist->employeeList[i].id == firstexpenselist->expenseList[j].employee_id){
                printf("\t%s $%.2f\n",firstexpenselist->expenseList[j].description,firstexpenselist->expenseList[j].cost);
                totalcost += firstexpenselist->expenseList[i].cost;
            }
        }
        printf("Total: $%.2f\n",totalcost);
        printf("\n");
    }
}



/// Sample complete output from app
/*
I.S.I.S. Employees

ID:        1
Name:      Archer, Malory
Position:  CEO
Salary:    $500000.00

ID:        2
Name:      Archer, Sterling
Position:  Agent
Salary:    $250000.00

ID:        3
Name:      Kane, Lana
Position:  Agent
Salary:    $300000.00

ID:        4
Name:      Figus, Ceril
Position:  Accountant
Salary:    $100000.00

ID:        5
Name:      Tunt, Cheryl
Position:  Secretary
Salary:    $65000.00

ID:        6
Name:      Poovey, Pam
Position:  HR
Salary:    $85000.00

I.S.I.S. Expenses

Employee ID:  1
Description:  Dinner
Cost:         $456.23

Employee ID:  1
Description:  Air Travel
Cost:         $692.12

Employee ID:  1
Description:  Spa Day
Cost:         $725.00

Employee ID:  2
Description:  Bar Bill
Cost:         $392.34

Employee ID:  2
Description:  Glenghoulie Blue
Cost:         $320.00

Employee ID:  2
Description:  Bar Bill
Cost:         $523.54

Employee ID:  3
Description:  Explosives
Cost:         $550.00

Employee ID:  3
Description:  Firearms
Cost:         $2343.56

Employee ID:  3
Description:  Amunition
Cost:         $245.98

Employee ID:  4
Description:  Lunch
Cost:         $52.45

Employee ID:  4
Description:  Ledger
Cost:         $23.45

Employee ID:  5
Description:  Copy Paper
Cost:         $56.23

Employee ID:  5
Description:  Staples
Cost:         $12.09

Employee ID:  6
Description:  Milk
Cost:         $4.50

Employee ID:  6
Description:  Cheese
Cost:         $7.89

1 Archer, Malory CEO $500000.00
        Dinner $456.23
        Air Travel $692.12
        Spa Day $725.00
Total: $1873.35

2 Archer, Sterling Agent $250000.00
        Bar Bill $392.34
        Glenghoulie Blue $320.00
        Bar Bill $523.54
Total: $1235.88

3 Kane, Lana Agent $300000.00
        Explosives $550.00
        Firearms $2343.56
        Amunition $245.98
Total: $3139.54

4 Figus, Ceril Accountant $100000.00
        Lunch $52.45
        Ledger $23.45
Total: $75.90

5 Tunt, Cheryl Secretary $65000.00
        Copy Paper $56.23
        Staples $12.09
Total: $68.32

6 Poovey, Pam HR $85000.00
        Milk $4.50
        Cheese $7.89
Total: $12.39


Process returned 0 (0x0)   execution time : 1.642 s
Press any key to continue.

*/

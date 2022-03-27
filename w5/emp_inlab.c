//==============================================
// Name:           saddam faisal
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Section:        NII
// Workshop:       5 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 2


// Declare Struct Employee 
struct employee {
	int id;
	int age;
	double salary;
};


/* main program */
int main(void)
{
	int option = 0;
	int count = 0;
	int i = 0;
	struct employee emp[SIZE];

	// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero


	printf("---=== EMPLOYEE DATA ===---\n\n");



	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:	// Exit the program

			printf("Exiting Employee Data Program. Good Bye!!!\n");

			break;

		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0; i < SIZE; i++) {
				printf("   %d       %d   %.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
			}
			printf("\n");

			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0


			break;

		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 

			if (count > SIZE  - 1) {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
				break;
			}
			
				printf("Enter Employee ID: ");
				scanf("%d", &emp[count].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[count].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[count].salary);
				printf("\n");
			

			count++;

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	

	return 0;
}

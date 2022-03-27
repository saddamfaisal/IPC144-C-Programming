//==============================================
// Name:           saddam faisal
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Section:        NII
// Date:           
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"
//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Empty function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt: Empty function definition goes here:
int getInt(void)
{
	int Value;
	char NL = '\0';

	while (scanf("%d%c", &Value, &NL) != 2 || NL != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
	}

	return Value;
}


// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int limit;
	do
	{
		limit = getInt();

		if (min > limit || limit > max)
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	}

	while (min > limit || limit > max);
	return limit;

}


// yes: Empty function definition goes here:
int yes(void)
{
	char answer = '\0';
	char NL = '\0';

	while
		(scanf(" %c%c", &answer, &NL) != 2 || NL != '\n')
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
	}

	if (answer == 'Y' || answer == 'y')
	{
		return 1;
	}
	else if (answer == 'N' || answer == 'n')
	{
		return 0;
	}
	return 0;
}


// menu: Empty function definition goes here:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	//printf("\n");
	return getIntInRange(0, 6);

}


// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int a;
	int option;
	do
	{
		switch (option = menu())
		{
		case 0:
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			a = yes();
			printf("\n");
			if (a == 1)
			{
				printf("Contact Management System: terminated\n");
			}
			else if (a == 0)
			{
				option = 1;
			}

			break;
		case 1:
			printf("\n");
			printf("<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");

			break;
		case 2:
			printf("\n");
			printf("<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");

			break;
		case 3:
			printf("\n");
			printf("<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");

			break;
		case 4:
			printf("\n");
			printf("<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");

			break;
		case 5:
			printf("\n");
			printf("<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");

			break;
		case 6:
			printf("\n");
			printf("<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");

			break;
		default:
break;


		;	
		}
	} while (option != 0);
}

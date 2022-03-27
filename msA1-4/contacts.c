/* -------------------------------------------
Name:saddam faisal
Student number:
Email:sfaisal6@myseneca.ca
Section:NII

----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"



// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* name)
{
	char a;
	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]s%*c", name[0].firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &a);
	if (a == 'Y' || a == 'y')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]s%*c", name[0].middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]s%*c", name[0].lastName);
}



// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address* address)
{
	char b;
	do
	{
		printf("Please enter the contact's street number: ");
		scanf("%d", &address[0].streetNumber);
		if (address[0].streetNumber < 1)
		{
			printf("Invalid entry. Street number must be equal to or greater than one.\n");
		}
	} while (address[0].streetNumber < 1);

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]s%*c", address[0].street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &b);
	if (b == 'Y' || b == 'y')
	{
		do
		{
			printf("Please enter the contact's apartment number: ");
			scanf("%d", &address[0].apartmentNumber);
			if (address[0].apartmentNumber < 1)
			{
				printf("Invalid entry. Apartment number must be equal to or greater than one.\n");
			}
		} while (address[0].apartmentNumber < 1);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]s%*c", address[0].postalCode);

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]s%*c", address[0].city);
}



// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers* numbers)
{
	char c;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &c);
	if (c == 'Y' || c == 'y')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf(" %10[^\n]s%*c", numbers[0].cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &c);
	if (c == 'Y' || c == 'y')
	{
		printf("Please enter the contact's home phone number: ");
		scanf(" %10[^\n]s%*c", numbers[0].home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &c);
	if (c == 'Y' || c == 'y')
	{
		printf("Please enter the contact's business phone number: ");
		scanf(" %10[^\n]s%*c", numbers[0].business);
	}
	printf("\n");
}

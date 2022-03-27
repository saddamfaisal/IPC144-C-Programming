//==============================================
// Name:           saddam faisal
// Student Number: #########
// Email:          sfaisal6@myseneca.ca
// Section:        NII
// Date:           
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"
#include"contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
void getName(struct Name* name)
{
	int a;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	a = yes();
	if (a == 1)
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
	}
	clearKeyboard();

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
	clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
	int a;

	do
	{
		printf("Please enter the contact's street number: ");
		scanf("%d", &address->streetNumber);
		getInt();
		if (address->streetNumber < 1)
		{
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
			//address->streetnumber = getint(); instead of scanf
			scanf("%d", &address->streetNumber);
		}
	} while (address->streetNumber < 1);

	printf("Please enter the contact's street name: ");
	scanf(" %40[^\n]", address->street);
	clearKeyboard();

	printf("Do you want to enter an apartment number? (y or n): ");
	a = yes();
	if (a == 1)
	{
		do
		{
			printf("Please enter the contact's apartment number: ");
			scanf("%d", &address->apartmentNumber);

			if (address->apartmentNumber < 1)
			{
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
				scanf("%d", &address->apartmentNumber);
			}
		} while (address->apartmentNumber < 1);
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %40[^\n]", address->city);
	clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
	int a;

	printf("Please enter the contact's cell phone number: ");
	scanf(" %10[^\n]", numbers->cell);
	clearKeyboard();

	printf("Do you want to enter a home phone number? (y or n): ");
	a = yes();
	if (a == 1)
	{
		printf("Please enter the contact's home phone number: ");
		scanf(" %10[^\n]", numbers->home);
		clearKeyboard();
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	a = yes();
	if (a == 1)
	{
		printf("Please enter the contact's business phone number: ");
		scanf(" %10[^\n]", numbers->business);
		clearKeyboard();
	}

}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}

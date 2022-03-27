//==============================================
// Name:           saddam faisal
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Section:        NII
// Date:           
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
void clear()

{
	while (getchar() != '\n');
}


int main(void)
{
	// Declare variables here:

	struct Name SName = { {0} };
	struct Address SAddress = { 0,{0},0,{0},{0} };
	struct Numbers SNumbers = { {0} };
	char ch1, ch2, ch3, ch4, ch5;
	// Display the title

	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]s",SName.firstName);
	clear();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%c",&ch1);
	clear();
	if (ch1 == 'y' || ch1 == 'Y') 
	{



		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]s",SName.middleInitial);
	}
	clear();
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]s",SName.lastName);

	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d",&SAddress.streetNumber);
	clear();
	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]s",SAddress.street);
	clear();


	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%c",&ch2);

	if (ch2 == 'y' || ch2 == 'Y') 
	{




		printf("Please enter the contact's apartment number: ");
		scanf("%d",&SAddress.apartmentNumber);
		clear();
	}
	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]s",SAddress.postalCode);
	clear();

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]s",SAddress.city);
	clear();


	// Contact Numbers Input:

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%c",&ch3);
	clear();
	if (ch3 == 'y' || ch3 == 'Y') 
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%10[^\n]s",SNumbers.cell);
	} clear();

	// home 
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%c",&ch4);
	clear();
	if (ch4 == 'y' || ch4 == 'Y') 
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%10[^\n]",SNumbers.home);
	}
	clear();

	//business
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%c",&ch5);
	clear();
	if (ch5 == 'y' || ch5 == 'Y') 
	{

		printf("Please enter the contact's business phone number: ");
		scanf("%10[^\n]s",SNumbers.business);
	}
	clear();

	// Display Contact Summary Details

	printf("\nContact Details\n");
	printf("---------------\n");

	printf("Name Details:\n");
	printf("First name: %s\n", SName.firstName);
	
	if (ch1 ==  'y' || ch1 == 'Y')
	{
	printf("Middle initial(s): %s\n", SName.middleInitial);


	}
	
	printf("Last name: %s\n\n", SName.lastName);
	
	

	printf("Address Details:\n");

	printf("Street number: %d\n", SAddress.streetNumber);
	printf("Street name: %s\n", SAddress.street);
	if (ch2 == 'y' || ch2 == 'Y')
	{
	printf("Apartment: %d\n", SAddress.apartmentNumber);
	}
	printf("Postal code: %s\n", SAddress.postalCode);
	printf("City: %s\n\n", SAddress.city);
	

	printf("Phone Numbers:\n");
	if (ch3 == 'y' || ch3 == 'Y')
	{
		printf("Cell phone number: %s\n", SNumbers.cell);
	}
	if (ch4 == 'y' || ch4 == 'Y')
	{
		printf("Home phone number: %s\n", SNumbers.home);
	}
	if (ch5 == 'y' || ch5 == 'Y')
	{
		printf("Business phone number: %s\n\n", SNumbers.business);

		
	}

	// Display Completion Message
	printf("Structure test for Name, Address, and Numbers Done!\n");


	return 0;

}


/*  SAMPLE OUTPUT:

	Contact Management System
	-------------------------
	Please enter the contact's first name: Tom
	Do you want to enter a middle initial(s)? (y or n): y
	Please enter the contact's middle initial(s): L. A.
	Please enter the contact's last name: Wong Song
	Please enter the contact's street number: 20
	Please enter the contact's street name: Keele Street
	Do you want to enter an apartment number? (y or n): y
	Please enter the contact's apartment number: 40
	Please enter the contact's postal code: A8A 4J4
	Please enter the contact's city: North York
	Do you want to enter a cell phone number? (y or n): Y
	Please enter the contact's cell phone number: 9051116666
	Do you want to enter a home phone number? (y or n): Y
	Please enter the contact's home phone number: 7052227777
	Do you want to enter a business phone number? (y or n): Y
	Please enter the contact's business phone number: 4163338888

	Contact Details
	---------------
	Name Details:
	First name: Tom
	Middle initial(s): L. A.
	Last name: Wong Song

	Address Details:
	Street number: 20
	Street name: Keele Street
	Apartment: 40
	Postal code: A8A 4J4
	City: North York

	Phone Numbers:
	Cell phone number: 9051116666
	Home phone number: 7052227777
	Business phone number: 4163338888

	Structure test for Name, Address, and Numbers Done!
*/
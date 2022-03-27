//==============================================
// Name:  saddam faisal
// Student Number: 118406198
// Email:          Sfaisal6@myseneca.ca
// Section:        NII
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int loonies, quarters, dimes, nickels, pennies;
	double amount, balance1, balance2, balance3, balance4,balance5, gst, newamount;
	
	printf ("Please enter the amount to be paid: $");// ask output
	scanf("%lf", &amount);//ask input
	gst = amount * 0.13 + 0.005;//gst
	newamount = amount + gst;
	printf("GST: %.2lf\n", gst);// ask output
	printf("Balance owing: $%.2lf\n", newamount);// askoutput for the newamount=9.81
	loonies = (int) newamount;// casting
	balance1 = newamount - loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies,balance1);


	balance1 = balance1 * 100;// =81
	quarters = (int) balance1 / 25;// =81 /25=3.6
	balance2 = (int)balance1 % 25;
	printf("Quarters required : %d, balance owing $%.2lf\n", quarters,balance2 / 100); 
  
	dimes = (int) balance2 / 10;
	balance3 = (int) balance2 % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, balance3 / 100);

	nickels = (int) balance3 / 5;
	balance4 = (int) balance3 % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, balance4/100);

	pennies = (int)balance4 / 1;
	balance5 = (int)balance4 % 1;
	printf("Pennies required: %d, balance owing $%.2lf", pennies,balance5 /100);


	return 0;


}


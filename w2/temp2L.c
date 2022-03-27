//==============================================
// Name:           saddam faisal
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Section:        NII
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
int main(void)
{
	int i;
	int days = 4;
	int hightemp[10];
	int lowtemp[10];
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n");

	while (days < 3 || days >10) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");
	}

	for (i = 0; i < days; i++) {
		printf("Day %d - High: ", i+1);
		scanf("%d", &hightemp[i]);
		printf("Day %d - Low: ", i+1);
		scanf("%d", &lowtemp[i]);
	}
	printf("\n");
	printf("Day  Hi  Low\n");

	for (i = 0; i < days; i++)
		printf("%d    %d    %d\n", i+1, hightemp[i], lowtemp[i]);


	return 0;
}
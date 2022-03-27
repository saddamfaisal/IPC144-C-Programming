//==============================================
// Name:           saddam faisal
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Section:        NII
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
#include <stdio.h>
int main()
{
	int i;
	int days;
	int hightemp[10];
	int lowtemp[10];
	int maxvalue = 0;
	int highestday = 0;
	int minvalue = 0;
	int lowestday = 0;
	int averagehigh = 0;
	int averagelow = 0;
	int meanday = 0;
	double mean = 0.00;
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	

	while (days < 3 || days >10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}
	printf("\n");
	for (i = 0; i < days; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &hightemp[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lowtemp[i]);
	}

	printf("\nDay  Hi  Low\n");

	for (i = 0; i < days; i++)
	{
		printf("%d    %d    %d\n", i + 1, hightemp[i], lowtemp[i]);

	}

	maxvalue = hightemp[0];
	minvalue = lowtemp[0];
	for (i = 0; i < days; i++)
	{
		if (maxvalue < hightemp[i]) {
			maxvalue = hightemp[i];
			highestday = i + 1;
		}


		if (minvalue > lowtemp[i]) {
			minvalue = lowtemp[i];
			lowestday = i + 1;
		}
	}
	printf("\nThe highest temperature was %d, on day %d\n", maxvalue, highestday);
	printf("The lowest temperature was %d, on day %d\n", minvalue, lowestday);





	do {
		averagehigh = 0, averagelow = 0;
		    printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &meanday);
		while (meanday > days || meanday == 0) {
			printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf("%d", &meanday);
		}
		if (meanday > 0) {
			for (i = 0; i < meanday; i++) {
				averagehigh += hightemp[i];
				averagelow += lowtemp[i];
			}
				mean = (double)(averagehigh + averagelow) /(meanday *2);
			

			printf("\nThe average temperature up to day %d is: %.2lf\n", meanday, mean);
		}
	} while (meanday > 0);
	printf("\nGoodbye!\n");
	
	return 0;
}
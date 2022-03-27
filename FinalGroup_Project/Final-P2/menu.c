/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)SIRAN CHEN                 schen214@myseneca.ca
   2)SADDAM FAISAL              sfaisal6@myseneca.ca
   3)AHMAD SHAHZEB              ASHAHZEB@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: menu.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "menu.h"


int menu()
{
	int options=0;

	printf("What would you like to do?\n"
		"0 - Exit\n"\
		"1 - Print top 3 riders in a category\n"
		"2 - Print all riders in a category\n"
		"3 - Print last 3 riders in a category\n"
		"4 - Print winners in all categories\n"
		": ");
	while (1) {
		int result = scanf("%d", &options);
		if (options >= 0 && options <= 4 && result != 0) {
			break;
		}
		scanf("%*[^\n]");
		printf("Incorrect option, try again: ");
	}

	return options;
}

char chooseCategory() {
	char options=0;
	printf("\nWhich category (S, M, L): ");
	while (1) {
		int result = scanf(" %c", &options);
		if (result != 0) {
			switch (options) {
			case 's':
			case 'S':
			case 'm':
			case 'M':
			case 'l':
			case 'L':
				return options;
			}
		}
		scanf("%*[^\n]");
		printf("Incorrect option, try again: ");
	}
}

void displayrider(struct RiderInfo* rider, int show_cat, int show_withdrow) {
	char age[10] = "N/A";
	if (16 <= rider->age && rider->age <= 20) {
		strcpy(age, "   Junior");
	}
	else if (21 <= rider->age && rider->age <= 34) {
		strcpy(age, "    Adult");
	}
	else if (35 <= rider->age) {
		strcpy(age, "   Senior");
	}
	printf("%-30s%-10s", rider->name, age);
	if (show_cat) {
		char len[10] = "  N/A";
		switch (rider->raceLength)
		{
		case 's':
		case 'S':
			strcpy(len, "  50 km");
			break;
		case 'm':
		case 'M':
			strcpy(len, "  75 km");
			break;
		case 'l':
		case 'L':
			strcpy(len, " 100 km");
			break;
		}
		printf("%-10s", len);
	}
	double time = rider->finishTime - rider->startTime;
	double hours = (double)time;
	float minutes = (time - (int)time) * 60;

	if (rider->withdrawn) {
		printf("   N/A");
	}
	else {
		printf(" %2d:%02d", (int)hours, (int)minutes);
	}
	if (show_withdrow) {
		if (rider->withdrawn) {
			printf("%10s", "Yes");
		}
		else {
			printf("%10s", "No");
		}
	}
	printf("\n");
}

void displayriders(struct RiderInfo riders[], int index[], int index_len) {
	int show_category = 0;
	int show_withdrow = 0;
	int s = 0, m = 0, l = 0;
	for (int i = 0; i < index_len; i++) {
		if (riders[index[i]].withdrawn == 1) {
			show_withdrow = 1;
		}
		switch (riders[index[i]].raceLength) {
		case 's':
		case 'S':
			s = 1;
			break;
		case 'm':
		case 'M':
			m = 1;
			break;
		case 'l':
		case 'L':
			l = 1;
			break;
		}
	}
	if (s + m + l > 1) {
		show_category = 1;
	}

	printf("\n");
	int len = 0;
	printf("%-30s%-10s", "Rider", "Age Group");
	len += 40;
	if (show_category == 1) {
		printf("%-10s", "Category");
		len += 10;
	}
	printf("%6s", "Time");
	len += 6;
	if (show_withdrow) {
		printf("%10s", "Withdrew");
		len += 10;
	}
	printf("\n");
	for (int i = 0; i < len; i++) {
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < index_len; i++) {
		displayrider(&riders[index[i]], show_category, show_withdrow);
	}
	printf("\n");
}

int compare_riders(struct RiderInfo* r1, struct RiderInfo* r2)
{
	double t1 = r1->finishTime - r1->startTime;
	double t2 = r2->finishTime - r2->startTime;
	int change = 0;
	if (r1->withdrawn == 0 && r2->withdrawn == 0) {
		if (t1 < t2) {
			change = 0;
		}
		else if (t1 == t2) {
			if (r1->mountainTime < r2->mountainTime) {
				change = 0;
			}
			else {
				change = 1;
			}
		}
		else {
			change = 1;
		}
	}
	else if (r1->withdrawn == 1) {
		change = 1;
	}
	return change;
}

void change_riders(struct RiderInfo* r1, struct RiderInfo* r2)
{
	struct RiderInfo tmp;
	tmp = *r1;
	*r1 = *r2;
	*r2 = tmp;
}

int find_size(struct RiderInfo riders[], int MAX) {
	int i;
	for (i = 0; i < MAX; i++) {
		if (riders[i].raceLength == 0) {
			break;
		}
	}
	return i;
}

void sort_riders(struct RiderInfo riders[], int MAX)
{
	int size = find_size(riders, MAX);
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (compare_riders(&riders[j - 1], &riders[j])) {
				change_riders(&riders[j - 1], &riders[j]);
			}
		}
	}
}

int find_category(struct RiderInfo riders[], int MAX, int index[], char category, int no_withdraw) {
	int size = find_size(riders, MAX);
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (riders[i].raceLength == toupper(category) && (!no_withdraw || !riders[i].withdrawn)) {
			index[j] = i;
			j++;
		}
	}
	return j;
}

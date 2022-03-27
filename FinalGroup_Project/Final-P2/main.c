/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)SIRAN CHEN                 schen214@myseneca.ca
   2)SADDAM FAISAL              sfaisal6@myseneca.ca
   3)AHMAD SHAHZEB              ASHAHZEB@myseneca.ca
   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#define SIZE 5000

#include "file_helper.h"
#include "menu.h"


int main(void)
{
	// TODO: Code the necessary logic for your solution below
	//
	// NOTE: Use modularity whenever possible in your design
	//
	// HINTS:
	// 1) You will need to load the file data and store
	//    it to a data structure array 
	//    (MUST USE: provided "readFileRecord" function)
	//
	// 2) Create a menu system to provide the user with
	//    the reporting options
	//
	// 3) Generate the user-selected report
	

	printf("******************** Seneca Cycling Race Results ********************\n");
	FILE* fp = NULL;
    fp = fopen("data.txt", "r");
	struct RiderInfo riders[SIZE] = { 0 };
	struct RiderInfo winners[3];
	int index[SIZE];
	char category;
	int i = 0;
	int len;

	while (readFileRecord(fp, &riders[i]) == 0 && i < SIZE) {
		i++;
	}

	sort_riders(riders, SIZE);

	while (1)
	{
		switch (menu()) {
		case 1:
			category = chooseCategory();
			len = find_category(riders, SIZE, index, category, 1);
			if (len > 3) {
				len = 3;
			}
			displayriders(riders, index, len);
			break;
		case 2:
			category = chooseCategory();
			len = find_category(riders, SIZE, index, category, 0);
			displayriders(riders, index, len);
			break;
		case 3:
			category = chooseCategory();
			len = find_category(riders, SIZE, index, category, 1);
			int begin = len > 3 ? len - 3 : 0;
			displayriders(riders, &index[begin], len-begin);
			break;
		case 4:
			i = 0;
			len = find_category(riders, SIZE, index, 's', 1);
			if (len > 0) {
				winners[i] = riders[index[0]];
				i++;
			}
			len = find_category(riders, SIZE, index, 'm', 1);
			if (len > 0) {
				winners[i] = riders[index[0]];
				i++;
			}
			len = find_category(riders, SIZE, index, 'l', 1);
			if (len > 0) {
				winners[i] = riders[index[0]];
				i++;
			}
			int ind[] = { 0, 1, 2 };
			displayriders(winners, ind, i);
			break;
		case 0:
			printf("\nKeep on Riding!\n");
			return 0;
		}
	}

}
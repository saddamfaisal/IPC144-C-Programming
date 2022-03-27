/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)SIRAN CHEN                 schen214@myseneca.ca
   2)SADDAM FAISAL              sfaisal6@myseneca.ca
   3)AHMAD SHAHZEB              ASHAHZEB@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: menu.h                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#include "file_helper.h"

Header();

int menu();

char chooseCategory();

void displayriders(struct RiderInfo riders[], int indexes[], int indexes_len);

void sort_riders(struct RiderInfo riders[], int size);

int find_category(struct RiderInfo riders[], int MAX, int indexes[], char category, int no_withdraw);
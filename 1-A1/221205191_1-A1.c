/*
 *クラス：B
 *学籍番号：221205191
 *氏名：和藤佑
*/


#include <stdio.h>

int isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main() {
    for (int year = 1970; year <= 2120; year++) {
        if (year >= 1948 && (year - 1948) % 4 == 0) {
            printf("%d: olympic", year);
            if (isLeapYear(year)) {
                printf(" leap year");
            }
            printf("\n");
        }
        else if (isLeapYear(year)) {
            printf("%d: leap year\n", year);
        }
        else {
            printf("%d:\n", year);
        }
    }

    return 0;
}

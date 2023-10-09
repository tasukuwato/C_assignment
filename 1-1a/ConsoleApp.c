/*
 *クラス：B
 *学籍番号：221205191
 *氏名：和藤佑
*/

#include <stdio.h>

int main() {
    int i, j;

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            int result = i * j;
            printf("%d * %d = %d\n", i, j, result);
        }
    }

    return 0;
}

/*
 *クラス：B
 * 学籍番号：221205191
 * 氏名：和藤佑
 */#include <stdio.h>

int main() {
    int i, j;

    for (i = 9; i >= 1; i--) {
        for (j = 9; j >= i; j--) {
            int result = i * j;
            printf("%d * %d = %d\n", i, j, result);
        }
    }

    return 0;
}

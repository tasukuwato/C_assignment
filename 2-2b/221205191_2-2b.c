/*
*クラス：B
*学籍番号：221205191
*氏名：和藤佑
*/

#include <stdio.h>
#define N (3)

void transpose(int matrix[N][N]) {
	//行列の転置操作を記述
	int i, j;
	int transposed[N][N];

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			transposed[j][i] = matrix[i][j];
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			matrix[i][j] = transposed[i][j];
		}
	}
}

int main(void) {
	int i, j;
	int x[N][N] = { {2,0,5},{1,4,6},{8,7,3} };
	printf("Before:\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}
	transpose(x);

	printf("After:\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) { //ループ条件に誤りがあると判断したため修正しました
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}
	return 0;
}

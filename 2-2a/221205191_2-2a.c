/*
*クラス：B
*学籍番号：221205191
*氏名：和藤佑
*/

#include <stdio.h>
#define N (3)

int main(void) {
	int i, j;
	int x[N][N] = { {2,0,5},
					{1,4,6},
					{8,7,3} };

	int transposed[N][N]; //行列を一時的に格納するための配列

	printf("Before:\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}

	//行列の転置操作
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			transposed[j][i] = x[i][j];
		}
	}

	// 転置行列を元の行列にコピー
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			x[i][j] = transposed[i][j];
		}
	}

	printf("After:\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}
	return 0;
}
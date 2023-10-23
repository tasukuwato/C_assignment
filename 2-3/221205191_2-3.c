/*
*クラス：B
*学籍番号:221205191
*氏名：和藤佑
*/

#include <stdio.h>
#include <stdlib.h>
#define N (5)

int compare(const void* a, const void* b) {
	double arg1 = *(const double*)a;
	double arg2 = *(const double*)b;

	if (arg1 < arg2) return -1;
	if (arg1 > arg2) return 1;
	return 0;
}


int main(void) {
	double x[N] = { 178.1, 185.2, 175.3, 168.9, 178.5 };
	double m;

	// 配列をソート
	qsort(x, N, sizeof(double), compare);

	// 中央値の計算
	if (N % 2 == 0) {
		// Nが偶数の場合
		m = (x[N / 2 - 1] + x[N / 2]) / 2.0;
	}
	else {
		// Nが奇数の場合
		m = x[N / 2];
	}

	printf("Median = %.2f\n", m);
	return 0;
}
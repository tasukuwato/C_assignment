/*
 *クラス：B
 * 学籍番号：221205191
 * 氏名：和藤佑
 */


#include <stdio.h>
#include <math.h>  // 数学関数ライブラリをインクルード
#define N (3)

int main(void) {
    double x[N] = { 5.6, 0.3, 1.8 };
    double var = 0.0;  // 分散を初期化

    // 平均を計算
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += x[i];
    }
    double mean = sum / N;

    // 分散を計算
    for (int i = 0; i < N; i++) {
        var += pow(x[i] - mean, 2);  // (データ - 平均)^2 を累積
    }
    var /= N;  // データ数で割る

    printf("分散 = %.2f\n", var);
    return 0;
}

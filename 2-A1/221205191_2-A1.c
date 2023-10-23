/*
*クラス：B
*学籍番号：221205191
*氏名：和藤佑
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char msgs[][20] = { "Welcome", "to", "Meijo", "University" };
	char out[1000] = { 0 };

	// 最初の単語をコピー
	strcpy(out, msgs[0]);

	// 残りの単語を連結
	for (int i = 1; i < sizeof(msgs) / sizeof(msgs[0]); i++) {
		strcat(out, " "); // 単語の間に空白を追加
		strcat(out, msgs[i]);
	}


	printf("<<%s>>\n", out);
	return EXIT_SUCCESS;
}
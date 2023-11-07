/*
*クラス：B
*学籍番号：221205191
*氏名：和藤佑
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_strdup(const char* str) {

	//文字列の長さを取得して、それにヌル文字の分、1バイト追加する
	size_t len = strlen(str) + 1;


	//メモリ確保
	char* new_str = (char*)malloc(len);

	//メモリ確保が出来ているか確認
	if (new_str == NULL) {
		return NULL;
	}

	//新しいメモリ領域のアドレスを返す
	strcpy(new_str, str);

	return new_str;
}

int main(void) {
	char* s1 = "Meijo University";
	char* s2 = NULL;

	s2 = my_strdup(s1);

	/* 各々が格納されている領域のアドレスは異なる */
	printf("Address of s1 = %p¥n", s1);
	printf("Address of s2 = %p¥n", s2);

	/* しかし内容は同一 */
	printf("s1 = %s¥n", s1);
	printf("s2 = %s¥n", s2);

	/* strdup() 関数が作ったコピーのメモリ領域を解放 */
	free(s2);
	s2 = NULL;

	return 0;
}
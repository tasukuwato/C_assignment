/*
*クラス：B
*学籍番号：221205191
*氏名：和藤佑
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME (30)
#define N (5)

struct person {
	char name[MAX_NAME]; /* 名前 */
	int age; /* 年齢 */
};

int compare_person(const void* p, const void* q) {

	const struct person* p1 = p;
	const struct person* p2 = q;

	//年齢で比較
	if (p1->age < p2->age) return -1;
	if (p1->age > p2->age) return 1;

	//年齢が同じ場合は名前で比較
	return strcmp(p1->name, p2->name);
}

int main(void) {
	struct person a[N] = {
		{"Shiogama Hanako", 23},
		{"Shiogama Saburo", 22},
		{"Yagoto Shiro", 22},
		{"Meijo Taro", 25},
		{"Meijo Jiro", 22}
	};
	int i;

	qsort(a, N, sizeof(struct person),
				compare_person);

	for (i = 0; i < N; i++) {
		printf("(name=%s, age=%d)\n",
			a[i].name, a[i].age);
	}

	return 0;
}
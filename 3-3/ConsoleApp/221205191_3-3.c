/*
*クラス：B
*学籍番号：221205191
*氏名：和藤佑
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 3  // 一人の人物が購入できる書籍の上限
#define MAX_PERSONS 3 // 一冊の書籍を購入できる人数の上限

typedef struct person {
    char* name;      // 名前
    int age;         // 年齢
    struct book** books;  // 購入した書籍のポインタの配列
    int n_books;     // 購入した書籍の数
} *PersonPtr;

typedef struct book {
    char* title;     // タイトル
    int price;       // 価格
    PersonPtr* persons; // 購入者
    int n_persons;   // 購入者数
} *BookPtr;

PersonPtr new_person(char* name, int age) {
    PersonPtr u = malloc(sizeof(*u));
    u->name = strdup(name);
    u->age = age;
    u->books = malloc(MAX_BOOKS * sizeof(*u->books));
    u->n_books = 0;
    return u;
}

void delete_person(PersonPtr u) {
    if (u != NULL) {
        free(u->name);
        free(u->books);
        free(u);
    }
}

BookPtr new_book(char* title, int price) {
    BookPtr b = malloc(sizeof(*b));
    b->title = strdup(title);
    b->price = price;
    b->persons = malloc(MAX_PERSONS * sizeof(*b->persons));
    b->n_persons = 0;
    return b;
}

void delete_book(BookPtr b) {
    if (b != NULL) {
        free(b->title);
        free(b->persons);
        free(b);
    }
}

void buy(PersonPtr u, BookPtr b) {
    if (u && b && u->n_books < MAX_BOOKS) {
        u->books[u->n_books] = b;
        u->n_books++;
        if (b->n_persons < MAX_PERSONS) {
            b->persons[b->n_persons] = u;
            b->n_persons++;
        }
    }
}

void print_person(PersonPtr u) {
    if (u != NULL) {
        printf("名前: %s, 年齢: %d, 購入した書籍数: %d\n", u->name, u->age, u->n_books);
    }
}

double get_avg_price(PersonPtr u) {
    if (u == NULL || u->n_books == 0) return 0.0;

    int sum = 0;
    for (int i = 0; i < u->n_books; i++) {
        sum += u->books[i]->price;
    }
    return (double)sum / u->n_books;
}

double get_avg_age(BookPtr b) {
    if (b == NULL || b->n_persons == 0) return 0.0;

    int sum = 0;
    for (int i = 0; i < b->n_persons; i++) {
        sum += b->persons[i]->age;
    }
    return (double)sum / b->n_persons;
}

int compare_avg_price(const void* a, const void* b) {
    PersonPtr pa = *(PersonPtr*)a;
    PersonPtr pb = *(PersonPtr*)b;
    double avg_price_a = get_avg_price(pa);
    double avg_price_b = get_avg_price(pb);
    if (avg_price_a < avg_price_b) return 1; // 降順にするための比較
    if (avg_price_a > avg_price_b) return -1;
    return 0;
}

int main(void) {
    PersonPtr u1 = new_person("名城太郎", 20);
    PersonPtr u2 = new_person("東京次郎", 22);
    PersonPtr u3 = new_person("京都三郎", 24);
    PersonPtr u4 = new_person("大阪四郎", 19);
    PersonPtr u5 = new_person("名古屋五郎", 30);

    BookPtr b1 = new_book("我輩は猫である", 500);
    BookPtr b2 = new_book("坊っちゃん", 400);
    BookPtr b3 = new_book("こころ", 300);

    buy(u1, b1);
    buy(u1, b2);
    buy(u2, b1);
    buy(u3, b3);
    buy(u4, b2);
    buy(u5, b3);

    // 人物データの配列
    PersonPtr persons[] = { u1, u2, u3, u4, u5 };
    int num_persons = sizeof(persons) / sizeof(persons[0]);

    // 全ての人物について print_person() を呼び出す
    for (int i = 0; i < num_persons; i++) {
        print_person(persons[i]);
    }

    // 名城太郎の購入書籍の平均価格を表示
    printf("名城太郎の購入書籍の平均価格: %.2f\n", get_avg_price(u1));

    // "我輩は猫である" の購入者の平均年齢を表示
    printf("「我輩は猫である」の購入者の平均年齢: %.2f\n", get_avg_age(b1));

    // 人物を平均価格の降順でソート
    qsort(persons, num_persons, sizeof(PersonPtr), compare_avg_price);

    // ソート後の人物を表示
    printf("\n平均価格の降順にソートされた人物:\n");
    for (int i = 0; i < num_persons; i++) {
        print_person(persons[i]);
    }

    // データのクリーンアップ
    for (int i = 0; i < num_persons; i++) {
        delete_person(persons[i]);
    }

    delete_book(b1);
    delete_book(b2);
    delete_book(b3);

    return 0;
}
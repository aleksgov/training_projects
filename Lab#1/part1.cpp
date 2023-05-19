#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
int x;
float y;
bool t = true, f = false;
char w;
int main()
{
	setlocale(LC_ALL, "Russian");

	printf("Введите символ: ");
	scanf("%c", &w);
	printf("Ваш символ: %c\n", w);

	printf("Введите целое число: ");
	scanf("%d", &x);
	printf("Ваше число: %d\n", x);

	printf("Введите вещественное число: ");
	scanf("%f", &y);
	printf("Ваше число: %f\n", y);

	printf("t & f = %d\n", t & f);
	printf("t | f = %d\n", t | f);
	printf("t ^ f = %d\n", t ^ f);

	return 0;
}

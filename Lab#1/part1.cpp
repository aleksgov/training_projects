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

	printf("������� ������: ");
	scanf("%c", &w);
	printf("��� ������: %c\n", w);

	printf("������� ����� �����: ");
	scanf("%d", &x);
	printf("���� �����: %d\n", x);

	printf("������� ������������ �����: ");
	scanf("%f", &y);
	printf("���� �����: %f\n", y);

	printf("t & f = %d\n", t & f);
	printf("t | f = %d\n", t | f);
	printf("t ^ f = %d\n", t ^ f);

	return 0;
}

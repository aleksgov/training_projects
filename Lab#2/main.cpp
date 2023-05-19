#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int FirstProgram() {
    int n, m;
    printf("Введите размер массива (n, m) >> ");
    scanf("%d %d", &n, &m);

    // Выделение памяти для массива
    int** mas = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        mas[i] = (int*)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("[%d][%d] = ", i, j);
            scanf("%d", &mas[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("\t%d", mas[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mas[i][j] == 0) {
                printf("Строка %d содержит ноль\n", i + 1);
                break;
            }
        }
    }
    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        free(mas[i]);
    }
    free(mas);

    return 0;
}

int SecondProgram()
{
    int maxc = 0, count = 0;
    char string[100];
    printf("Введите строку\n>> ");
    scanf(" %[^\n]%*c", string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == ' ')
        {
            count++;
            if (maxc < count)
            {
                maxc = count;
            }
        }
        if (string[i] != ' ')
        {
            count = 0;
        }
    }
    printf("Максимум пробелов - %d\n", maxc);
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int op;
    printf("Выберите задание\n1. Нахождение нулевых строк\n2. Нахождение числа максимального количества пробелов в строке\n>> ");
    scanf("%d", &op);
    if (op == 1) {
        FirstProgram();
    }
    if (op == 2) {
        SecondProgram();
    }
    return 0;
}

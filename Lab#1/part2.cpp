#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n, i;
    printf("Enter your number: ");
    scanf("%d", &n);
    printf("Enter the value of the i-th bit: ");
    scanf("%d", &i);
    printf("Your meaning: %d", (n >> i) & 1u);
    return 0;
}


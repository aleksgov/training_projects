#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
typedef struct tagITEM
{
    char Surname[20], Country[20];
    int Point;
} ITEM;

ITEM People[20];
int Number;

void Print(void) {
    int i;
    printf("\nN Surname Country Point\n");
    for (i = 0; i < Number; i++) {
        printf("%i %s %s %i\n", i + 1, People[i].Surname, People[i].Country, People[i].Point);
    }
}
void Add(void)
{
    if (Number == 19)
    {
        fprintf(stderr, "It is impossible to add another element\n");
        return;
    }
    printf("Enter surname > ");
    scanf("%s", People[Number].Surname);
    printf("Enter country > ");
    scanf("%s", People[Number].Country);
    printf("Enter point > ");
    scanf("%i", &People[Number].Point);
    Number++;
}
void Del(void)
{
    int i;

    Print();
    printf("Enter the number of the item to be deleted > ");
    scanf("%i", &i);
    if (i < 1 || i > Number)
    {
        fprintf(stderr, "The element with the number %i does not exist\n", i);
        return;
    }
    for (i--; i < Number - 1; i++)
        People[i] = People[i + 1];
    Number--;
}
void Save(void)
{
    FILE* F;
    int i;
    if ((F = fopen("test.txt", "wt")) == NULL)
    {
        fprintf(stderr, "Unable to open the file 'test.txt' for writing\n");
        return;
    }
    fprintf(F, "%i\n", Number);
    for (i = 0; i < Number; i++)
        fprintf(F, "% s % s % i\n", People[i].Surname, People[i].Country, People[i].Point);

    fclose(F);
}
void Load(void)
{
    FILE* F;
    int i;

    if ((F = fopen("test.txt", "rt")) == NULL)
    {
        fprintf(stderr, "Unable to open the file 'test.txt' for writing\n");
        return;
    }
    fscanf(F, "%i", &Number);
    for (i = 0; i < Number; i++)
        fscanf(F, "%s%s%i", People[i].Surname, People[i].Country, &People[i].Point);
    fclose(F);
}
void Edit(void)
{
    int i;
    printf("Enter the line number that you want to change");
    scanf("%d", &i);
    printf("Enter surname > ");
    scanf("%s", People[i].Surname);
    printf("Enter country > ");
    scanf("%s", People[i].Country);
    printf("Enter point > ");
    scanf("%i", &People[i].Point);
}
void Sort(void)
{
    int i, j;
    ITEM Temp;
    for (j = Number - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (People[i].Point < People[i + 1].Point)
            {
                Temp = People[i];
                People[i] = People[i + 1];
                People[i + 1] = Temp;
            }
}
void Average(void)
{
    float sum = 0;
    for (int i = 0; i < Number; i++) {
        sum += People[i].Point;
    }
    float armean = sum / Number;
    printf("The average score is %.1f\n", armean);
}
int Menu(void)
{
    int c = 0;
    while ((c < '0' || c > '8') && c != 28)
    {
        printf("~~~Menu~~~\n"
            "0 : escape\n"
            "1 : add\n"
            "2 : save\n"
            "3 : load\n"
            "4 : output\n"
            "5 : edit\n"
            "6 : sort\n"
            "7 : delete\n"
            "8 : average\n"
            ">");
        c = _getch();
        printf("%c\n", c);
    }
    return c;
}
void main(void)
{
    int Selection;

    Number = 0;
    while ((Selection = Menu()) != '0' && Selection != 27)
        switch (Selection)
        {
        case '1':
            Add();
            break;
        case '2':
            Save();
            break;
        case '3':
            Load();
            break;
        case '4':
            Print();
            break;
        case '5':
            Edit();
            break;
        case '6':
            Sort();
            break;
        case '7':
            Del();
            break;
        case '8':
            Average();
            break;
        }
}




#include <cs50.h>
#include <stdio.h>

void printspaces(int n);
void printhashes(int n);
void printpyramids(int rows);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height:");
    }
    while (height < 1);
    printpyramids(height);
}

void printspaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void printhashes(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void printpyramids(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        printspaces(rows - i - 1);
        printhashes(i + 1);
        printspaces(2);
        printhashes(i + 1);
        printf("\n");
    }
}

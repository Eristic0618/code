#include <stdio.h>

int main()
{
    int i = 1;
    int row = 1;
    int space = 6;
    while (row <= 13)
    {
        for (int j = 0; j < space; j++)
        {
            printf("  ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("* ");
        }
        for (int j = 0; j < space; j++)
        {
            printf("  ");
        }
        if (row < 7)
        {
            i = i + 2;
            row++;
            space--;
            printf("\n");
        }
        else if (row >= 7)
        {
            i = i - 2;
            row++;
            space++;
            printf("\n");
        }
    }
    return 0;
}
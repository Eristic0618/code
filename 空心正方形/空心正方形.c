#include <stdio.h>

int main()
{
    int a, i, j;
    while (scanf("%d", &a) != EOF)
    {
        for (i = 1; i <= a; i++)
        {
            if (i == 1)
            {
                for (j = 1; j <= a; j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            else if (i == a)
            {
                for (j = 1; j <= a; j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            else
            {
                for (j = 1; j <= a; j++)
                {
                    if (j == 1)
                    {
                        printf("*");
                    }
                    else if (j == a)
                    {
                        printf("*\n");
                    }
                    else
                    {
                        printf(" ");
                    }
                }
            }
        }
    }
    return 0;
}
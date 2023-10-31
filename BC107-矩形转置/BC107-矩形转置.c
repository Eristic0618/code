#include <stdio.h>

int main()
{
    int a, b, i, j;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        int arr1[a][b];
        int arr2[b][a];
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < b; j++)
            {
                scanf("%d", &arr1[i][j]);
                arr2[j][i] = arr1[i][j];
            }
        }
        for (j = 0; j < b;j++)
        {
            for (i = 0; i < a;i++)
            {
                printf("%d ", arr2[j][i]);
            }
            printf("\n");
        }
    }
    return 0;
}
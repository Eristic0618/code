#include <stdio.h>

int main()
{
    int a = 0;
    scanf("%d", &a);
    int arr1[a];
    int arr2[a];
    int arr3[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int j = 0; j < a; j++)
    {
        scanf("%d", &arr2[j]);
    }
    for (int n = 0; n < a; n++)
    {
        arr3[n] = arr2[n];
        arr2[n] = arr1[n];
        arr1[n] = arr3[n];
    }
    return 0;
}
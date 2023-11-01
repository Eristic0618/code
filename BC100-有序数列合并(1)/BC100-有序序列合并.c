#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int temp;
    for (int c = 0; c < n - 1; c++)
    {
        for (int x = 0; x < n - c - 1; x++)
        {
            if (arr[x] > arr[x + 1])
            {
                temp = arr[x];
                arr[x] = arr[x + 1];
                arr[x + 1] = temp;
            }
        }
    }
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int i, j;
    int arr1[a];
    int arr2[b];
    int c = a + b;
    int arr[c];
    for (i = 0; i < a; i++)
    {
        scanf("%d", &arr1[i]);
        arr[i] = arr1[i];
    }
    for (j = 0; j < b; j++)
    {
        int t = a + j;
        scanf("%d", &arr2[j]);
        arr[t] = arr2[j];
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);
    for (int k = 0; k < c; k++)
    {
        printf("%d ", arr[k]);
    }

    return 0;
}
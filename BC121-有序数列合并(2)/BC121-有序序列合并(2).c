// 输入两个升序排列的序列，将两个序列合并为一个有序序列并输出
#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n];
    int arr2[m];
    int arr3[n + m];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &arr2[j]);
    }
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[count] = arr1[i];
            i++;
            count++;
        }
        else if (arr1[i] == arr2[j])
        {
            arr3[count] = arr1[i];
            i++;
            count++;
            arr3[count] = arr2[j];
            j++;
            count++;
        }
        else if (arr1[i] > arr2[j])
        {
            arr3[count] = arr2[j];
            j++;
            count++;
        }
    }
    if (i == n)
    {
        while (j < m)
        {
            arr3[count] = arr2[j];
            j++;
            count++;
        }
    }
    else if (j == m)
    {
        while (i < n)
        {
            arr3[count] = arr1[i];
            i++;
            count++;
        }
    }
    for (count = 0; count < n + m; count++)
    {
        printf("%d ", arr3[count]);
    }
    return 0;
}
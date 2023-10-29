#include <stdio.h>

//打印数组的每个元素
void Print(int arr1[], int sz1)
{
    for (int i = 0; i < sz1; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}

//完成数组元素的逆置
void Reverse(int arr2[], int sz2)
{
    int temp;
    int arr3[sz2];
    for (int x = 0; x < sz2;x++)
    {
        arr3[x] = arr2[x];
    }
    int i = 0;
    int j = sz2 - 1;
    while (i < sz2)
    {
        arr2[i] = arr3[j];
        printf("%d ", arr2[i]);
        i++;
        j--;
    }
    printf("\n");
}

//初始化数组为全0
void Init(int arr3[],int sz3)
{
    for (int i = 0; i < sz3;i++)
    {
        arr3[i] = 0;
        printf("%d ",arr3[i]);
    }
    printf("\n");
}

int main()
{
    int a;
    scanf("%d", &a);
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr[i]);
    }
    Print(arr, a);
    Reverse(arr, a);
    Init(arr, a);
    return 0;
}
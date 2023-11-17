// 在屏幕上打印杨辉三角
#include <stdio.h>

int main()
{
    int arr1[10000] = {0};
    int arr2[10000] = {0};
    int num = 0;
    printf("请输入杨辉三角行数:>");
    scanf("%d", &num);
    printf("1\n");
    printf("1 1\n");
    for (int i = 2; i < num; i++)
    {
        arr1[0] = 1;
        arr1[i - 1] = 1;
        arr2[0] = 1;
        arr2[i] = 1;
        printf("%d ", arr2[0]);
        for (int j = 1; j < i; j++)
        {
            arr2[j] = arr1[j - 1] + arr1[j];
            printf("%d ", arr2[j]);
        }
        for (int j = 1; j < i; j++)
        {
            arr1[j] = arr2[j];
        }
        printf("%d\n", arr2[i]);
    }
    return 0;
}
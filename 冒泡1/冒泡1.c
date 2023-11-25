//对整形数组的冒泡排序
#include <stdio.h>

void BubbleSort(int *pa, int sz) // 实现升序冒泡
{
    int temp = 0;
    for (int i = 0; i < sz - 1; i++)
    {
        int flag = 1;
        for (int j = 0; j < sz - i - 1; j++)
        {
            if (*(pa + j) > *(pa + j + 1))
            {
                temp = *(pa + j + 1);
                *(pa + j + 1) = *(pa + j);
                *(pa + j) = temp;
                flag = 0;
            }
        }
        if (flag)
        {
            break;
        }
    }
}

int main()
{
    int arr[10] = {3, 8, 4, 7, 9, 5, 1, 2, 6, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, sz);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
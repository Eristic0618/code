//调整数组使奇数全部都位于偶数前面
#include <stdio.h>

void OE_Sort(int *pa, int sz)
{
    int temp = 0;
    int n = 0;
    for (int i = 0; i < sz; i++)
    {
        if (*(pa + i) % 2 == 1)
        {
            temp = *(pa + i);
            *(pa + i) = *(pa + n);
            *(pa + n) = temp;
            n++;
        }
    }
}

int main()
{
    int arr[10] = {6, 24, 17, 4, 16, 21, 33, 23, 11, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    OE_Sort(arr, sz);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
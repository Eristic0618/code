// 模仿qsort的功能实现一个通用的冒泡排序
#include <stdio.h>
#include <stdlib.h>

void Swap(char *p1, char *p2, size_t width)
{
    for (int i = 0; i < width; i++)
    {
        char temp = *(p1 + i);
        *(p1 + i) = *(p2 + i);
        *(p2 + i) = temp;
    }
}

void Bubble_Sort2(void *base, size_t sz, size_t width, int (*cmp)(const void *p1, const void *p2))
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = 0; j < sz - 1 - i; j++)
        {
            if (cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
            }
        }
    }
}

int cmp_int(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

int main()
{
    int arr[10] = {8, 2, 4, 5, 9, 7, 0, 1, 3, 6};
    int sz = sizeof(arr) / sizeof(arr[0]);
    Bubble_Sort2(arr, sz, sizeof(arr[0]), cmp_int);
    for (int i = 0; i  < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
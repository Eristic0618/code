//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//例如：
//有数组的元素是：1，2，3，4，5，1，2，3，4，6
//只有5和6只出现1次，要找出5和6.
#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *p1, const void *p2)
{
    return *((int *)p1) - *((int *)p2);
}

void Search(int arr[], size_t sz)
{
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    int flag = 0;
    int count = 0;
    int i = 0;
    int num = -1;
    while (count < 2)
    {
        for (i = 0; i < sz; i++)
        {
            flag = 0;
            if (i == num)
            {
                continue;
            }
            else if (i == 0)
            {
                if (arr[i] == arr[i + 1])
                {
                    flag = 1;
                }
            }
            else if (i == sz - 1)
            {
                if (arr[i] == arr[i - 1])
                {
                    flag = 1;
                }
            }
            else if (arr[i] == arr[i - 1] || arr[i] == arr[i + 1])
            {
                flag = 1;
            }
            if (flag == 0)
            {
                printf("%d ", arr[i]);
                count++;
            }
        }
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 6};
    size_t sz = sizeof(arr) / sizeof(arr[0]);
    Search(arr, sz);
    return 0;
}
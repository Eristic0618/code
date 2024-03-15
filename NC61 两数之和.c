// https://www.nowcoder.com/share/jump/8993698061708567395970
// 给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。
// （注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int *twoSum(int *numbers, int numbersLen, int target, int *returnSize)
{
    int *ret = (int *)malloc(sizeof(int) * 2);
    memset(ret, 0, sizeof(int) * 2);
    *returnSize = 2;
    int *hash[2]; // 保存数组原下标
    hash[0] = (int *)malloc(sizeof(int) * numbersLen);
    hash[1] = (int *)malloc(sizeof(int) * numbersLen);
    for (int i = 0; i < numbersLen; i++)
    {
        hash[0][i] = numbers[i];
        hash[1][i] = i + 1;
    }
    qsort(numbers, numbersLen, sizeof(int), cmp); // 排序数组
    for (int i = 0; i < numbersLen; i++)          // 遍历数组 O(N)
    {
        int diff = target - numbers[i]; // 算出每个数与target的差值
        int begin = 0, end = numbersLen - 1;
        bool flag = false;
        while (begin <= end) // 二分寻找差值 O(logn)
        {
            int mid = (begin + end) / 2;
            if (mid == i) // 此时需要修正，否则死循环
            {
                begin += 1;
                continue;
            }
            if (numbers[mid] == diff) // 找到
            {
                for (int j = 0; j < numbersLen; j++)
                {
                    if (hash[0][j] == numbers[i] && ret[0] == 0) // 防止重复赋值
                    {
                        ret[0] = hash[1][j];
                    }
                    else if (hash[0][j] == numbers[mid] && hash[1][j] != ret[0])
                    {
                        ret[1] = hash[1][j];
                    }
                }
                flag = true;
                break; // 跳出循环
            }
            else if (numbers[mid] < diff)
            {
                begin = mid + 1;
            }
            else if (numbers[mid] > diff)
            {
                end = mid - 1;
            }
        }
        if (flag)
            break;
    }
    qsort(ret, 2, sizeof(int), cmp); // 最后对返回数组排序
    return ret;
}
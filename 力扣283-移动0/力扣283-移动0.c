// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序
#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int *nums, int numsSize)
{
    int t = 0;
    int m;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != 0)
        {
            m = nums[i];
            nums[i] = nums[t];
            nums[t] = m;
            t++;
        }
    }
}

int main()
{
    int nums[5] = {0, 1, 0, 3, 12};
    int numsSize = 5;
    moveZeroes(nums, numsSize);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(nums + i));
    }
    return 0;
}
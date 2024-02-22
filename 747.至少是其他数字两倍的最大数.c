// 给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
// 请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。
int cmp(int *a, int *b)
{
    return *a - *b;
}

int dominantIndex(int *nums, int numsSize)
{
    int maxi = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] > nums[maxi])
            maxi = i;
    }
    int max = nums[maxi];
    qsort(nums, numsSize, sizeof(int), cmp);
    if (max >= nums[numsSize - 2] * 2)
        return maxi;
    else
        return -1;
}
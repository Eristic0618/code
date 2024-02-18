// 集合 s 包含从 1 到 n 的整数。
// 不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合丢失了一个数字并且 有一个数字重复 。
// 给定一个数组 nums 代表了集合 S 发生错误后的结果。
// 请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
int cmp(int *a, int *b)
{
    return *a - *b;
}

int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    int *a = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++)
    {
        int prev = nums[i];
        int cur = nums[i + 1];
        if (prev == cur)
        {
            a[0] = prev;
        }
        if (nums[0] != 1)
            a[1] = 1;
        if (nums[numsSize - 1] != numsSize)
            a[1] = numsSize;
        if (cur - prev > 1)
            a[1] = prev + 1;
    }
    return a;
}
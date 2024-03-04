// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
// 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
    int *leftmul = (int *)malloc(sizeof(int) * numsSize);
    leftmul[0] = 0;
    int *rightmul = (int *)malloc(sizeof(int) * numsSize);
    rightmul[numsSize - 1] = 0;
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 1; i < numsSize; i++)
    {
        int j = numsSize - 1 - i;
        if (i - 1 != 0)
            leftmul[i] = leftmul[i - 1] * nums[i - 1];
        else
            leftmul[i] = nums[i - 1];
        if (j + 1 != numsSize - 1)
            rightmul[j] = rightmul[j + 1] * nums[j + 1];
        else
            rightmul[j] = nums[j + 1];
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (i == 0)
            ret[i] = rightmul[i];
        else if (i == numsSize - 1)
            ret[i] = leftmul[i];
        else
            ret[i] = leftmul[i] * rightmul[i];
    }
    *returnSize = numsSize;
    return ret;
}
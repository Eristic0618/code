// 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
// 请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    int *hash = (int *)malloc(sizeof(int) * numsSize);
    memset(hash, 0, sizeof(int) * numsSize);
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        hash[nums[i] - 1]++;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[i] == 0)
        {
            count++;
        }
    }
    *returnSize = count;
    int *ret = (int *)malloc(sizeof(int) * count);
    int j = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (hash[i] == 0)
        {
            ret[j++] = i + 1;
        }
    }
    return ret;
}
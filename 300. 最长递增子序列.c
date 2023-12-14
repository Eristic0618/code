// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
int lengthOfLIS(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int *dp = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++)
    {
        dp[i] = 1;
    }
    int ret = 1;
    for (int i = 1; i < numsSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > ret)
        {
            ret = dp[i];
        }
    }
    return ret;
}
// https://leetcode.cn/problems/partition-equal-subset-sum/description/
// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
// 思路：把nums分成两个相等的部分，转换成01背包问题
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= sum / 2; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; // dp和原数组下标映射有偏差
            }
        return dp[n][sum / 2];
    }
};
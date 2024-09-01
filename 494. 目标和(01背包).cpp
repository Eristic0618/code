// https://leetcode.cn/problems/target-sum/description/
// 给你一个非负整数数组 nums 和一个整数 target 。
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

// 思路：
// 把所有数分为正负两部分，求出两部分的绝对值之和a、b
// a - b = target，a + b = 数组和sum -> 2a = sum + target -> a = (sum + target) / 2
// 然后就可以转化为01背包问题，找出有多少种选法可以刚好等于a
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int _target)
    {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        int a = (sum + _target) / 2;
        if (a < 0 || (sum + _target) % 2 == 1)
            return 0;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(a + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= a; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        return dp[n][a];
    }
};

// 滚动数组优化
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int _target) {
//         int sum = 0;
//         for(auto i : nums)
//             sum += i;
//         int a = (sum + _target) / 2;
//         if(a < 0 || (sum + _target) % 2 == 1)
//             return 0;
//         int n = nums.size();
//         vector<int> dp(a + 1);
//         dp[0] = 1;
//         for(int i = 1;i <= n;i++)
//             for(int j = a;j >= nums[i-1];j--)
//             {
//                 dp[j] += dp[j-nums[i-1]];
//             }
//         return dp[a];
//     }
// };
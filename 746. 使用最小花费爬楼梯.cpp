// https://leetcode.cn/problems/min-cost-climbing-stairs/description/
// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
// 请你计算并返回达到楼梯顶部的最低花费。
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0; // 下标即为台阶数，因为可以从0或1开始爬，所以两个地方的初始值都为0
        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]); // 第i阶的最低花费取决于先到i-2阶+费用和先到i-1阶+费用的较小值
        }
        return dp[n];
    }
};
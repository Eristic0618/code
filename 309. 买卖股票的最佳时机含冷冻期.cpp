// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。?
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            dp[1][i] = max(dp[2][i - 1], dp[1][i - 1]);
            dp[2][i] = dp[0][i - 1] + prices[i];
        }
        return max(dp[1][n - 1], dp[2][n - 1]);
    }
};
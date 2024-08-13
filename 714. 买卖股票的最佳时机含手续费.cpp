// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
// 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
// 返回获得利润的最大值。
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = -prices[0] - fee;
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i] - fee);
            dp[1][i] = max(dp[0][i - 1] + prices[i], dp[1][i - 1]);
        }
        return dp[1][n - 1];
    }
};
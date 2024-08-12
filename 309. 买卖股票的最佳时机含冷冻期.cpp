// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
// ����һ����������prices�����е�  prices[i] ��ʾ�� i ��Ĺ�Ʊ�۸� ��?
// ���һ���㷨����������������������Լ�������£�����Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ��:
// ������Ʊ�����޷��ڵڶ��������Ʊ (���䶳��Ϊ 1 ��)��
// ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
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
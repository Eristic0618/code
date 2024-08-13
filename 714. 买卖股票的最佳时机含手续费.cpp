// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
// ����һ���������� prices������ prices[i]��ʾ�� i ��Ĺ�Ʊ�۸� ������ fee �����˽��׹�Ʊ���������á�
// ��������޴ε���ɽ��ף�������ÿ�ʽ��׶���Ҫ�������ѡ�������Ѿ�������һ����Ʊ����������֮ǰ��Ͳ����ټ��������Ʊ�ˡ�
// ���ػ����������ֵ��
// ע�⣺�����һ�ʽ���ָ������в�������Ʊ���������̣�ÿ�ʽ�����ֻ��ҪΪ֧��һ�������ѡ�
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
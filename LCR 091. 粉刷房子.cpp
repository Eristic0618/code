// https://leetcode.cn/problems/JEj789/description/
// ������һ�ŷ��ӣ��� n ����ÿ�����ӿ��Ա���ˢ�ɺ�ɫ����ɫ������ɫ��������ɫ�е�һ�֣�����Ҫ��ˢ���еķ��Ӳ���ʹ�����ڵ�����������ɫ������ͬ��
// ��Ȼ����Ϊ�г��ϲ�ͬ��ɫ����ļ۸�ͬ�����Է��ӷ�ˢ�ɲ�ͬ��ɫ�Ļ��ѳɱ�Ҳ�ǲ�ͬ�ġ�ÿ�����ӷ�ˢ�ɲ�ͬ��ɫ�Ļ�������һ�� n x 3 ������������ costs ����ʾ�ġ�
// ���磬costs[0][0] ��ʾ�� 0 �ŷ��ӷ�ˢ�ɺ�ɫ�ĳɱ����ѣ�costs[1][2] ��ʾ�� 1 �ŷ��ӷ�ˢ����ɫ�Ļ��ѣ��Դ����ơ�
// ��������ˢ�����з������ٵĻ��ѳɱ���
class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3));
        for (int i = 0; i < 3; i++)
        {
            dp[0][i] = costs[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    }
};
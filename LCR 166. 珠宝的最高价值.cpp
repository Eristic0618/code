// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/
// ����һ��������ά���� frame ���鱦�ܣ����� frame[i][j] Ϊ��λ���鱦�ļ�ֵ����ȡ�鱦�Ĺ���Ϊ��
// ֻ�ܴӼ��ӵ����Ͻǿ�ʼ���鱦
// ÿ�ο����ƶ����Ҳ���²������λ��
// �����鱦���ӵ����½�ʱ��ֹͣ��ȡ
// ע�⣺�鱦�ļ�ֵ���Ǵ��� 0 �ġ��������������û���κ��鱦������ frame = [[0]]��
class Solution
{
public:
    int jewelleryValue(vector<vector<int>> &frame)
    {
        int m = frame.size();
        int n = frame[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
        return dp[m][n];
    }
};
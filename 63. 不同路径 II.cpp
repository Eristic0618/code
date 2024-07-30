// https://leetcode.cn/problems/unique-paths-ii/description/
// һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
// ������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish������
// ���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
// �����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid[0].size();
        int m = obstacleGrid.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (obstacleGrid[i - 1][j - 1] == 1)
                    dp[i][j] = 0;
            }
        }
        return dp[m][n];
    }
};
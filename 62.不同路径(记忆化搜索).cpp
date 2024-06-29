// https://leetcode.cn/problems/unique-paths/
// һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����
// ������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ����
// ���ܹ��ж�������ͬ��·����
class Solution
{
public:
    vector<vector<int>> memo;

    int uniquePaths(int m, int n)
    {
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1));
        return dfs(m, n);
    }

    int dfs(int i, int j)
    {
        if (memo[i][j] != 0)
            return memo[i][j];
        if (i == 0 || j == 0)
            return 0;
        if (i == 1 && j == 1)
        {
            memo[i][j] = 1;
            return 1;
        }
        memo[i][j] = dfs(i - 1, j) + dfs(i, j - 1);
        return memo[i][j];
    }
};
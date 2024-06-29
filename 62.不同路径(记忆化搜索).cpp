// https://leetcode.cn/problems/unique-paths/
// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
// 问总共有多少条不同的路径？
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
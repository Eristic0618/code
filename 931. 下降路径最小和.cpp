// https://leetcode.cn/problems/minimum-falling-path-sum/description/
// 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。
// 下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
// 在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
// 具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX)); // 多开一行两列，避免数组越界，要将左右两列初始化为INT_MAX避免干扰dp表填写，为了方便这里之间把dp表初始化为INT_MAX
        for (int j = 0; j < n + 2; j++)
            dp[0][j] = 0; // 将dp第一行初始化为0
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1]; // 选择左右正上方最小值加上原始矩阵中的值
        int min = INT_MAX;
        for (int i = 1; i <= n; i++)
            if (dp[n][i] < min)
                min = dp[n][i]; // 找出dp表最后一行的最小值即为最小路径和
        return min;
    }
};
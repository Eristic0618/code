// https://leetcode.cn/problems/max-area-of-island/
// 给你一个大小为 m x n 的二进制矩阵 grid 。
// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
// 岛屿的面积是岛上值为 1 的单元格的数目。
// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
class Solution
{
public:
    vector<vector<bool>> visit;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;
    int count;
    int max;

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && !visit[i][j])
                {
                    dfs(grid, i, j);
                    if (count > max)
                        max = count;
                    count = 0;
                }
            }
        return max;
    }

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        visit[i][j] = true;
        count++;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && !visit[x][y])
                dfs(grid, x, y);
        }
        return;
    }
};
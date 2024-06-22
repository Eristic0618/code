// https://leetcode.cn/problems/number-of-islands/description/
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围
class Solution
{
public:
    vector<vector<bool>> visit;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int m, n;

    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        visit = vector<vector<bool>>(m, vector<bool>(n));
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visit[i][j])
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        visit[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !visit[x][y])
                dfs(grid, x, y);
        }
        return;
    }
};
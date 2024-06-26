// https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
// 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。
// 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。
// 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。
// 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。
class Solution
{
public:
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> paflow(m, vector<bool>(n));
        vector<vector<bool>> atflow(m, vector<bool>(n));
        for (int i = 0; i < m; i++)
        {
            dfs(heights, paflow, i, 0);
            dfs(heights, atflow, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, paflow, 0, j);
            dfs(heights, atflow, m - 1, j);
        }
        vector<vector<int>> ret;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (paflow[i][j] && atflow[i][j])
                    ret.push_back({i, j});
        return ret;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &flow, int i, int j)
    {
        if (flow[i][j])
            return;
        flow[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[i][j])
                dfs(heights, flow, x, y);
        }
        return;
    }
};
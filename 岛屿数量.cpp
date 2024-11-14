//给一个01矩阵，1代表是陆地，0代表海洋，如果两个1相邻，那么这两个1属于同一个岛。
//我们只考虑上下左右为相邻。岛屿: 相邻陆地可以组成一个岛屿(相邻:上下左右) 判断岛屿个数。
//例如:输入[1,1,0,0,0].[0,1,0,1,1],[0,0,0,1,1],[0,0,0,0,0].[0,0,1,1,1]对应的输出为3
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    void dfs(vector<vector<char> >& grid, int a, int b)
    {
        grid[a][b] = '0';
        for(int i = 0;i < 4;i++)
        {
            int x = a + dx[i];
            int y = b + dy[i];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }

    int solve(vector<vector<char> >& grid) {
        int ret = 0;
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }
};
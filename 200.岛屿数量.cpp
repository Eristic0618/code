// https://leetcode.cn/problems/number-of-islands/description/
// ����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
// �������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�
// ���⣬����Լ��������������߾���ˮ��Χ
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
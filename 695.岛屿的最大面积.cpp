// https://leetcode.cn/problems/max-area-of-island/
// ����һ����СΪ m x n �Ķ����ƾ��� grid ��
// ���� ����һЩ���ڵ� 1 (��������) ���ɵ���ϣ�����ġ����ڡ�Ҫ������ 1 ������ ˮƽ������ֱ���ĸ������� ���ڡ�����Լ��� grid ���ĸ���Ե���� 0������ˮ����Χ�š�
// ���������ǵ���ֵΪ 1 �ĵ�Ԫ�����Ŀ��
// ���㲢���� grid �����ĵ�����������û�е��죬�򷵻����Ϊ 0 ��
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
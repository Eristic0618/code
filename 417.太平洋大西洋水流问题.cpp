// https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
// ��һ�� m �� n �ľ��ε��죬�� ̫ƽ�� �� ������ ���ڡ� ��̫ƽ�� ���ڴ�½����߽���ϱ߽磬�� �������� ���ڴ�½���ұ߽���±߽硣
// ��������ָ��һ�������ɷ��ε�Ԫ����ɵ����񡣸���һ�� m x n ���������� heights �� heights[r][c] ��ʾ���� (r, c) �ϵ�Ԫ�� ���ں�ƽ��ĸ߶� ��
// ������ˮ�϶࣬������ڵ�Ԫ��ĸ߶� С�ڻ���� ��ǰ��Ԫ��ĸ߶ȣ���ˮ����ֱ���򱱡��ϡ��������������ڵ�Ԫ��ˮ���ԴӺ��󸽽����κε�Ԫ�����뺣��
// ������������ result �� 2D �б� ������ result[i] = [ri, ci] ��ʾ��ˮ�ӵ�Ԫ�� (ri, ci) ���� �ȿ�����̫ƽ��Ҳ����������� ��
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
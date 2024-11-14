//��һ��01����1������½�أ�0�������������1���ڣ���ô������1����ͬһ������
//����ֻ������������Ϊ���ڡ�����: ����½�ؿ������һ������(����:��������) �жϵ��������
//����:����[1,1,0,0,0].[0,1,0,1,1],[0,0,0,1,1],[0,0,0,0,0].[0,0,1,1,1]��Ӧ�����Ϊ3
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * �жϵ�������
     * @param grid char�ַ���vector<vector<>> 
     * @return int����
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
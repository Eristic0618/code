// https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/description/
// ����һ�� m x n ���Թ����� maze ���±�� 0 ��ʼ�����������пո��ӣ��� '.' ��ʾ����ǽ���� '+' ��ʾ����ͬʱ�����Թ������ entrance ���� entrance = [entrancerow, entrancecol] ��ʾ��һ��ʼ���ڸ��ӵ��к��С�
// ÿһ��������������� �ϣ��£��� ���� �� �ƶ�һ�����ӡ��㲻�ܽ���ǽ���ڵĸ��ӣ���Ҳ�����뿪�Թ������Ŀ�����ҵ��� entrance ��� �ĳ��ڡ����� �ĺ����� maze �߽� �ϵ� �ո��ӡ�entrance ���� ���� ���ڡ�
// ���㷵�ش� entrance ��������ڵ����·���� ���� �����������������·�������㷵�� -1 ��
class Solution
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        queue<vector<int>> q;
        vector<vector<bool>> visit(maze.size(), vector<bool>(maze[0].size()));
        q.push(entrance);
        visit[entrance[0]][entrance[1]] = true;
        int ans = 0;
        while (!q.empty())
        {
            ans++;
            int n = q.size();
            while (n--)
            {
                for (int i = 0; i < 4; i++)
                {
                    int x = q.front()[0] + dx[i];
                    int y = q.front()[1] + dy[i];
                    if (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size())
                    {
                        char des = maze[x][y];
                        if (des == '.' && visit[x][y] == false)
                        {
                            if (x == 0 || x == maze.size() - 1 || y == 0 || y == maze[0].size() - 1)
                                return ans;
                            q.push({x, y});
                            visit[x][y] = true;
                        }
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};
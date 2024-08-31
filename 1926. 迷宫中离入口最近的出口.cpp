// https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/description/
// 给你一个 m x n 的迷宫矩阵 maze （下标从 0 开始），矩阵中有空格子（用 '.' 表示）和墙（用 '+' 表示）。同时给你迷宫的入口 entrance ，用 entrance = [entrancerow, entrancecol] 表示你一开始所在格子的行和列。
// 每一步操作，你可以往 上，下，左 或者 右 移动一个格子。你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 entrance 最近 的出口。出口 的含义是 maze 边界 上的 空格子。entrance 格子 不算 出口。
// 请你返回从 entrance 到最近出口的最短路径的 步数 ，如果不存在这样的路径，请你返回 -1 。
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
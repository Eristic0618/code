// https : // leetcode.cn/problems/surrounded-regions/description/
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
class Solution
{
public:
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void solve(vector<vector<char>> &board)
    {
        m = board.size(), n = board[0].size();
        for (int j = 0; j < n; j++)
        {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        return;
    }

    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (board[i][j] == 'A' || board[i][j] == 'X')
            return;
        board[i][j] = 'A';
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O')
                dfs(board, x, y);
        }
        return;
    }
};
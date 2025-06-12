//https://www.acwing.com/problem/content/190/
#include <iostream>
#include <queue>
using namespace std;

#define N 160
#define x first
#define y second

int n, m, kx, ky, hx, hy, res;
int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1}, dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
char g[N][N];
bool st[N][N];

int bfs(int a, int b)
{
    int ret = 0;
    queue<pair<int, int>> q;
    q.push({a, b});
    st[a][b] = true;
    while(q.size())
    {
        int sz = q.size();
        ret++;
        while(sz--)
        {
            auto f = q.front();
            q.pop();
            for(int i = 0; i < 8; i++)
            {
                int tx = f.x + dx[i], ty = f.y + dy[i];
                if(tx >= 0 && tx < n && ty >= 0 && ty < m && g[tx][ty] != '*' && !st[tx][ty]) //不越界、不为障碍且未访问
                {
                    q.push({tx, ty});
                    st[tx][ty] = true;
                    if(tx == hx && ty == hy)
                        return ret;
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == 'K') kx = i, ky = j;
            if(g[i][j] == 'H') hx = i, hy = j;
        }
    res = bfs(kx, ky);
    cout << res << endl;
    return 0;
}
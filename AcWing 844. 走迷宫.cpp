// https://www.acwing.com/video/276/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int N = 110;
typedef pair<int, int> PII;

int g[N][N];
int d[N][N];
bool vis[N][N];
int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs()
{
    queue<PII> q;
    q.push({1, 1});
    memset(d, -1, sizeof d);
    d[1][1] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + t.first;
            int y = dy[i] + t.second;
            if (x >= 1 && x <= n && y >= 1 && y <= m && d[x][y] == -1 && g[x][y] == 0)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    return d[n][m];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    cout << bfs() << endl;
    return 0;
}
//https://www.acwing.com/problem/content/175/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define N 1010
#define x first
#define y second

int n, m;
char g[N][N];
int ans[N][N], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool st[N][N];
queue<pair<int, int>> q;

void bfs() //多源bfs
{
    int dist = 1;
    while(q.size())
    {
        int sz = q.size();
        while(sz--)
        {
            auto f = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int tx = f.x + dx[i], ty = f.y + dy[i];
                if(tx >= 0 && tx < n && ty >= 0 && ty < m && !st[tx][ty])
                {
                    q.push({tx, ty});
                    st[tx][ty] = true;
                    ans[tx][ty] = dist;
                }
            }
        }
        dist++;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == '1') //起点
            {
                q.push({i, j});
                st[i][j] = true;
            }
        }
    bfs();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
        
    return 0;
}
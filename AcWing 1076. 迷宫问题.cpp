//https://www.acwing.com/problem/content/1078/
#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define x first
#define y second

int n;
int g[N][N], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
bool st[N][N];
pair<int, int> pre[N][N]; //记录前驱节点

void bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    st[a][b] = true;
    while(q.size())
    {
        auto f = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int tx = f.x + dx[i], ty = f.y + dy[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < n && g[tx][ty] == 0 && !st[tx][ty])
            {
                q.push({tx, ty});
                st[tx][ty] = true;
                pre[tx][ty] = {f.x, f.y};
                if(tx == n-1 && ty == n-1)
                    return;
            }
        }
    }
}

void inorder(int a, int b)
{
    if(!a && !b)
    {
        cout << a << " " << b << endl;
        return;
    }
    inorder(pre[a][b].x, pre[a][b].y);
    cout << a << " " << b << endl;
}

int main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
            
    bfs(0, 0);
    inorder(n-1, n-1);
    return 0;
}
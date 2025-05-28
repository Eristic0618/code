//https://www.acwing.com/problem/content/1108/
#include <iostream>
#include <queue>
using namespace std;

#define N 1010
#define x first
#define y second

int n, h, l;
int g[N][N];
bool st[N][N];

int bfs(int a, int b)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    st[a][b] = true;
    bool h = false, l = false;
    while(q.size())
    {
        auto f = q.front();
        q.pop();
        for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++) //遍历方向
            {
                if(!i && !j)
                    continue;
                int tx = f.x + i, ty = f.y + j;
                if(tx >= 1 && tx <= n && ty >= 1 && ty <= n) //坐标不越界
                {
                    if(g[tx][ty] == g[f.x][f.y] && !st[tx][ty]) //高度相等且未访问过
                    {
                        q.push({tx, ty});
                        st[tx][ty] = true;
                    }
                    else if(g[tx][ty] > g[f.x][f.y]) //四周更高
                        l = true;
                    else if(g[tx][ty] < g[f.x][f.y]) //四周更矮
                        h = true;
                }
            }
    }
    if(h && l) //既不是山峰也不是山谷
        return 0;
    else if(h) //是山峰
        return 1;
    else if(l)
        return -1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];
            
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            if(!st[i][j])
            {
                int ret = bfs(i, j);
                if(ret == 1)
                    h++;
                else if(ret == -1)
                    l++;
            }
        }
    if(!h && !l) h++, l++;
    cout << h << " " << l << endl;
    return 0;
}
//https://www.luogu.com.cn/problem/P9425
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 1010
#define M 1010
#define K 15

int n, m, k, cnt;
char grid[N][M];
bool check[N][M][K]; //判断grid[i][j]在第k步是否被访问过（如果已被访问过说明可能导致重复路径？）
queue<pair<int, int>> q;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
#define check(x, y) (x >= 0 && x < n && y >= 0 && y < m)

void solve()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    q.push({ 0, 0 }); //初始化
    check[0][0][1] = true;
    while (!q.empty())
    {
        for (int step = 1; step <= k; step++)
        {
            int sz = q.size();
            while (sz--)
            {
                auto front = q.front();
                q.pop();
                int x = front.first, y = front.second;
                if (x == n - 1 && y == m - 1) //走到右下角
                {
                    cout << cnt << endl;
                    return;
                }

                if (step == k) //准备更换字符
                {
                    for (int i = 0; i < 4; i++)
                    {
                        int tx = x + dx[i], ty = y + dy[i]; //坐标偏移
                        if (check(tx, ty) && grid[tx][ty] != grid[x][y] && !check[tx][ty][1]) //不越界、字符不同
                        {
                            check[tx][ty][1] = true;
                            q.push({ tx, ty });
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < 4; i++)
                    {
                        int tx = x + dx[i], ty = y + dy[i]; //坐标偏移
                        if (check(tx, ty) && grid[tx][ty] == grid[x][y] && !check[tx][ty][step+1]) //不越界、字符相同
                        {
                            check[tx][ty][step + 1] = true;
                            q.push({ tx, ty });
                        }
                    }
                }
            }
            cnt++;
        }
    }
    cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
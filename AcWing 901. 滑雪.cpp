// https://www.acwing.com/problem/content/903/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;

int n, m;
int h[N][N], f[N][N];

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int dp(int x, int y)
{
    int &v = f[x][y];
    if (v != -1)
        return v;
    v = 1;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && h[a][b] < h[x][y])
            v = max(v, dp(a, b) + 1);
    }
    return v;
}

int main()
{
    cin >> n >> m;
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> h[i][j];
        }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            res = max(res, dp(i, j));
        }
    cout << res << endl;
    return 0;
}
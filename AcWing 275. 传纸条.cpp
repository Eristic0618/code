//https://www.acwing.com/problem/content/277/
#include <bits/stdc++.h>
using namespace std;

#define N 55

int n, m;
int g[N][N];
int f[N+N][N][N];

//纸条来回传实际上可以转化为从左上角向右下角传递两次，因此这题和AcWing 1027. 方格取数一样
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    for(int k = 2; k <= n+m; k++)
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = 1; i2 <= n; i2++)
            {
                if(k-i1 >= 1 && k-i1 <= m && k-i2 >= 1 && k-i2 <= m)
                {
                    f[k][i1][i2] = max(max(max(f[k-1][i1-1][i2-1], f[k-1][i1-1][i2])
                                            , f[k-1][i1][i2-1]), f[k-1][i1][i2]) + g[i1][k-i1];
                    if(i1 != i2)
                        f[k][i1][i2] += g[i2][k-i2];
                }
            }
    cout << f[n+m][n][n] << endl;
    return 0;
}
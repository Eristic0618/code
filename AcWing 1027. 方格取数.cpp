//https://www.acwing.com/problem/content/1029/
#include <bits/stdc++.h>
using namespace std;

#define N 15

int n;
int g[N][N];
int f[2*N][N][N]; //f[k][i1][i2]代表两条路径分别从(1,1)到(i1,k-i1)(i2,k-i2)的最大长度和（k为横纵坐标之和）

int main()
{
    cin >> n;
    int x, y, c;
    while(cin >> x >> y >> c, x || y || c)
        g[x][y] = c;
    
    for(int k = 2; k <= 2*n; k++)
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = 1; i2 <= n; i2++)
            {
                //1.第一条路径最后一步向下，第二条路径最后一步向下
                //2.第一条路径最后一步向下，第二条路径最后一步向右
                //3.第一条路径最后一步向右，第二条路径最后一步向下
                //4.第一条路径最后一步向右，第二条路径最后一步向右
                if(k-i1 >= 1 && k-i1 <= n && k-i2 >= 1 && k-i2 <= n)
                {
                    f[k][i1][i2] = max(max(max(f[k-1][i1-1][i2-1], f[k-1][i1-1][i2]), 
                                                f[k-1][i1][i2-1]), f[k-1][i1][i2]) + g[i1][k-i1];
                    if(i1 != i2) //(i1,k-i1)和(i2,k-i2)不重合
                        f[k][i1][i2] += g[i2][k-i2];
                }
            }
    cout << f[2*n][n][n] << endl;
    return 0;
}
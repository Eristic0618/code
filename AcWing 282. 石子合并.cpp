//https://www.acwing.com/problem/content/description/284/
#include <bits/stdc++.h>
using namespace std;

#define N 310

int n;
int a[N];
int dp[N][N]; //dp[i][j]代表合并从i到j的石头的所有方案中的最小代价
int f[N]; //前缀和

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    f[0] = a[0];
    for(int i = 1; i < n; i++)
        f[i] = f[i-1] + a[i];
    for(int len = 2; len <= n; len++) //枚举区间长度
    {
        for(int i = 0; i + len - 1 < n; i++) //枚举左端点
        {
            int j = i + len - 1;
            dp[i][j] = 1e8;
            for(int k = i; k < j; k++) //枚举区间划分点
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + f[j] - f[i-1]); //除了左右两个区间的最小代价，还需要加上该区间内所有石子重量
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
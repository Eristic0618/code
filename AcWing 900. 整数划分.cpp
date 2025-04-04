//https://www.acwing.com/problem/content/902/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 1010

int MOD = 1e9 + 7;
int n;
int dp[N][N];

signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        dp[i][i] = 1;
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-j][j]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += dp[n][i];
    cout << ans % MOD << endl;
    return 0;
}
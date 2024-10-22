// https://www.acwing.com/problem/content/900/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

const int N = 510;

int g[N][N];
int dp[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[n][i] = g[n][i];
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + g[i][j];
    }
    cout << dp[1][1];
    return 0;
}
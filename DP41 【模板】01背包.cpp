// https://www.nowcoder.com/practice/fd55637d3f24484e96dad9e992d3f62e?tpId=230&tqId=38964&ru=/exam/oj
#include <iostream>
#include <string.h>
using namespace std;

const int N = 1010;
int n, V, v[N], w[N];
int dp[N][N];

int main()
{
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    // 第一问
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i][j], w[i] + dp[i - 1][j - v[i]]);
        }
    cout << dp[n][V] << endl;
    // 第二问
    for (int i = 1; i <= V; i++) // 初始化：因为必须装满，所以可能存在无解情况，记为-1
        dp[0][i] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i] && dp[i - 1][j - v[i]] != -1)
                dp[i][j] = max(dp[i][j], w[i] + dp[i - 1][j - v[i]]);
        }
    cout << (dp[n][V] == -1 ? 0 : dp[n][V]) << endl;
    return 0;
}

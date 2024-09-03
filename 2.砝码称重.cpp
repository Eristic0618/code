// https://www.lanqiao.cn/problems/1447/learning/?problem_list_id=1&page=1
#include <bits/stdc++.h>
using namespace std;

int w[105];
bool dp[105][100050];

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        sum += w[i];
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= sum; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j + w[i]] + dp[i - 1][abs(j - w[i])];
    int ans = 0;
    for (int j = 1; j <= sum; j++)
        if (dp[n][j])
            ans++;
    cout << ans << endl;
    return 0;
}
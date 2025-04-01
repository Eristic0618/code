//https://www.acwing.com/problem/content/description/901/
#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m;
int dp[15][15];
char s[N][15];
int d;

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n; i++)
        cin >> (s[i]+1);
    for(int i = 0; i < 15; i++)
    {
        dp[i][0] = i, dp[0][i] = i;
    }
    for(int t = 0;t < m; t++)
    {
        char q[15];
        cin >> (q+1) >> d;
        int l1 = strlen(q+1);
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int l2 = strlen(s[i]+1);
            for(int j = 1; j <= l2; j++)
            {
                for(int k = 1; k <= l1; k++)
                {
                    dp[j][k] = min(dp[j-1][k], dp[j][k-1])+1;
                    if(s[i][j] == q[k]) dp[j][k] = min(dp[j][k], dp[j-1][k-1]);
                    else dp[j][k] = min(dp[j][k], dp[j-1][k-1]+1);
                }
            }
            if(dp[l2][l1] <= d) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
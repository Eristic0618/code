// https://www.luogu.com.cn/problem/P9420
#include <bits/stdc++.h>
#define int __int128
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

// int dp[4];
//
// void solve()
//{
//	for(int i = 1;i <= 2023;i ++)
//	{
//		string s = to_string(i);
//		for(int i = 0;i < s.size();i++)
//		{
//			if(s[i] == '2') dp[0]++, dp[2] += dp[1];
//			else if(s[i] == '0') dp[1] += dp[0];
//			else if(s[i] == '3') dp[3] += dp[2];
//		}
//	}
//	cout << dp[3] << endl;
// }

const int N = 3000000;
vector<int> prime;
bool is_prime[N];

void solve()
{
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
        }
        for (auto e : prime)
        {
            if (i * e > N)
                break;
            is_prime[i * e] = false;
            if (i % e == 0)
                break;
        }
    }
    long long ans = 0;
    int left = 2333;
    int right = 23333333333333;
    for (int i = 0; i < prime.size(); i++)
        for (int j = i + 1; j < prime.size(); j++)
        {
            int num = prime[i] * prime[i] * prime[j] * prime[j];
            if (num < left)
                continue;
            else if (num > right)
                break;
            else
                ans++;
        }
    cout << ans << endl;
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
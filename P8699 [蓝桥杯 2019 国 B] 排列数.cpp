//https://www.luogu.com.cn/problem/P8699
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 505

int dp[N][N]; //dp[i][j]代表1~i的排列中有j个折点的方案数
int n, k; 

void solve()
{
	cin >> n >> k;
	dp[1][0] = 1;
	for(int i = 2; i < n; i++)
	{
		dp[i][0] = 2; //递增或递减 
		for(int j = 0; j <= i; j++)
		{
			dp[i+1][j] += (dp[i][j] * (j+1)) % 123456; //如果有j个折点，且插入新元素后不能增加折点，则只能在波峰两侧插入。不论是奇数个折点还是偶数个折点，可插入的位置都是j+1个
			dp[i+1][j+1] += (dp[i][j] * 2) % 123456; //只能在序列头或尾的前后插入才能实现只增加一个折点
			dp[i+1][j+2] += (dp[i][j] * ((i+1)-(j+1)-2)) % 123456; //剩余所有位置都可以增加两个折点 
		}
	}
	cout << dp[n][k-1] % 123456 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
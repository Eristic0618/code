//https://www.luogu.com.cn/problem/P8752
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

int cnt; 

void solve()
{
	for(int i = 0;i < 5; i++)
	{
		string y;
		cin >> y;
		if(y[0] == y[2] && y[1]+1 == y[3])
			cnt++;
	}
	cout << cnt << endl;
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
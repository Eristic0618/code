// https://www.luogu.com.cn/problem/P8772
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 200020

int n, sum;
int a[N], f[N]; // f[i]ÎªÇ°×ººÍ

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum += a[i] * (f[n] - f[i]);
    }
    cout << sum << endl;
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
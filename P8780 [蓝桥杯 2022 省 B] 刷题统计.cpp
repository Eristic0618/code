// https://www.luogu.com.cn/problem/P8780
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

int a, b, n, d;

void solve()
{
    cin >> a >> b >> n;
    int w = a * 5 + b * 2;
    d += (n / w) * 7;
    n %= w;
    for (int i = 0; i < 5 && n > 0; i++)
    {
        n -= a;
        d++;
    }
    for (int i = 0; i < 2 && n > 0; i++)
    {
        n -= b;
        d++;
    }
    cout << d << endl;
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
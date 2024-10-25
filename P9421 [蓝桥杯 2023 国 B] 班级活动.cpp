// https://www.luogu.com.cn/problem/P9421
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 100010;
int n;
int a[N];
int f[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[a[i]]++;
    }
    int cntmore = 0;
    int cntone = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] > 2)
            cntmore += (f[i] - 2);
        else if (f[i] == 1)
            cntone++;
    }
    if (cntmore >= cntone)
        cout << cntmore << endl;
    else
        cout << (cntmore + (cntone - cntmore) / 2) << endl;
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
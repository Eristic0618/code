// https://www.luogu.com.cn/problem/P10424
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

int n, cnt;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 % 2 == 0)
            {
                flag = false;
                break;
            }
            tmp /= 10;
            if (tmp == 0)
                break;
            if (tmp % 10 % 2 == 1)
            {
                flag = false;
                break;
            }
            tmp /= 10;
        }
        if (flag)
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
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
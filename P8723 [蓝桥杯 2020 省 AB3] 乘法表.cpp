// https://www.luogu.com.cn/problem/P8723
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

int p;

void radix(int m, int r)
{
    char a = m / r + '0', b = m % r + '0';
    if ((a - '0') >= 10)
        a = 'A' + (a - '0' - 10);
    if ((b - '0') >= 10)
        b = 'A' + (b - '0' - 10);
    if (a != '0')
        cout << a;
    cout << b << " ";
}

void solve()
{
    cin >> p;
    for (int i = 1; i < p; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char a = '0' + i, b = '0' + j;
            if (i >= 10)
                a = 'A' + (i - 10);
            if (j >= 10)
                b = 'A' + (j - 10);
            cout << a << "*" << b << "=";
            radix(i * j, p);
        }
        cout << endl;
    }
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
// https://www.luogu.com.cn/problem/P9422
// 无测试点，不确定是否ac
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 100010;
int n, m, ans;
queue<int> a, b;

void add(queue<int> &l, queue<int> &s)
{
    while (!l.empty())
    {
        int h1 = l.front(), h2 = s.front();
        l.pop();
        s.pop();
        if (h1 == h2)
            continue;
        else
        {
            while (h1 < h2)
            {
                h1 += l.front();
                l.pop();
                ans++;
            }
            while (h1 > h2)
            {
                h2 += s.front();
                s.pop();
                ans++;
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        b.push(tmp);
    }
    if (n > m)
        add(a, b);
    else if (n < m)
        add(b, a);
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
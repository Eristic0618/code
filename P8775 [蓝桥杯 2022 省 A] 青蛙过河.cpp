//https://www.luogu.com.cn/problem/P8775
// 小青蛙住在一条河边，它想到河对岸的学校去学习。小青蛙打算经过河里的石头跳到对岸。
// 河里的石头排成了一条直线，小青蛙每次跳跃必须落在一块石头或者岸上。不过，每块石头有一个高度，每次小青蛙从一块石头起跳，这块石头的高度就会下降 1
// 当石头的高度下降到 0 时小青蛙不能再跳到这块石头上（某次跳跃后使石头高度下降到 0 是允许的)。
// 小青蛙一共需要去学校上 x 天课，所以它需要往返 2x次。当小青蛙具有一个跳跃能力 y 时，它能跳不超过 y 的距离。
// 请问小青蛙的跳跃能力至少是多少才能用这些石头上完 x 次课。
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 1000000

int n, x;
int h[N];

void solve()
{
    cin >> n >> x;
    for (int i = 1; i < n; i++)
        cin >> h[i];
    int l = 1, r = 0, sum = 0, ans = 0;
    for (; l < n; l++)
    {
        while (r < n && sum < 2 * x)
            sum += h[++r];
        ans = max(ans, r - l + 1);
        sum -= h[l];
    }
    cout << ans << endl;
    return;
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
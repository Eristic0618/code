// https://www.luogu.com.cn/problem/P8800
// 本题未ac，只有80分
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

const int N = 200020;
typedef pair<int, int> PII;

int n, m;
int a[N], b[N];
vector<PII> card;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        card.push_back({a[i], b[i]});
    }
    sort(card.begin(), card.end());
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        int wri = 0;
        for (int i = 0; i < mid; i++)
        {
            if (card[mid].first - card[i].first <= card[i].second)
                wri += card[mid].first - card[i].first;
            else
                wri += card[i].second;
        }
        wri += mid + 1;
        if (wri > m)
            r = mid;
        else
            l = mid + 1;
    }
    for (int i = 0; i <= l - 1; i++)
    {
        if (card[l].first - card[i].first > card[i].second)
        {
            cout << card[i].first + card[i].second << endl;
            return;
        }
        m -= card[l].first - card[i].first;
        card[i].first = card[l].first;
    }
    int k = m / (l + 1);
    card[0].first += k;
    cout << card[0].first << endl;
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
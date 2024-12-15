//https://www.luogu.com.cn/problem/P8775
// С����ס��һ���ӱߣ����뵽�Ӷ԰���ѧУȥѧϰ��С���ܴ��㾭�������ʯͷ�����԰���
// �����ʯͷ�ų���һ��ֱ�ߣ�С����ÿ����Ծ��������һ��ʯͷ���߰��ϡ�������ÿ��ʯͷ��һ���߶ȣ�ÿ��С���ܴ�һ��ʯͷ���������ʯͷ�ĸ߶Ⱦͻ��½� 1
// ��ʯͷ�ĸ߶��½��� 0 ʱС���ܲ������������ʯͷ�ϣ�ĳ����Ծ��ʹʯͷ�߶��½��� 0 �������)��
// С����һ����ҪȥѧУ�� x ��Σ���������Ҫ���� 2x�Ρ���С���ܾ���һ����Ծ���� y ʱ�������������� y �ľ��롣
// ����С���ܵ���Ծ���������Ƕ��ٲ�������Щʯͷ���� x �οΡ�
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
// https://www.luogu.com.cn/problem/P10425
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

int n, c, cnt;
string d;

void solve()
{
    cin >> n >> d;
    // ��d����Ϊȥ��С������ַ���
    auto pos = d.find('.');
    string s1 = d.substr(0, pos);  // ȡ����������
    string s2 = d.substr(pos + 1); // ȡ��С������
    cnt = s2.size();               // ��¼С��λ��
    string m = s1 + s2;            // ƴ��������С������

    for (int i = 0; i < n; i++)
    {
        c = 0;
        for (int j = m.size() - 1; j >= 0; j--)
        {
            int t = m[j] - '0';            // ȡ����Ӧ��λ
            m[j] = (t * 2 + c) % 10 + '0'; // ���㱾λ
            c = (t * 2 + c) / 10;          // �����λ
        }
        if (c > 0) // �����λ��λ
            m = to_string(c) + m;
    }

    pos = m.size() - cnt;  // �ҵ�С����λ��
    s1 = m.substr(0, pos); // ȡ����������
    s2 = m.substr(pos);    // û��С���������Բ�+1
    if (s2[0] - '0' >= 5)  // ����
    {
        c = 1;
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            int t = s1[i] - '0';
            s1[i] = (t + c) % 10 + '0';
            c = (t + c) / 10;
        }
        if (c > 0)
            s1 = "1" + s1;
    }
    cout << s1 << endl;
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
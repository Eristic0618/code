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
    // 将d处理为去掉小数点的字符串
    auto pos = d.find('.');
    string s1 = d.substr(0, pos);  // 取出整数部分
    string s2 = d.substr(pos + 1); // 取出小数部分
    cnt = s2.size();               // 记录小数位数
    string m = s1 + s2;            // 拼接整数和小数部分

    for (int i = 0; i < n; i++)
    {
        c = 0;
        for (int j = m.size() - 1; j >= 0; j--)
        {
            int t = m[j] - '0';            // 取出对应数位
            m[j] = (t * 2 + c) % 10 + '0'; // 计算本位
            c = (t * 2 + c) / 10;          // 计算进位
        }
        if (c > 0) // 向更高位进位
            m = to_string(c) + m;
    }

    pos = m.size() - cnt;  // 找到小数点位置
    s1 = m.substr(0, pos); // 取出整数部分
    s2 = m.substr(pos);    // 没有小数点了所以不+1
    if (s2[0] - '0' >= 5)  // 五入
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
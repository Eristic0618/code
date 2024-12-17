// https://www.luogu.com.cn/problem/P8615
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 10000010

bool f[N];
int a, b;

bool func(int x)
{
    return (int)sqrt(x) == sqrt(x); // 如果x不是平方数，则开方后再平方的结果!=x
}

void solve()
{
    cin >> a >> b;
    for (int i = 1; i <= b; i++) // 枚举从1到b的所有平方数
    {
        if (func(i))
            f[i] = true; // 是平方数
    }
    for (int i = a; i <= b; i++) // 从a到b遍历
    {
        if (f[i]) // i是平方数
        {
            string str = to_string(i); // 转为字符串
            if (str.size() >= 2)       // i不为个位数（可分割）
            {
                for (int j = 1; j <= str.size() - 1; j++) // 枚举分割的位置
                {
                    string s1 = str.substr(0, j);
                    string s2 = str.substr(j);
                    int n1 = stoi(s1), n2 = stoi(s2);
                    if (f[n1] && f[n2]) // f1和f2都是平方数
                    {
                        cout << i << endl; // i为拼接平方数
                        break;
                    }
                }
            }
        }
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
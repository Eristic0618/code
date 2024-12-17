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
    return (int)sqrt(x) == sqrt(x); // ���x����ƽ�������򿪷�����ƽ���Ľ��!=x
}

void solve()
{
    cin >> a >> b;
    for (int i = 1; i <= b; i++) // ö�ٴ�1��b������ƽ����
    {
        if (func(i))
            f[i] = true; // ��ƽ����
    }
    for (int i = a; i <= b; i++) // ��a��b����
    {
        if (f[i]) // i��ƽ����
        {
            string str = to_string(i); // תΪ�ַ���
            if (str.size() >= 2)       // i��Ϊ��λ�����ɷָ
            {
                for (int j = 1; j <= str.size() - 1; j++) // ö�ٷָ��λ��
                {
                    string s1 = str.substr(0, j);
                    string s2 = str.substr(j);
                    int n1 = stoi(s1), n2 = stoi(s2);
                    if (f[n1] && f[n2]) // f1��f2����ƽ����
                    {
                        cout << i << endl; // iΪƴ��ƽ����
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
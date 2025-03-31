// https://www.acwing.com/problem/content/6121/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define INF 0x3f3f3f3f
using namespace std;

#define N 500050

int n;
int a[N];
int f[N]; // 前缀和
int g[N]; // 后缀和

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            f[0] = a[i];
        else
            f[i] = f[i - 1] + a[i];
    }
    g[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) // 后缀和
    {
        g[i] = g[i + 1] + a[i];
    }
    int cake_num2 = (n - 1) / 2; // 埃尔茜最少能吃到的蛋糕数
    int s = n - cake_num2;       // 剩余蛋糕数
    int eat1 = 0;
    int index = 0;
    for (int i = 0; i <= cake_num2; i++) // 无论蛋糕数为奇数还是偶数，埃尔茜最少能吃到的蛋糕数量
    {
        int temp = 0;
        if (i - 1 >= 0)
            temp += f[i - 1];
        if (n - cake_num2 + i < n)
            temp += g[n - cake_num2 + i];
        if (eat1 < temp)
        {
            eat1 = temp;
            index = i;
        }
    }
    int dif = INF;
    int eat2 = 0;
    int sum = g[0] - eat1; // 剩余蛋糕总数
    if (n % 2 == 1)        // 蛋糕数为奇数：以埃尔茜拿走倒数第二个蛋糕为结束
    {
        for (int i = index; i < index + s - 1; i++)
        {
            if (dif > (f[index] - f[index - 1] + g[index + 1] - g[index + s]))
            {
                dif = f[index] - f[index - 1] + g[index + 1] - g[index + s];
                eat2 = max(f[index] - f[index - 1], g[index + 1] - g[index + s]);
            }
        }
    }
    cout << sum - eat2 << " " << eat1 + eat2 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
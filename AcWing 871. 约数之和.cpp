//https://www.acwing.com/problem/content/873/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, res = 1;
unordered_map<int, int> g;
const int mod = 1e9+7;

signed main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        int x;
        cin >> x;
        for(int j = 2; j <= x/j; j++) //分解质因数
        {
            while(x % j == 0)
            {
                g[j]++;
                x /= j;
            }
            if(x == 1)
                break;
        }
        if(x > 1) //存在较大的质因数
            g[x]++;
    }
    for(auto &e : g)
    {
        int cnt = e.second, a = e.first, sum = 1;
        for(int i = 1; i <= cnt; i++)
        {
            sum = (sum * a + 1) % mod; //1 -> p+1 -> p^2+p+1->...-> p^n+...+1
        }
        res = (res * sum) % mod;
    }
    cout << res << endl;
    return 0;
}
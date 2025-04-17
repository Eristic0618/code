//https://www.acwing.com/problem/content/872/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

int n, res = 1;
unordered_map<int, int> g;

signed main()
{
    //要统计乘积的约数个数，只需要将每一个乘数进行分解质因数，然后统计每个质因数的指数之和，再用约数个数计算公式求即可
    //公式：约数个数=(a1+1)(a2+1)...(an+1)
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        int x;
        cin >> x;
        for(int j = 2; j <= x / j; j++) //分解质因数
        {
            while(x % j == 0) //j是质因数
            {
                g[j]++; 
                x /= j;
            }
            if(x == 1) //被除尽了
                break;
        }
        if(x > 1) //分解质因子后剩余的x如果大于1说明x本身是一个比较大的质因数
            g[x]++;
    }
    for(auto &e : g)
    {
        res = (res * (e.second+1)) % mod;
    }
    cout << res << endl;
    return 0;
}
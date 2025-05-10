//https://www.acwing.com/problem/content/875/
#include <bits/stdc++.h>
using namespace std;

int n;
set<double> g;

int main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        g.clear();
        int x;
        cin >> x;
        int res = x;
        for(int j = 2; j <= x/j; j++) //分解质因数
        {
            if(x % j == 0)
            {
                res = res / j * (j-1); //先除再乘预防爆int，j本身就是x的质因子所以不用强转
                while(x % j == 0)
                {
                    x /= j;
                }
            }
            if(x == 1)
                break;
        }
        if(x > 1)
            res = res / x * (x-1);
        
        cout << res << endl;
    }
    return 0;
}
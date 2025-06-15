//https://www.acwing.com/problem/content/243/
#include <iostream>
#include <cstring>
using namespace std;

#define N 200020
#define int long long

int n, res1, res2;
int a[N];
int tr[N]; //树状数组存储某一时刻出现的y
int Greater[N], lower[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for(int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

//思路：通过统计某个y左右两边大于自身的个数，相乘即为V的组合数，反之同理
//统计个数的方法：树状数组
signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++) //从前往后计算第i个y往前大于y和小于y的个数
    {
        int y = a[i];
        Greater[i] = sum(n) - sum(y); //y值是一个个被加入tr的，因此某一时刻n的前缀和减去y的前缀和，即为这个时刻之前出现过的大于y的数
        lower[i] = sum(y-1); //同理
        add(y, 1); //将y加入tr
    }
    
    memset(tr, 0, sizeof tr); //清空tr，开始计算第i个y往后大于y和小于的个数
    for(int i = n; i > 0; i--) //从后往前计算
    {
        int y = a[i];
        res1 += Greater[i] * (sum(n) - sum(y)); //第i个y往前和往后大于它自身的y值个数相乘即为V的组合数
        res2 += lower[i] * sum(y-1); 
        add(y, 1); 
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}

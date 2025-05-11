//https://www.acwing.com/problem/content/876/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 1000010

int n, res;
int primes[N], cnt; //存储质数
int phi[N]; //存储欧拉函数
int st[N]; //判断一个数是否被筛掉了（不是质数）

int get_eulers(int n)
{
    phi[1] = 1; //1是自己的质因数
    for(int i = 2; i <= n; i++) //欧拉筛法
    {
        if(!st[i])
        {
            primes[cnt++] = i; //i是质数
            phi[i] = i-1; //1~i-1所有数都是i的质因数
        }
        for(int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j]*i] = true;
            if(i % primes[j] == 0) //primes[j]是i的质因数
            {
                phi[primes[j] * i] = primes[j] * phi[i]; 
                //φ(pj*i) = pj*i * (1-1/p1)(1-1/p2)...(1-1/pk) [因为pj是i的质因数，已经包含在内了]
                //i * (1-1/p1)(1-1/p2)...(1-1/pk) = φ[i]
                break;
            }
            //primes[j]不是i的质因数，因此求φ(pj*i)时因为新加入了pj所以需要进行处理
            phi[primes[j] * i] = phi[i] * (primes[j]-1);
            //φ(pj*i) = pj*i * (1-1/p1)(1-1/p2)...(1-1/pk)(1-1/pj)
            //pj*(1-1/pj) = pj-1
        }
    }
    for(int i = 1; i <= n; i++)
        res += phi[i];
    return res;
}

signed main()
{
    cin >> n;
    cout << get_eulers(n) << endl;
    return 0;
}
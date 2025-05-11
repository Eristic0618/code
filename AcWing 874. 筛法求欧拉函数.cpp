//https://www.acwing.com/problem/content/876/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 1000010

int n, res;
int primes[N], cnt; //�洢����
int phi[N]; //�洢ŷ������
int st[N]; //�ж�һ�����Ƿ�ɸ���ˣ�����������

int get_eulers(int n)
{
    phi[1] = 1; //1���Լ���������
    for(int i = 2; i <= n; i++) //ŷ��ɸ��
    {
        if(!st[i])
        {
            primes[cnt++] = i; //i������
            phi[i] = i-1; //1~i-1����������i��������
        }
        for(int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j]*i] = true;
            if(i % primes[j] == 0) //primes[j]��i��������
            {
                phi[primes[j] * i] = primes[j] * phi[i]; 
                //��(pj*i) = pj*i * (1-1/p1)(1-1/p2)...(1-1/pk) [��Ϊpj��i�����������Ѿ�����������]
                //i * (1-1/p1)(1-1/p2)...(1-1/pk) = ��[i]
                break;
            }
            //primes[j]����i����������������(pj*i)ʱ��Ϊ�¼�����pj������Ҫ���д���
            phi[primes[j] * i] = phi[i] * (primes[j]-1);
            //��(pj*i) = pj*i * (1-1/p1)(1-1/p2)...(1-1/pk)(1-1/pj)
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
//https://www.acwing.com/problem/content/872/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

int n, res = 1;
unordered_map<int, int> g;

signed main()
{
    //Ҫͳ�Ƴ˻���Լ��������ֻ��Ҫ��ÿһ���������зֽ���������Ȼ��ͳ��ÿ����������ָ��֮�ͣ�����Լ���������㹫ʽ�󼴿�
    //��ʽ��Լ������=(a1+1)(a2+1)...(an+1)
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        int x;
        cin >> x;
        for(int j = 2; j <= x / j; j++) //�ֽ�������
        {
            while(x % j == 0) //j��������
            {
                g[j]++; 
                x /= j;
            }
            if(x == 1) //��������
                break;
        }
        if(x > 1) //�ֽ������Ӻ�ʣ���x�������1˵��x������һ���Ƚϴ��������
            g[x]++;
    }
    for(auto &e : g)
    {
        res = (res * (e.second+1)) % mod;
    }
    cout << res << endl;
    return 0;
}
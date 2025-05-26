//https://www.acwing.com/problem/content/1016/
#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, res;
int a[N], f[N], g[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
        
    for(int i = 1; i <= n; i++) //�������������
    {
        f[i] = 1; //��ʼ��
        for(int j = 1; j < i; j++)
            if(a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }
    for(int i = n; i >= 1; i--) //�����������������
    {
        g[i] = 1; //��ʼ��
        for(int j = n; j > i; j--)
            if(a[i] > a[j])
                g[i] = max(g[i], g[j] + 1);
        res = max(res, f[i] + g[i] - 1);
    }
    cout << res << endl;
    return 0;
}
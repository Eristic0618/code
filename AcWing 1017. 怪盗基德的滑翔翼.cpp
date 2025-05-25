//https://www.acwing.com/problem/content/1019/
#include <bits/stdc++.h>
using namespace std;

#define N 110

int n;
int a[N], f[N];

int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
            
        int res = 0;
        for(int i = 1; i <= n; i++) //���1~i�������������f[i]
        {
            f[i] = 1; //��ʼ��
            for(int j = 1; j < i; j++)
                if(a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
        for(int i = n; i >= 1; i--) //���n~i�������������g[i](�������LIS)
        {
            f[i] = 1;
            for(int j = n; j > i; j--)
                if(a[i] > a[j])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }
        cout << res << endl;
    }
    return 0;
}
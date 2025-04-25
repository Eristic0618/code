//https://www.acwing.com/problem/content/797/
#include <bits/stdc++.h>
using namespace std;

#define N 100010

int n, m;
int a[N], f[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i-1] + a[i];
    }
    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << f[r]-f[l-1] << endl;
    }
    return 0;
}
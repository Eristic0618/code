//https://www.acwing.com/problem/content/description/915/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, cnt;
vector<int> v;

signed main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = n-1; i > 0; i--)
    {
        cnt += v[i] * i;
    }
    cout << cnt << endl;
    return 0;
}
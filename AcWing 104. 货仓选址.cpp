//https://www.acwing.com/problem/content/106/
#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int n, cnt, a[N];

int main()
{
    //|x-a|+|x-b| >= |a-b|
    //只有当x位于a和b之间时，等式才成立，才能取到最小值
    //所以货仓位置要位于0~n-1、1~n-2...每个区间之间
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    int mid = (n-1)/2;
    if(n % 2 == 1) //个数为奇数
        mid--; //去掉中点
    for(int i = 0; i <= mid; i++)
    {
        cnt += a[n-1-i] - a[i];
    }
    cout << cnt << endl;
    return 0;
}
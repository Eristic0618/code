//https://www.acwing.com/problem/content/874/
#include <bits/stdc++.h>
using namespace std;

int n;

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
    cin >> n;
    for(int i = 0;i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}
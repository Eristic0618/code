// https://www.acwing.com/problem/content/843/
#include <iostream>
using namespace std;
typedef unsigned long long ull;

const int N = 100010, P = 131;

int n, m;
char str[N];
ull p[N], h[N];

ull ask(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    cin >> n >> m;
    scanf("%s", str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    for (int i = 0; i < m; i++)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (ask(l1, r1) == ask(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
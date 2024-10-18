// https://www.acwing.com/problem/content/898/
#include <iostream>
using namespace std;

const int N = 100010;

int n;
int a[N], q[N];

int main()
{
    q[0] = -2e9;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    cout << len;
    return 0;
}
//https://www.luogu.com.cn/problem/P8781
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

int n;

int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    double mid = (n+1) / 2.0;
    for (int i = 1; i <= n; i++)
    {
        if (i < mid) //i距离右端点更远
            cout << (n - i) * 2 << endl;
        else //i在中间或距离左端点更远
            cout << (i - 1) * 2 << endl;
    }
    return 0;
}
// https://www.acwing.com/problem/content/871/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> get_devisors(int n)
{
    vector<int> res;
    for (int i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res.push_back(i);
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vector<int> ans = get_devisors(a);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
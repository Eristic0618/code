// https://www.acwing.com/problem/content/795/
#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> &a, int b)
{
    int t = 0;
    vector<int> res;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        res.push_back(t % 10);
        t /= 10;
    }
    if (t)
        res.push_back(t);
    return res;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    if (!b)
    {
        cout << 0;
        return 0;
    }
    vector<int> v;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        v.push_back(a[i] - '0');
    }
    v = mul(v, b);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
    }
    return 0;
}
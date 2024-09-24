// https://www.acwing.com/problem/content/796/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> div(vector<int> &a, int b, int &r)
{
    vector<int> tmp;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        r = r * 10 + a[i];
        tmp.push_back(r / b);
        if (!tmp[0])
            tmp.pop_back();
        r %= b;
    }
    return tmp;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }
    int r = 0;
    A = div(A, b, r);
    if (!A.size())
        cout << 0;
    else
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i];
        }
    cout << endl
         << r << endl;
    return 0;
}
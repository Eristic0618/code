// https://www.acwing.com/problem/content/793/
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

vector<int> add(vector<int> &a, vector<int> &b)
{
    vector<int> tmp;
    int flag = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++)
    {
        int bit = 0;
        if (i < a.size())
            bit += a[i];
        if (i < b.size())
            bit += b[i];
        bit += flag;
        flag = 0;
        if (bit > 9)
        {
            flag = 1;
            bit %= 10;
        }
        tmp.push_back(bit);
    }
    if (flag == 1)
        tmp.push_back(1);
    return tmp;
}

int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    vector<int> C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    return 0;
}
// https://www.acwing.com/problem/content/844/
#include <iostream>
#include <vector>
using namespace std;

#define N 10

bool check[N];
vector<int> v;
int n;

void dfs()
{
    if (v.size() == n)
    {
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (check[i])
            continue;
        v.push_back(i);
        check[i] = true;
        dfs();
        v.pop_back();
        check[i] = false;
    }
}

int main()
{
    cin >> n;
    dfs();
    return 0;
}
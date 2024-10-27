// https://www.acwing.com/problem/content/150/
#include <iostream>
#include <queue>
using namespace std;

const int N = 10010;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    int ans = 0;
    while (!pq.empty())
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += (a + b);
        if (!pq.empty())
            pq.push(a + b);
    }
    cout << ans << endl;
    return 0;
}
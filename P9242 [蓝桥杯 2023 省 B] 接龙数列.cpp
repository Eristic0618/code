// https : // www.luogu.com.cn/problem/P9242
#include <bits/stdc++.h>
using namespace std;

int get_last(int n)
{
    return n % 10;
}

int get_first(int n)
{
    while (n > 9)
        n /= 10;
    return n;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }
    vector<int> dp(10);
    dp[get_last(arr[0])]++;
    for (int i = 1; i < n; i++)
    {
        dp[get_last(arr[i])] = max(dp[get_first(arr[i])] + 1, dp[get_last(arr[i])]);
    }
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (dp[i] > max)
            max = dp[i];
    }
    cout << n - max << endl;
    return 0;
}
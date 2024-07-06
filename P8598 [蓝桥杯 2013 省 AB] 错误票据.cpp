// https://www.luogu.com.cn/problem/P8598
// 题目背景
// 某涉密单位下发了某种票据，并要在年终全部收回。
// 题目描述
// 每张票据有唯一的 ID 号，全年所有票据的 ID 号是连续的，但 ID 的开始数码是随机选定的。因为工作人员疏忽，在录入 ID 号的时候发生了一处错误，造成了某个 ID 断号，另外一个 ID 重号。
// 你的任务是通过编程，找出断号的 ID 和重号的 ID。
// 数据保证断号不可能发生在最大和最小号。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int m = 0, n = 0;
    vector<int> hash(10000, 0);
    int x;
    int min = INT_MAX, amount = 0;
    while (cin >> x)
    {
        if (x < min)
            min = x;
        hash[x]++;
        amount++;
    }
    for (int i = min; i < min + amount; i++)
    {
        if (hash[i] == 2)
            n = i;
        if (hash[i] && !hash[i + 1])
            m = i + 1;
        if (n && m)
            break;
    }
    cout << m << " " << n << endl;
    return 0;
}
// https://www.luogu.com.cn/problem/P8597
// 桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）
// 比如可能情形是 **oo***oooo，如果同时翻转左边的两个硬币，则变为 oooo***oooo。
// 现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币
// 那么对特定的局面，最少要翻动多少次呢？
#include <iostream>
#include <string>
using namespace std;

void roll(char &c)
{
    if (c == '*')
        c = 'o';
    else
        c = '*';
}

int main()
{
    string ori;
    string des;
    cin >> ori >> des;
    int i = 0, j = 0;
    int count = 0;
    while (i < ori.size())
    {
        if (ori[i] != des[j])
        {
            roll(ori[i]);
            roll(ori[i + 1]);
            count++;
        }
        i++;
        j++;
    }
    cout << count << endl;
    return 0;
}
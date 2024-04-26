// https://www.acwing.com/problem/content/3501/
// 有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。
// 输入包含多组测试数据。
// 每组数据占两行，分别表示两个日期，形式为 YYYYMMDD。
#include <bits/stdc++.h>
using namespace std;

int getday(int date)
{
    vector<int> monthday = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int daysum = 0;
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        monthday[2] = 29;
    }
    daysum += day;
    while (month--)
    {
        daysum += monthday[month];
    }
    while (year--)
    {
        daysum += ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 366 : 365);
    }
    return daysum;
}

int main()
{
    int date1, date2;
    while (cin >> date1 >> date2)
    {
        cout << abs(getday(date2) - getday(date1)) + 1 << endl;
    }
    return 0;
}
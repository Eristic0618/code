// https://www.acwing.com/problem/content/3501/
// ���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ���졣
// �����������������ݡ�
// ÿ������ռ���У��ֱ��ʾ�������ڣ���ʽΪ YYYYMMDD��
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
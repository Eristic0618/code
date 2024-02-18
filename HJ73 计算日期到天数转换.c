// 根据输入的日期，计算是这一年的第几天。
// 保证年份为4位数且日期合法。
#include <stdio.h>

int main()
{
    int year, month, day;
    int daycount = 0;
    int month_day[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    scanf("%d %d %d", &year, &month, &day);
    daycount = month_day[month - 1] + day;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        if (month > 2)
        {
            daycount++;
        }
    }
    printf("%d", daycount);
    return 0;
}
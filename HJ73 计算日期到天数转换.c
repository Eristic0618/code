// ������������ڣ���������һ��ĵڼ��졣
// ��֤���Ϊ4λ�������ںϷ���
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
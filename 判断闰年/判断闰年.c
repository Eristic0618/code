//实现函数判断year是不是闰年
#include <stdio.h>

int Leap(int x)
{
    if (((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0))
        return 1;
    else
        return 0;
}

int main()
{
    int year = 0;
    scanf("%d", &year);
    if (Leap(year))
        printf("是闰年\n");
    else
        printf("不是闰年\n");
    return 0;
}
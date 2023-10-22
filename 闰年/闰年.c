//打印1000年到2000年之间的闰年
#include <stdio.h>

int main()
{
    for (int year = 1000; year < 2001; year++)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        {
            printf("%d ", year);
        }
    }
    return 0;
}
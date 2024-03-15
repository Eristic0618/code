// https://www.nowcoder.com/share/jump/8993698061708486568139
// 有一种兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子。
// 例子：假设一只兔子第3个月出生，那么它第5个月开始会每个月生一只兔子。
// 一月的时候有一只兔子，假如兔子都不死，问第n个月的兔子总数为多少？
#include <stdio.h>

int main()
{
    int month;
    scanf("%d", &month);
    int rabbitnum = 0;
    int onemonth = 1;
    int twomonth = 0;
    int adult = 0;
    for (int i = 2; i <= month; i++)
    {
        adult += twomonth;
        twomonth = onemonth;
        onemonth = adult;
        rabbitnum = +onemonth + twomonth + adult;
    }
    printf("%d", rabbitnum);
    return 0;
}
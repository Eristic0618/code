//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
#include <stdio.h>

int main()
{
    double sum = 0;
    int n = 1;
    for (int j = 1; j < 100; j++)
    {
        sum += n * (1.0 / j);
        n = -n;
    }
    printf("%lf", sum);
    return 0;
}
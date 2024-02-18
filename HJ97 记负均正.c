// 首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。
// 0即不是正整数，也不是负数，不计入计算。如果没有正数，则平均值为0。
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int posnum = 0;
    int possum = 0;
    int negnum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            negnum++;
        else if (a[i] > 0)
        {
            posnum++;
            possum += a[i];
        }
    }
    double avg = 0.0;
    if (posnum != 0)
        avg = (double)possum / (double)posnum;
    printf("%d %.1f", negnum, avg);
    return 0;
}
// https://www.nowcoder.com/share/jump/8993698061708487486865
// 数列的定义如下：数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。
// 输入数据有多组，每组占一行，由两个整数n（n<10000）和m(m<1000)组成，n和m的含义如前所述。
// 对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        double *a = (double *)malloc(sizeof(double) * m);
        a[0] = (double)n;
        double sum = a[0];
        for (int i = 1; i < m; i++)
        {
            a[i] = sqrt(a[i - 1]);
            sum += a[i];
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}
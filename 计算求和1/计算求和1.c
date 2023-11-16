//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
//例如：2+22+222+2222+22222
#include <stdio.h>

int main()
{
    int a = 0;
    int sum = 0;
    int b = 0;
    scanf("%d", &a);
    for (int i = 0; i < 5; i++)
    {
        b = b + a;
        sum = sum + b;
        a = a * 10;
    }
    printf("%d", sum);
}
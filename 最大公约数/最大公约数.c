//求两个数的最大公约数
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    printf("请输入两个数\n");
    scanf("%d %d", &a, &b);
    if (a == b)
    {
        printf("最大公约数为%d", a);
    }
    else
    {
        if (a > b)
        {
            int c = 0;
            while (1)
            {
                c = a % b;
                if (a % c == 0 && b % c == 0)
                {
                    printf("最大公约数为%d", c);
                    break;
                }              
                else
                {
                    a = b;
                    b = c;
                }
            }
        }
        else if (a < b)
        {
            int c = 0;
            while (1)
            {
                c = b % a;
                if (a % c == 0 && b % c == 0)
                {
                    printf("最大公约数为%d", c);
                    break;
                }               
                else
                {
                    b = a;
                    a = c;
                }
            }
        }
    }
    return 0;
}
// 获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
#include <stdio.h>

int main()
{
    int n;
    int odd[16] = {0};
    int even[16] = {0};
    int e = 0;
    int o = 0;
    scanf("%d", &n);
    for (int i = 0; i < 32; i++)
    {
        if (i % 2 == 0)
        {
            if ((n >> i) & 1 == 1)
            {
                odd[o] = 1;
                o++;
            }
            else
            {
                odd[o] = 0;
                o++;
            }
        }
        else
        {
            if ((n >> i) & 1 == 1)
            {
                even[e] = 1;
                e++;
            }
            else
            {
                even[e] = 0;
                e++;
            }
        }
    }
    for (o = 15; o >= 0; o--)
    {
        printf("%d", odd[o]);
    }
    printf("\n");
    for (e = 15; e >= 0; e--)
    {
        printf("%d", even[e]);
    }
    return 0;
}
// 打印100-200之间的素数
#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 100; i < 201; i++)
    {
        int flag = 1;
        for (int n = 2; n <= sqrt(i); n++)
        {
            if (i % n == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 1)
        {
            printf("%d ", i);
        }
    }

    return 0;
}
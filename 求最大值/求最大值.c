//求10 个整数中最大值
#include <stdio.h>

int main()
{
    int k[10], i;
    int max = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &k[i]);
        if (k[i] > max)
        {
            max = k[i];
        }
    }
    printf("%d", max);
    return 0;
}
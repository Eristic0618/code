//求两个数二进制中有多少个位不同
#include <stdio.h>

int main()
{
    int x, y;
    int n = 0;
    int m = 0;
    int count = 0;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < 32; i++)
    {
        n = (x >> i) & 1;
        m = (y >> i) & 1;
        if(n!=m)
            count++;
    }
    printf("%d", count);
    return 0;
}
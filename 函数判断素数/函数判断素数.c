#include <stdio.h>
#include <math.h>

int is_prime(int x)
{
    int flag = 1;
    for (int n = 2; n <= sqrt(x); n++)
        if (x % n == 0)
        {
            flag = 0;
            break;
        }
    if (flag == 1)
    {
        printf("%d ", x);
    }
}

int main()
{
    for (int i = 100; i <= 200; i++)
    {
        is_prime(i);
    }
    return 0;
}
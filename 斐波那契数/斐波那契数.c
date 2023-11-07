//用递归计算斐波那契数
// #include <stdio.h>

// int Fib(int x)
// {
//     if(x>=3)
//         return Fib(x - 1) + Fib(x - 2);
//     else
//         return 1;
// }

// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int ret = Fib(n);
//     printf("%d", ret);
//     return 0;
// }

//用迭代计算斐波那契数
#include <stdio.h>

int Fib(int x)
{
    int a = 1;
    int b = 1;
    int c = 1;
    if(x>=3)
    {
        for (int i = 0; i < x - 2;i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
    else
        return c;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ret = Fib(n);
    printf("%d", ret);
    return 0;
}
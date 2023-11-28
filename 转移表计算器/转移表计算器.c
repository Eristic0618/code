// 使用函数指针数组实现转移表
#include <stdio.h>

void Menu()
{
    printf("*********************\n");
    printf("**** 1.Add 2.Sub ****\n");
    printf("**** 3.Mul 4.Div ****\n");
    printf("**** 0.exit *********\n");
    printf("*********************\n");
}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

int main()
{
    int (*parr[5])(int, int) = {0, Add, Sub, Mul, Div};
    int num = 0;
    int x, y;
    while (1)
    {
        Menu();
        printf("请选择:>");
        scanf("%d", &num);
        if (num == 0)
        {
            printf("退出计算器");
            break;
        }
        printf("请输入数值:>");
        scanf("%d %d", &x, &y);
        int ret = parr[num](x, y);
        printf("%d\n", ret);
    }
    return 0;
}
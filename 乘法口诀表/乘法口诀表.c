//打印乘法口诀表，口诀表的行数和列数自己指定
#include <stdio.h>

void Table(int x)
{
    int a;
    int b = 1;
    for (a = 1; a <= x; a++)
    {
        int c = a * b;
        printf("%d*%d=%d\n", a, b, c);
        if (a == x && b < x)
        {
            b++;
            a = 1;
        }
    }
}

int main()
{
    int a = 0;
    scanf("%d", &a);
    Table(a);
    return 0;
}
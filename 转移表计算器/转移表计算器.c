// ʹ�ú���ָ������ʵ��ת�Ʊ�
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
        printf("��ѡ��:>");
        scanf("%d", &num);
        if (num == 0)
        {
            printf("�˳�������");
            break;
        }
        printf("��������ֵ:>");
        scanf("%d %d", &x, &y);
        int ret = parr[num](x, y);
        printf("%d\n", ret);
    }
    return 0;
}
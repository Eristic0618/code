//��ӡ�˷��ھ����ھ���������������Լ�ָ��
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
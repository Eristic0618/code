//�������������Լ��
#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    printf("������������\n");
    scanf("%d %d", &a, &b);
    if (a == b)
    {
        printf("���Լ��Ϊ%d", a);
    }
    else
    {
        if (a > b)
        {
            int c = 0;
            while (1)
            {
                c = a % b;
                if (a % c == 0 && b % c == 0)
                {
                    printf("���Լ��Ϊ%d", c);
                    break;
                }              
                else
                {
                    a = b;
                    b = c;
                }
            }
        }
        else if (a < b)
        {
            int c = 0;
            while (1)
            {
                c = b % a;
                if (a % c == 0 && b % c == 0)
                {
                    printf("���Լ��Ϊ%d", c);
                    break;
                }               
                else
                {
                    b = a;
                    a = c;
                }
            }
        }
    }
    return 0;
}
//����Ļ�����9*9�˷��ھ���
#include <stdio.h>

int main()
{
    int a;
    int b = 1;
    for (a = 1; a < 10; a++)
    {
        int c = a * b;
        printf("%d*%d=%d\n", a, b, c);
        if (a == 9 && b < 9)
        {
            b++;
            a = 1;
        }
    }

    return 0;
}
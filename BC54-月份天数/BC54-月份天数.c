//������ݺ��·ݣ�������һ��������ж�����
#include <stdio.h>

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (b == 2 && (a % 4 == 0 && a % 100 != 0 || a % 400 == 0))
        {
            printf("29\n");
        }
        else
        {
            printf("%d\n", month[b]);
        }
    }
    return 0;
}
//ģ��ʵ�ֿ⺯��strlen
#include <stdio.h>

int My_strlen(char *str)
{
    int i = 0;
    while (*(str + i))
    {
        i++;
    }
    return i;
}

int main()
{
    char str[100];
    gets(str);
    int len = My_strlen(str);
    printf("%d", len);
    return 0;
}
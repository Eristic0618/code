//дһ������ʵ������һ���ַ���������
#include <stdio.h>
#include <string.h>

void Reverse()
{
    char str[10000];
    char *pc = str;
    int i = 0;
    gets(str);
    int len = strlen(str);
    for (i = len-1; i >= 0;i--)
    {
        printf("%c", *(pc + i));
    }
}

int main()
{
    Reverse();
    return 0;
}
//ʵ��һ�����������������ַ����е�k���ַ�
#include <stdio.h>
#include <string.h>

void Circle(char str[], int k)
{
    int len = strlen(str);
    char *pc = str;
    for (int i = k; i < len; i++)
    {
        printf("%c", *(pc + i));
    }
    for (int i = 0; i < k;i++)
    {
        printf("%c", *(pc + i));
    }
}

int main()
{
    char str[10001];
    int k;
    printf("�������ַ���:");
    gets(str);
    printf("���������������ַ���:");
    scanf("%d", &k);
    Circle(str, k);
}
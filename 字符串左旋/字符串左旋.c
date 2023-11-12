//实现一个函数，可以左旋字符串中的k个字符
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
    printf("请输入字符串:");
    gets(str);
    printf("请输入想左旋的字符数:");
    scanf("%d", &k);
    Circle(str, k);
}
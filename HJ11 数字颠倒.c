// https://www.nowcoder.com/share/jump/8993698061708427244819
// ����һ��������������������ַ�������ʽ�������
// ���򲻿��Ǹ���������������ֺ���0����������ʽҲ����0��������Ϊ100�������Ϊ001
#include <stdio.h>
#include <string.h>

int main()
{
    char ch[11];
    scanf("%s", ch);
    int len = strlen(ch);
    char tmp[11];
    int i;
    for (i = 0; i < len; i++)
    {
        tmp[len - i - 1] = ch[i];
    }
    tmp[len] = '\0';
    printf("%s", tmp);
    return 0;
}
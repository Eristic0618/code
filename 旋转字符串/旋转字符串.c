//дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ���
//���磺����s1 =AABCD��s2 = BCDAA������1
//����s1=abcd��s2=ACBD������0
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC
#include <stdio.h>
#include <string.h>

int Circle(char str1[10000], char str2[10000], char str3[10000], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        str2[0] = *(str1 + sz - 1);
        for (int j = 1; j < sz; j++)
        {
            str2[j] = *(str1 + j - 1);
        }
        strcpy(str1, str2);
        if (!strcmp(str2, str3))
            return 1;
    }
    return 0;
}

int main()
{
    char str1[10000];
    printf("�������һ���ַ���:>");
    gets(str1);
    char str2[10000];
    strcpy(str2, str1);
    char str3[10000];
    printf("������ڶ����ַ���:>");
    gets(str3);
    int sz = strlen(str1);
    int ret = Circle(str1, str2, str3, sz);
    printf("%d\n", ret);
    return 0;
}
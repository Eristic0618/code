//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串
//例如：给定s1 =AABCD和s2 = BCDAA，返回1
//给定s1=abcd和s2=ACBD，返回0
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
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
    printf("请输入第一个字符串:>");
    gets(str1);
    char str2[10000];
    strcpy(str2, str1);
    char str3[10000];
    printf("请输入第二个字符串:>");
    gets(str3);
    int sz = strlen(str1);
    int ret = Circle(str1, str2, str3, sz);
    printf("%d\n", ret);
    return 0;
}
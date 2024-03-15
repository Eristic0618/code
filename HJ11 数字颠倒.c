// https://www.nowcoder.com/share/jump/8993698061708427244819
// 输入一个整数，将这个整数以字符串的形式逆序输出
// 程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
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
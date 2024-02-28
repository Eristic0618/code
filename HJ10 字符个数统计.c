// 编写一个函数，计算字符串中含有的不同字符的个数。字符在 ASCII 码范围内( 0~127 ，包括 0 和 127 )
// 换行表示结束符，不算在字符里。不在范围内的不作统计。多个相同的字符只计算一次
// 例如，对于字符串 abaca 而言，有 a、b、c 三种不同的字符，因此输出 3 。
#include <stdio.h>
#include <string.h>

int main()
{
    char ch[500];
    scanf("%s", ch);
    int len = strlen(ch);
    int hash[128] = {0};
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (ch[i] != '\n' && (int)ch[i] >= 0 && (int)ch[i] <= 127)
        {
            hash[(int)ch[i]]++;
        }
    }
    for (int i = 0; i < 128; i++)
    {
        if (hash[i] != 0)
            count++;
    }
    printf("%d", count);
    return 0;
}
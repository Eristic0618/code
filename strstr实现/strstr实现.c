// 模拟实现strstr
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *My_strstr(const char *str1, const char *str2)
{
    assert(str1 && str2);
    while (*str1)
    {
        const char *p1 = str1;
        const char *p2 = str2;
        while (*p1 == *p2)
        {
            p1++;
            p2++;
        }
        if (*p2 == '\0')
        {
            return (char *)str1;
        }
        str1++;
    }
    return NULL;
}

int main()
{
    char arr1[] = {"abbbbcdefg"};
    char arr2[] = {"bbc"};
    char *p = My_strstr(arr1, arr2);
    if (p != NULL)
        printf("%s", p);
    else
        printf("找不到");
    return 0;
}
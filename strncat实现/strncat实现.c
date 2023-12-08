// Ä£ÄâÊµÏÖstrncat
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *My_strncat(char *str1, const char *str2, size_t num)
{
    assert(str1 && str2);
    size_t a = strlen(str2);
    char *p1 = str1;
    while (*p1)
    {
        p1++;
    }
    if (num > a)
    {
        for (int i = 0; i < a; i++)
        {
            *p1++ = *str2++;
        }
        *p1 = '\0';
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            *p1++ = *str2++;
        }
        *p1 = '\0';
    }
    return str1;
}

int main()
{
    char arr1[] = "hello\0xxxxxxxxxxxxx";
    char arr2[] = "world";
    char *pc = My_strncat(arr1, arr2, 7);
    printf("%s", pc);
    return 0;
}
// Ä£ÄâÊµÏÖstrcat
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *My_strcat(char *str1, char *str2)
{
    assert(str1 && str2);
    char *ret = str1;
    while (*str1)
    {
        str1++;
    }
    while (*str2)
    {
        *str1++ = *str2++;
    }
    return ret;
}

int main()
{
    char arr1[20] = {"hello "};
    char arr2[] = {"world"};
    char *p = My_strcat(arr1, arr2);
    printf("%s", p);
    return 0;
}
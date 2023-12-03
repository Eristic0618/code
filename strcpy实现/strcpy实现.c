// Ä£ÄâÊµÏÖstrcpy
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *My_strcpy(char *str1, const char *str2)
{
    assert(str1 && str2);
    while (*str1++ = *str2++)
    {
        ;
    }
}

int main()
{
    char arr1[20] = {0};
    char arr2[] = {"hello"};
    char *p = My_strcpy(arr1, arr2);
    printf("%s", arr1);
    return 0;
}
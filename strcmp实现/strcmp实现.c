// Ä£ÄâÊµÏÖstrcmp
#include <stdio.h>
#include <string.h>
#include <assert.h>

int My_strcmp(const char *str1, const char *str2)
{
    assert(str1 && str2);
    while(*str1==*str2)
    {
        str1++;
        str2++;
    }
    if(*str1>*str2)
    {
        return 1;
    }
    else
        return -1;
}

int main()
{
    char arr1[] = {"abcdefg"};
    char arr2[] = {"abcdevg"};
    int ret = My_strcmp(arr1, arr2);
    printf("%d\n", ret);
    return 0;
}
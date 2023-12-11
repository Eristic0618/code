// Ä£ÄâÊµÏÖstrncpy
#include <stdio.h>
#include <string.h>
#include <assert.h>

char *My_strncpy(char *p1, const char *p2, size_t num)
{
    assert(p1 && p2);
    char *pret = p1;
    size_t cmp = strlen(p2);
    if (cmp < num)
    {
        for (int i = 0; i < cmp; i++)
        {
            *(pret + i) = *(p2 + i);
        }
        for (int j = cmp; j < num; j++)
        {
            *(pret + j) = '\0';
        }
    }
    else
    {
        for (int i = 0; i < num;i++)
        {
            *(pret + i) = *(p2 + i);
        }
    }
    return pret;
}

int main()
{
    char arr1[] = "helloworld";
    char arr2[20] = "xxxxxxxxxxxxxxxx";
    char *p1 = My_strncpy(arr2, arr1, 7);
    printf("%s", p1);
    return 0;
}
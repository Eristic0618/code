// Ä£ÄâÊµÏÖmemmove
#include <stdio.h>
#include <assert.h>

void *My_memmove(void *dest, const void *sour, size_t num)
{
    assert(dest && sour);
    void *ret = dest;
    if (dest > sour)
    {
        for (int i = num - 1; i >= 0; i--)
        {
            *((char *)dest + i) = *((char *)sour + i);
        }
    }
    else
    {
        for (int i = 0; i < num; i++)
        {
            *((char *)dest + i) = *((char *)sour + i);
        }
    }
    return ret;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pi = My_memmove(arr1 + 2, arr1, 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}
// Ä£ÄâÊµÏÖmemcpy
#include <stdio.h>
#include <assert.h>

void *My_memcpy(void *dest, const void *sour, size_t num)
{
    assert(dest && sour);
    void *pd = dest;
    for (int i = 0; i < num; i++)
    {
        *(char *)pd = *(char *)sour;
        (char *)pd++;
        (char *)sour++;
    }
    return dest;
}

int main()
{
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr1[20] = {0};
    int *pi = My_memcpy(arr1, arr2, 20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(pi + i));
    }
    return 0;
}
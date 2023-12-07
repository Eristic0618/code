#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpint(const void *p1, const void *p2)
{
    return *((int *)p1) - *((int *)p2);
}

int main()
{
    size_t n;
    while (scanf("%zd", &n) != EOF)
    {
        int *pn1 = NULL;
        pn1 = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", pn1 + i);
        }
        qsort(pn1, n, sizeof(*(pn1)), cmpint);
        int *pn2 = NULL;
        pn2 = (int *)malloc(sizeof(int) * (n - 1));
        for (int j = 0; j < n - 1; j++)
        {
            *(pn2 + j) = *(pn1 + j + 1) - *(pn1 + j);
        }
        qsort(pn2, n - 1, sizeof(*(pn2)), cmpint);
        printf("%d", *pn2);
        free(pn1);
        free(pn2);
    }
    return 0;
}
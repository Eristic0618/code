#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp_int(const void* p1, const void* p2)
{
    return *((int*)p1) - *((int*)p2);
}

int main()
{
    int n, q;
    int count = 0;
    scanf("%d %d", &n, &q);
    int* book = (int*)malloc(sizeof(int) * n);
    int(*code)[2] = (int(*)[2])malloc(sizeof(int) * 2 * q);
    if (book == NULL||code==NULL)
    {
        perror("malloc");
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", book + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (*(code + i) + 0));
        scanf("%d", (*(code + i) + 1));
    }
    qsort(book, n, sizeof(int), cmp_int);
    for (int j = 0; j < q; j++)
    {
        for (int i = 0; i < n; i++)
		{
            count = 0;
			int tmp = *(book + i);
			while (tmp)
			{
				tmp /= 10;
				count++;
			}
			tmp = *(book + i);
			int x = pow(10, code[j][0]);
			while (tmp > x)
			{
				int y = pow(10, count-1);
				tmp = tmp % y;
				count--;
			}
			if (tmp == code[j][1])
			{
				printf("%d\n", book[i]);
				break;
			}
            if (i == 4)
            {
                printf("-1\n");
                break;
            }
        }
    }
    return 0;
}
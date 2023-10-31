#include <stdio.h>

int main()
{
    int arr[10] = {};
    int a;
    for (a = 0; a < 10; a++)
    {
        scanf("%d", &arr[a]);
    }
    for (a = 9; a >= 0; a--)
    {
        printf("%d ", arr[a]);
    }
    return 0;
}
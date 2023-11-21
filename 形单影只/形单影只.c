//找出整型数组中只出现过一次的数字
#include <stdio.h>

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 1, 2, 3, 4};
    int flag = 1;
    int num = 0;
    for (int i = 0; i < 9; i++)
    {
        flag = 1;
        for (int j = 0; j < 9; j++)
        {
            if (i == j)
                continue;
            else if (arr[i] == arr[j])
                flag = 0;
        }
        if (flag == 1)
        {
            num = arr[i];
        }
    }
    printf("%d", num);
    return 0;
}
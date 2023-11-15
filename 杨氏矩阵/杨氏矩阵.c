// 有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在
// 要求：时间复杂度小于O(N)
#include <stdio.h>

int main()
{
    int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
    int xright = 4;
    int yup = 0;
    int num = 0;
    printf("请输入你要查找的数字:>");
    scanf("%d", &num);
    int flag = 0;
    while (1)
    {
        if (xright < 0 || yup > 2)
        {
            printf("目标不存在\n");
            break;
        }
        else if (arr[yup][xright] > num)
        {
            xright--;
        }
        else if (arr[yup][xright] < num)
        {
            yup++;
        }
        else if (arr[yup][xright] == num)
        {
            printf("目标存在\n");
            break;
        }
    }
    return 0;
}
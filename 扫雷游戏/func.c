#include "func.h"

void Initialize_Array(char arr[ROWS][LINES], int x, int y, char var)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            arr[i][j] = var;
        }
    }
}

void Print_Array(char arr1[ROWS][LINES], int x, int y)
{
    for (int n = 0; n <= x; n++)
    {
        printf("%d ", n);
    }
    printf("\n");
    for (int i = 1; i <= x; i++)
    {
        printf("%d ", i);
        for (int j = 1; j <= y; j++)
        {
            printf("%c ", arr1[i][j]);
        }
        printf("\n");
    }
}

void Set_mine(char arr2[ROWS][LINES], int x, int y)
{
    int count = MINES;
    while (count)
    {
        int j = rand() % ROW + 1;
        int n = rand() % LINE + 1;
        if (arr2[j][n] == '0')
        {
            arr2[j][n] = '1';
            count--;
        }
    }
}

int Traverse_around(char arr3[ROWS][LINES], int x, int y)
{
    return arr3[x - 1][y - 1] + arr3[x - 1][y] + arr3[x - 1][y + 1] + arr3[x][y - 1] + arr3[x][y + 1] + arr3[x + 1][y - 1] + arr3[x + 1][y] + arr3[x + 1][y + 1] - 8 * '0';
}

void Identifying_mine(char arr4[ROWS][LINES], char arr5[ROWS][LINES], int x, int y)
{
    int a, b;
    int win = 0;
    while (win < ROW * LINE - MINES)
    {
        printf("请输入行列:> ");
        scanf("%d %d", &a, &b);
        if (a >= 1 && a <= ROW && b >= 1 && b <= LINE)
        {
            if (arr4[a][b] == '1')
            {
                printf("你被炸死了\n");
                Print_Array(arr4, ROW, LINE);
                break;
            }
            else if (arr4[a][b] == '0')
            {
                system("cls");
                char count = Traverse_around(arr4, a, b) + '0';
                arr5[a][b] = count;
                Print_Array(arr5, ROW, LINE);
                win++;
            }

        }
        else
        {
            printf("非法坐标,请重新输入\n");
        }
    }
    if (win == ROW * LINE - MINES)
    {
        printf("游戏结束，你通关了!\n");
    }
}
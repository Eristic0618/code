#include "func.h"
#include "func.c"

void menu()
{
    printf("**********************\n");
    printf("****    1.play   *****\n");
    printf("****    0.exit   *****\n");
    printf("**********************\n");
}

void game()
{
    // 创建一个地雷二维数组和一个面板二维数组
    char mine[ROWS][LINES];
    char show[ROWS][LINES];

    Initialize_Array(mine, ROWS, LINES, '0'); // 初始化地雷二维数组
    Initialize_Array(show, ROWS, LINES, '*'); // 初始化面板二维数组

    Set_mine(mine, ROW, LINE); //随机设置地雷

    // Print_Array(mine, ROW, LINE); // 打印地雷二维数组
    Print_Array(show, ROW, LINE); // 打印面板二维数组

    Identifying_mine(mine,show,ROW,LINE); //判断地雷
}

int main()
{
    int input;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:> ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            printf("开始游戏\n");
            game();
            break;
        }
        case 0:
        {
            printf("游戏结束\n");
            break;
        }
        default:
        {
            printf("非法操作，请重新输入\n");
            break;
        }
        }
    } while (input);
    return 0;
}
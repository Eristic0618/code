#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game()//游戏实现部分
{
    int num = rand() % 100 + 1;//获取一个100-200之间的随机数
    int a = 0;
    int count = 5;//5次机会
    while(count)
    {
        printf("你还有%d次机会\n", count);
        printf("请输入数字:");
        scanf("%d", &a);
        if(a < num)
        {
            printf("猜小了\n");
        }
        else if(a > num)
        {
            printf("猜大了\n");
        }
        else
        {
            printf("答案正确\n");
            break;
        }
        count--;
    }
    if(count == 0)
    {
        printf("游戏结束，答案是%d\n", num);
    }
    
}

void menu()//菜单栏
{
    printf("*********************************\n");
    printf("*******      1.play       *******\n");
    printf("*******      0.exit       *******\n");
    printf("*********************************\n");
}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:");
        scanf("%d", &input);
        switch (input)
        {
            case 1 :
            {
                printf("开始游戏\n");
                game();
                break;
            } 
            case 0 :
            {
                printf("游戏结束\n");
                break;
            } 
            default:
            {
                printf("输入错误,请重新输入\n");
                break;
            }
        }
    } while (input);
    
    return 0;
}
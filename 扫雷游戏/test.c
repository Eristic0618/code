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
    // ����һ�����׶�ά�����һ������ά����
    char mine[ROWS][LINES];
    char show[ROWS][LINES];

    Initialize_Array(mine, ROWS, LINES, '0'); // ��ʼ�����׶�ά����
    Initialize_Array(show, ROWS, LINES, '*'); // ��ʼ������ά����

    Set_mine(mine, ROW, LINE); //������õ���

    // Print_Array(mine, ROW, LINE); // ��ӡ���׶�ά����
    Print_Array(show, ROW, LINE); // ��ӡ����ά����

    Identifying_mine(mine,show,ROW,LINE); //�жϵ���
}

int main()
{
    int input;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("��ѡ��:> ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
        {
            printf("��ʼ��Ϸ\n");
            game();
            break;
        }
        case 0:
        {
            printf("��Ϸ����\n");
            break;
        }
        default:
        {
            printf("�Ƿ�����������������\n");
            break;
        }
        }
    } while (input);
    return 0;
}
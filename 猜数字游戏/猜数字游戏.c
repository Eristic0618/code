#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game()//��Ϸʵ�ֲ���
{
    int num = rand() % 100 + 1;//��ȡһ��100-200֮��������
    int a = 0;
    int count = 5;//5�λ���
    while(count)
    {
        printf("�㻹��%d�λ���\n", count);
        printf("����������:");
        scanf("%d", &a);
        if(a < num)
        {
            printf("��С��\n");
        }
        else if(a > num)
        {
            printf("�´���\n");
        }
        else
        {
            printf("����ȷ\n");
            break;
        }
        count--;
    }
    if(count == 0)
    {
        printf("��Ϸ����������%d\n", num);
    }
    
}

void menu()//�˵���
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
        printf("��ѡ��:");
        scanf("%d", &input);
        switch (input)
        {
            case 1 :
            {
                printf("��ʼ��Ϸ\n");
                game();
                break;
            } 
            case 0 :
            {
                printf("��Ϸ����\n");
                break;
            } 
            default:
            {
                printf("�������,����������\n");
                break;
            }
        }
    } while (input);
    
    return 0;
}
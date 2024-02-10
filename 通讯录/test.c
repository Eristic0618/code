#include "SeqList.h"

void Menu()
{
	printf("****************ͨѶ¼******************\n");
	printf("****** 1.�����ϵ��  2.ɾ����ϵ�� ******\n");
	printf("****** 3.�޸���ϵ��  4.������ϵ�� ******\n");
	printf("****** 5.�鿴ͨѶ¼  6.���ͨѶ¼ ******\n");
	printf("****** 0.�˳�ͨѶ¼               ******\n");
	printf("****************************************\n");
}

int main()
{
	contact con;
	InitContact(&con);
	LoadContact(&con);
	int option = -1;
	do {
		Menu();
		printf("��ѡ��:\n");
		scanf("%d", &option);
		system("cls");
		switch (option)
		{
		case 1:
			//�����ϵ��
			AddContact(&con);
			break;
		case 2:
			//ɾ����ϵ��
			DelContact(&con);
			break;
		case 3:
			//�޸���ϵ��
			ModifyContact(&con);
			break;
		case 4:
			//������ϵ��
			FindContact(&con);
			break;
		case 5:
			//�鿴ͨѶ¼
			ShowContact(&con);
			break;
		case 6:
			//���ͨѶ¼
			ClearContact(&con);
			break;
		case 0:
			//�˳�ͨѶ¼
			printf("ͨѶ¼�˳���...\n");
			break;
		default:
			printf("�Ƿ�����������������\n");
			break;
		}
	} while (option);
	SaveContact(&con);
	DestoryContact(&con);
	return 0;
}
#include "SeqList.h"

void Menu()
{
	printf("****************通讯录******************\n");
	printf("****** 1.添加联系人  2.删除联系人 ******\n");
	printf("****** 3.修改联系人  4.查找联系人 ******\n");
	printf("****** 5.查看通讯录  6.清空通讯录 ******\n");
	printf("****** 0.退出通讯录               ******\n");
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
		printf("请选择:\n");
		scanf("%d", &option);
		system("cls");
		switch (option)
		{
		case 1:
			//添加联系人
			AddContact(&con);
			break;
		case 2:
			//删除联系人
			DelContact(&con);
			break;
		case 3:
			//修改联系人
			ModifyContact(&con);
			break;
		case 4:
			//查找联系人
			FindContact(&con);
			break;
		case 5:
			//查看通讯录
			ShowContact(&con);
			break;
		case 6:
			//清空通讯录
			ClearContact(&con);
			break;
		case 0:
			//退出通讯录
			printf("通讯录退出中...\n");
			break;
		default:
			printf("非法操作，请重新输入\n");
			break;
		}
	} while (option);
	SaveContact(&con);
	DestoryContact(&con);
	return 0;
}
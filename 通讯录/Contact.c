#include "SeqList.h"

void InitContact(contact* pcon)//初始化通讯录
{
	SeqListInit(pcon);
}

void DestoryContact(contact* pcon)//销毁通讯录
{
	SeqListDestory(pcon);
}

int FindByName(contact* pcon, char* name)//通过姓名查找联系人
{
	for (size_t i = 0; i < pcon->size; i++)
	{
		if (strcmp(name, pcon->a[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void AddContact(contact* pcon)//添加联系人
{
	CheckCapacity(pcon);

	printf("请输入姓名:\n");
	scanf("%s", pcon->a[pcon->size].name);
	printf("请输入年龄:\n");
	scanf("%d", &(pcon->a[pcon->size].age));
	printf("请输入性别:\n");
	scanf("%s", pcon->a[pcon->size].gender);
	printf("请输入电话:\n");
	scanf("%s", pcon->a[pcon->size].telephone);
	printf("请输入住址:\n");
	scanf("%s", pcon->a[pcon->size].address);

	pcon->size++;

	system("cls");
	printf("添加成功!\n");
}

void DelContact(contact* pcon)//删除联系人
{
	char name[100];
	printf("请输入要删除的联系人:\n");
	scanf("%s", name);

	int index = FindByName(pcon, name);
	if (index == -1)
	{
		printf("要删除的用户不存在!\n");
		return;
	}
	SeqListErase(pcon, index);

	system("cls");
	printf("删除成功!\n");
}

void ModifyContact(contact* pcon)//修改联系人信息
{
	char name[100];
	printf("请输入要修改的联系人:\n");
	scanf("%s", name);

	int index = FindByName(pcon, name);
	if (index == -1)
	{
		printf("要修改的用户不存在!\n");
		return;
	}
	system("cls");

	printf("请输入修改后的姓名:\n");
	scanf("%s", pcon->a[index].name);
	printf("请输入修改后的年龄:\n");
	scanf("%d", &(pcon->a[index].age));
	printf("请输入修改后的性别:\n");
	scanf("%s", pcon->a[index].gender);
	printf("请输入修改后的电话:\n");
	scanf("%s", pcon->a[index].telephone);
	printf("请输入修改后的住址:\n");
	scanf("%s", pcon->a[index].address);

	system("cls");
	printf("修改成功!\n");
}

void FindContact(contact* pcon)//查找联系人
{
	char name[100];
	printf("请输入要查找的联系人:\n");
	scanf("%s", name);

	int index = FindByName(pcon, name);
	if (index == -1)
	{
		printf("要查找的用户不存在!\n");
		return;
	}

	system("cls");

	printf("查找成功!\n");
	printf("姓名:%s\n", pcon->a[index].name);
	printf("年龄:%d\n", pcon->a[index].age);
	printf("性别:%s\n", pcon->a[index].gender);
	printf("电话:%s\n", pcon->a[index].telephone);
	printf("住址:%s\n", pcon->a[index].address);
}

void ShowContact(contact* pcon)//展示联系人列表
{
	if (pcon->size == 0)
	{
		printf("通讯录为空!\n");
		return;
	}
	printf("姓名 年龄 性别 电话 地址\n");
	for (size_t i = 0; i < pcon->size; i++)
	{
		printf("%s %d %s %s %s\n",
			pcon->a[i].name,
			pcon->a[i].age,
			pcon->a[i].gender,
			pcon->a[i].telephone,
			pcon->a[i].address);
	}
}

void ClearContact(contact* pcon)//清空通讯录
{
	pcon->size = 0;
	printf("通讯录清空成功!\n");
}

void SaveContact(contact* pcon)//保存通讯录
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (size_t i = 0; i < pcon->size; i++)
	{
		fwrite(pcon->a + i, sizeof(Info), 1, pf);
	}
	printf("通讯录数据保存成功!\n");
	fclose(pf);
}

void LoadContact(contact* pcon)//载入历史通讯录
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen fail");
		return;
	}
	Info info;
	while (fread(&info, sizeof(Info), 1, pf))
	{
		SeqListPushBack(pcon, info);
	}
	printf("通讯录数据载入成功!\n");
	fclose(pf);
}

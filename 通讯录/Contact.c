#include "SeqList.h"

void InitContact(contact* pcon)//��ʼ��ͨѶ¼
{
	SeqListInit(pcon);
}

void DestoryContact(contact* pcon)//����ͨѶ¼
{
	SeqListDestory(pcon);
}

int FindByName(contact* pcon, char* name)//ͨ������������ϵ��
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

void AddContact(contact* pcon)//�����ϵ��
{
	CheckCapacity(pcon);

	printf("����������:\n");
	scanf("%s", pcon->a[pcon->size].name);
	printf("����������:\n");
	scanf("%d", &(pcon->a[pcon->size].age));
	printf("�������Ա�:\n");
	scanf("%s", pcon->a[pcon->size].gender);
	printf("������绰:\n");
	scanf("%s", pcon->a[pcon->size].telephone);
	printf("������סַ:\n");
	scanf("%s", pcon->a[pcon->size].address);

	pcon->size++;

	system("cls");
	printf("��ӳɹ�!\n");
}

void DelContact(contact* pcon)//ɾ����ϵ��
{
	char name[100];
	printf("������Ҫɾ������ϵ��:\n");
	scanf("%s", name);

	int index = FindByName(pcon, name);
	if (index == -1)
	{
		printf("Ҫɾ�����û�������!\n");
		return;
	}
	SeqListErase(pcon, index);

	system("cls");
	printf("ɾ���ɹ�!\n");
}

void ModifyContact(contact* pcon)//�޸���ϵ����Ϣ
{
	char name[100];
	printf("������Ҫ�޸ĵ���ϵ��:\n");
	scanf("%s", name);

	int index = FindByName(pcon, name);
	if (index == -1)
	{
		printf("Ҫ�޸ĵ��û�������!\n");
		return;
	}
	system("cls");

	printf("�������޸ĺ������:\n");
	scanf("%s", pcon->a[index].name);
	printf("�������޸ĺ������:\n");
	scanf("%d", &(pcon->a[index].age));
	printf("�������޸ĺ���Ա�:\n");
	scanf("%s", pcon->a[index].gender);
	printf("�������޸ĺ�ĵ绰:\n");
	scanf("%s", pcon->a[index].telephone);
	printf("�������޸ĺ��סַ:\n");
	scanf("%s", pcon->a[index].address);

	system("cls");
	printf("�޸ĳɹ�!\n");
}

void FindContact(contact* pcon)//������ϵ��
{
	char name[100];
	printf("������Ҫ���ҵ���ϵ��:\n");
	scanf("%s", name);

	int index = FindByName(pcon, name);
	if (index == -1)
	{
		printf("Ҫ���ҵ��û�������!\n");
		return;
	}

	system("cls");

	printf("���ҳɹ�!\n");
	printf("����:%s\n", pcon->a[index].name);
	printf("����:%d\n", pcon->a[index].age);
	printf("�Ա�:%s\n", pcon->a[index].gender);
	printf("�绰:%s\n", pcon->a[index].telephone);
	printf("סַ:%s\n", pcon->a[index].address);
}

void ShowContact(contact* pcon)//չʾ��ϵ���б�
{
	if (pcon->size == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
		return;
	}
	printf("���� ���� �Ա� �绰 ��ַ\n");
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

void ClearContact(contact* pcon)//���ͨѶ¼
{
	pcon->size = 0;
	printf("ͨѶ¼��ճɹ�!\n");
}

void SaveContact(contact* pcon)//����ͨѶ¼
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
	printf("ͨѶ¼���ݱ���ɹ�!\n");
	fclose(pf);
}

void LoadContact(contact* pcon)//������ʷͨѶ¼
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
	printf("ͨѶ¼��������ɹ�!\n");
	fclose(pf);
}

#pragma once

#define NAME_MAX 100
#define GENDER_MAX 10
#define TEL_MAX 11
#define ADDR_MAX 100

struct SqeList;
typedef struct SeqList contact;

typedef struct PersonInfo
{
	char name[NAME_MAX];
	int age;
	char gender[GENDER_MAX];
	char telephone[TEL_MAX];
	char address[ADDR_MAX];
}Info;

void InitContact(contact* pcon);//��ʼ��ͨѶ¼

void DestoryContact(contact* pcon);//����ͨѶ¼

int FindByName(contact* pcon, char* name);//ͨ������������ϵ��

void AddContact(contact* pcon);//�����ϵ��

void DelContact(contact* pcon);//ɾ����ϵ��

void ModifyContact(contact* pcon);//�޸���ϵ����Ϣ

void FindContact(contact* pcon);//������ϵ��

void ShowContact(contact* pcon);//չʾ��ϵ���б�

void ClearContact(contact* pcon);//���ͨѶ¼

void SaveContact(contact* pcon);//����ͨѶ¼

void LoadContact(contact* pcon);//������ʷͨѶ¼


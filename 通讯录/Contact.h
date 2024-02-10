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

void InitContact(contact* pcon);//初始化通讯录

void DestoryContact(contact* pcon);//销毁通讯录

int FindByName(contact* pcon, char* name);//通过姓名查找联系人

void AddContact(contact* pcon);//添加联系人

void DelContact(contact* pcon);//删除联系人

void ModifyContact(contact* pcon);//修改联系人信息

void FindContact(contact* pcon);//查找联系人

void ShowContact(contact* pcon);//展示联系人列表

void ClearContact(contact* pcon);//清空通讯录

void SaveContact(contact* pcon);//保存通讯录

void LoadContact(contact* pcon);//载入历史通讯录


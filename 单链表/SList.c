#include "SList.h"

SLTNode* CreateNewNode(SLTDataType x)//�����½ڵ�
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)//ͷ������ڵ�
{
	assert(pphead);
	SLTNode* newnode = CreateNewNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)//β������ڵ�
{
	assert(pphead);
	SLTNode* newnode = CreateNewNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else 
	{
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SLTPopFront(SLTNode** pphead)//ͷ��ɾ���ڵ�
{
	assert(pphead);
	assert(*pphead);
	SLTNode* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);
}

void SLTPopBack(SLTNode** pphead)//β��ɾ���ڵ�
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

void SLTPrint(SLTNode* plist)//��ӡ������
{
	SLTNode* tmp = plist;
	while (tmp)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL");
}

SLTNode* SLTFind(SLTNode* plist, SLTDataType x)//�ڵ������в�������
{
	SLTNode* tmp = plist;
	while (tmp)
	{
		if (tmp->data == x)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//��posλ��֮ǰ����ڵ�
{
	assert(pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else 
	{
		SLTNode* tmp = *pphead;
		while (tmp->next != pos)
		{
			tmp = tmp->next;
		}
		SLTNode* newnode = CreateNewNode(x);
		newnode->next = pos; 
		tmp->next = newnode;
	}
}

void SLTInsertAfter(SLTNode* pos, SLTDataType x)//��posλ��֮�����ڵ�
{
	assert(pos);
	SLTNode* newnode = CreateNewNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTErase(SLTNode** pphead, SLTNode* pos)//ɾ��posλ�õĽڵ�
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* tmp = *pphead;
		while (tmp->next != pos)
		{
			tmp = tmp->next;
		}
		tmp->next = pos->next;
		free(pos);
	}
}

void SLTEraseAfter(SLTNode* pos)//ɾ��posλ�õĺ�һ���ڵ�
{
	assert(pos);
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}
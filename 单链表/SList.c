#include "SList.h"

SLTNode* CreateNewNode(SLTDataType x)//创建新节点
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

void SLTPushFront(SLTNode** pphead, SLTDataType x)//头部插入节点
{
	assert(pphead);
	SLTNode* newnode = CreateNewNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)//尾部插入节点
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

void SLTPopFront(SLTNode** pphead)//头部删除节点
{
	assert(pphead);
	assert(*pphead);
	SLTNode* tmp = *pphead;
	*pphead = (*pphead)->next;
	free(tmp);
}

void SLTPopBack(SLTNode** pphead)//尾部删除节点
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

void SLTPrint(SLTNode* plist)//打印单链表
{
	SLTNode* tmp = plist;
	while (tmp)
	{
		printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL");
}

SLTNode* SLTFind(SLTNode* plist, SLTDataType x)//在单链表中查找数据
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

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)//在pos位置之前插入节点
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

void SLTInsertAfter(SLTNode* pos, SLTDataType x)//在pos位置之后插入节点
{
	assert(pos);
	SLTNode* newnode = CreateNewNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTErase(SLTNode** pphead, SLTNode* pos)//删除pos位置的节点
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

void SLTEraseAfter(SLTNode* pos)//删除pos位置的后一个节点
{
	assert(pos);
	assert(pos->next);
	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);
}
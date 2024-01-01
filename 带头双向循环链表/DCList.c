#include "DCList.h"

ListNode* ListCreate()//��������ͷ�ڵ�
{
	ListNode* phead = CreateNewNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

ListNode* CreateNewNode(LTDataType x)//�����½ڵ�
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void DListDestory(ListNode* plist)//��������
{
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(plist);
}

void DListPrint(ListNode* plist)//�����ӡ
{
	assert(plist);
	printf("head");
	ListNode* cur = plist->next;
	if (cur != plist)
	{
		while (cur != plist)
		{
			printf("<==>%d", cur->data);
			cur = cur->next;
		}
	}
	printf("<==>");
}

void DLTPushFront(ListNode* plist, LTDataType x)//ͷ������ڵ�
{
	assert(plist);
	ListNode* newnode = CreateNewNode(x);
	ListNode* first = plist->next;
	newnode->next = first;
	first->prev = newnode;
	newnode->prev = plist;
	plist->next = newnode;
}

void DLTPushBack(ListNode* plist, LTDataType x)//β������ڵ�
{
	assert(plist);
	ListNode* newnode = CreateNewNode(x);
	ListNode* tail = plist->prev;
	tail->next = newnode;
	newnode->prev = tail;
	plist->prev = newnode;
	newnode->next = plist;
}

void DLTPopFront(ListNode* plist)//ͷ��ɾ���ڵ�
{
	assert(plist);
	assert(plist->next != plist);
	ListNode* first = plist->next;
	ListNode* second = first->next;
	plist->next = second;
	second->prev = plist;
	free(first);
}

void DLTPopBack(ListNode* plist)//β��ɾ���ڵ�
{
	assert(plist);
	assert(plist->next != plist);
	ListNode* tmp = plist->prev;
	plist->prev = tmp->prev;
	tmp->prev->next = plist;
	free(tmp);
}

ListNode* DListFind(ListNode* plist, LTDataType x)//�������
{
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void DListInsert(ListNode* pos, LTDataType x)//��posǰ�����ڵ�
{
	assert(pos);
	ListNode* newnode = CreateNewNode(x);
	ListNode* posprev = pos->prev;
	newnode->prev = posprev;
	posprev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
}

void DListErase(ListNode* pos)//ɾ��posλ�ýڵ�
{
	assert(pos);
	assert(pos->next != pos);
	ListNode* posprev = pos->prev;
	ListNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}


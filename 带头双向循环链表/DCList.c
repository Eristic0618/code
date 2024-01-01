#include "DCList.h"

ListNode* ListCreate()//创建链表头节点
{
	ListNode* phead = CreateNewNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

ListNode* CreateNewNode(LTDataType x)//创建新节点
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

void DListDestory(ListNode* plist)//链表销毁
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

void DListPrint(ListNode* plist)//链表打印
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

void DLTPushFront(ListNode* plist, LTDataType x)//头部插入节点
{
	assert(plist);
	ListNode* newnode = CreateNewNode(x);
	ListNode* first = plist->next;
	newnode->next = first;
	first->prev = newnode;
	newnode->prev = plist;
	plist->next = newnode;
}

void DLTPushBack(ListNode* plist, LTDataType x)//尾部插入节点
{
	assert(plist);
	ListNode* newnode = CreateNewNode(x);
	ListNode* tail = plist->prev;
	tail->next = newnode;
	newnode->prev = tail;
	plist->prev = newnode;
	newnode->next = plist;
}

void DLTPopFront(ListNode* plist)//头部删除节点
{
	assert(plist);
	assert(plist->next != plist);
	ListNode* first = plist->next;
	ListNode* second = first->next;
	plist->next = second;
	second->prev = plist;
	free(first);
}

void DLTPopBack(ListNode* plist)//尾部删除节点
{
	assert(plist);
	assert(plist->next != plist);
	ListNode* tmp = plist->prev;
	plist->prev = tmp->prev;
	tmp->prev->next = plist;
	free(tmp);
}

ListNode* DListFind(ListNode* plist, LTDataType x)//链表查找
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

void DListInsert(ListNode* pos, LTDataType x)//在pos前面插入节点
{
	assert(pos);
	ListNode* newnode = CreateNewNode(x);
	ListNode* posprev = pos->prev;
	newnode->prev = posprev;
	posprev->next = newnode;
	newnode->next = pos;
	pos->prev = newnode;
}

void DListErase(ListNode* pos)//删除pos位置节点
{
	assert(pos);
	assert(pos->next != pos);
	ListNode* posprev = pos->prev;
	ListNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}


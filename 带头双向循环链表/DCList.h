#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//带头双向循环链表增删查改接口实现

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListCreate();//创建链表头节点

ListNode* CreateNewNode(LTDataType x);//创建新节点

void DListDestory(ListNode* plist);//链表销毁

void DListPrint(ListNode* plist);//链表打印

void DLTPushFront(ListNode* plist, LTDataType x);//头部插入节点

void DLTPushBack(ListNode* plist, LTDataType x);//尾部插入节点

void DLTPopFront(ListNode* plist);//头部删除节点

void DLTPopBack(ListNode* plist);//尾部删除节点

ListNode* DListFind(ListNode* plist, LTDataType x);//链表查找

void DListInsert(ListNode* pos, LTDataType x);//在pos前面插入节点

void DListErase(ListNode* pos);//删除pos位置节点




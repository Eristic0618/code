#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//无头单向非循环链表增删查改接口实现

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* CreateNewNode(SLTDataType x);//创建新节点

void SLTPushFront(SLTNode** pphead, SLTDataType x);//头部插入节点

void SLTPushBack(SLTNode** pphead, SLTDataType x);//尾部插入节点

void SLTPopFront(SLTNode** pphead);//头部删除节点

void SLTPopBack(SLTNode** pphead);//尾部删除节点

void SLTPrint(SLTNode* plist);//打印单链表

SLTNode* SLTFind(SLTNode* plist, SLTDataType x);//在单链表中查找数据

//在指定位置插入节点
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//在pos位置之前插入节点
void SLTInsertAfter(SLTNode* pos, SLTDataType x);//在pos位置之后插入节点

//在指定位置删除节点
void SLTErase(SLTNode** pphead, SLTNode* pos);//删除pos位置的节点
void SLTEraseAfter(SLTNode* pos);//删除pos位置的后一个节点

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��ͷ˫��ѭ��������ɾ��Ľӿ�ʵ��

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

ListNode* ListCreate();//��������ͷ�ڵ�

ListNode* CreateNewNode(LTDataType x);//�����½ڵ�

void DListDestory(ListNode* plist);//��������

void DListPrint(ListNode* plist);//�����ӡ

void DLTPushFront(ListNode* plist, LTDataType x);//ͷ������ڵ�

void DLTPushBack(ListNode* plist, LTDataType x);//β������ڵ�

void DLTPopFront(ListNode* plist);//ͷ��ɾ���ڵ�

void DLTPopBack(ListNode* plist);//β��ɾ���ڵ�

ListNode* DListFind(ListNode* plist, LTDataType x);//�������

void DListInsert(ListNode* pos, LTDataType x);//��posǰ�����ڵ�

void DListErase(ListNode* pos);//ɾ��posλ�ýڵ�




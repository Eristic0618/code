#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��ͷ�����ѭ��������ɾ��Ľӿ�ʵ��

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode* CreateNewNode(SLTDataType x);//�����½ڵ�

void SLTPushFront(SLTNode** pphead, SLTDataType x);//ͷ������ڵ�

void SLTPushBack(SLTNode** pphead, SLTDataType x);//β������ڵ�

void SLTPopFront(SLTNode** pphead);//ͷ��ɾ���ڵ�

void SLTPopBack(SLTNode** pphead);//β��ɾ���ڵ�

void SLTPrint(SLTNode* plist);//��ӡ������

SLTNode* SLTFind(SLTNode* plist, SLTDataType x);//�ڵ������в�������

//��ָ��λ�ò���ڵ�
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//��posλ��֮ǰ����ڵ�
void SLTInsertAfter(SLTNode* pos, SLTDataType x);//��posλ��֮�����ڵ�

//��ָ��λ��ɾ���ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos);//ɾ��posλ�õĽڵ�
void SLTEraseAfter(SLTNode* pos);//ɾ��posλ�õĺ�һ���ڵ�

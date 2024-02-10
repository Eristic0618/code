#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include "Contact.h"

typedef Info SLDataType; //˳���Ԫ������Ϊ��Ÿ�����Ϣ�Ľṹ��

typedef struct SeqList
{
    SLDataType* a;
    size_t size;
    size_t capicity;
} SeqList;

// ˳����ʼ��
void SeqListInit(SeqList* psl);
// ���ռ䣬������ˣ���������
void CheckCapacity(SeqList* psl);
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos);
// ˳�������
void SeqListDestory(SeqList* psl);
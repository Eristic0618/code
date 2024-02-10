#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <Windows.h>
#include "Contact.h"

typedef Info SLDataType; //顺序表元素种类为存放个人信息的结构体

typedef struct SeqList
{
    SLDataType* a;
    size_t size;
    size_t capicity;
} SeqList;

// 顺序表初始化
void SeqListInit(SeqList* psl);
// 检查空间，如果满了，进行增容
void CheckCapacity(SeqList* psl);
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos);
// 顺序表销毁
void SeqListDestory(SeqList* psl);
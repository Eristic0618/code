#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
    STDataType *arr;
    int top;      // ջ��
    int capacity; // ����
} Stack;

void StackInit(Stack *pst); // ��ʼ��ջ

void StackPush(Stack *pst, STDataType x); // ��ջ

void StackPop(Stack *pst); // ��ջ

STDataType StackTop(Stack *pst); // ��ȡջ��Ԫ��

int StackSize(Stack *pst); // ��ȡջ����ЧԪ�ظ���

bool StackEmpty(Stack *pst); // ���ջ�Ƿ�Ϊ��

void StackDestory(Stack *pst); // ����ջ

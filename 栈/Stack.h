#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
    STDataType *arr;
    int top;      // 栈顶
    int capacity; // 容量
} Stack;

void StackInit(Stack *pst); // 初始化栈

void StackPush(Stack *pst, STDataType x); // 入栈

void StackPop(Stack *pst); // 出栈

STDataType StackTop(Stack *pst); // 获取栈顶元素

int StackSize(Stack *pst); // 获取栈中有效元素个数

bool StackEmpty(Stack *pst); // 检测栈是否为空

void StackDestory(Stack *pst); // 销毁栈

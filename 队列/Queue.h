#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode *next;
	QDataType data;
} QNode;

typedef struct Queue
{
	QNode *phead; // 指向队头
	QNode *ptail; // 指向队尾
	int size;	  // 可选，提高效率
} Queue;

// 队列的增删查改接口实现（因为指针在结构体中所以不需要传二级指针）

void QueueInit(Queue *que); // 初始化队列

void QueueDestroy(Queue *que); // 销毁队列

void QueuePush(Queue *que, QDataType x); // 队尾入队列

void QueuePop(Queue *que); // 队头出队列

QDataType QueueFront(Queue *que); // 获取队列头部元素

QDataType QueueBack(Queue *que); // 获取队列队尾元素

int QueueSize(Queue *que); // 获取队列中有效元素个数

bool QueueEmpty(Queue *que); // 检测队列是否为空

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
	QNode *phead; // ָ���ͷ
	QNode *ptail; // ָ���β
	int size;	  // ��ѡ�����Ч��
} Queue;

// ���е���ɾ��Ľӿ�ʵ�֣���Ϊָ���ڽṹ�������Բ���Ҫ������ָ�룩

void QueueInit(Queue *que); // ��ʼ������

void QueueDestroy(Queue *que); // ���ٶ���

void QueuePush(Queue *que, QDataType x); // ��β�����

void QueuePop(Queue *que); // ��ͷ������

QDataType QueueFront(Queue *que); // ��ȡ����ͷ��Ԫ��

QDataType QueueBack(Queue *que); // ��ȡ���ж�βԪ��

int QueueSize(Queue *que); // ��ȡ��������ЧԪ�ظ���

bool QueueEmpty(Queue *que); // �������Ƿ�Ϊ��

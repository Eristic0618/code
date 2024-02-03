#include "Queue.h"

void QueueInit(Queue* que)//��ʼ������
{
	assert(que);
	que->phead = NULL;
	que->ptail = NULL;
	que->size = 0;
}

void QueueDestroy(Queue* que)//���ٶ���
{
	assert(que);
	QNode* cur = que->phead;
	while (cur)
	{
		que->phead = que->phead->next;
		free(cur);
		cur = que->phead;
	}
	que->phead = que->ptail = NULL;
	que->size = 0;
}

void QueuePush(Queue* que, QDataType x)//��β�����
{
	assert(que);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (que->phead == NULL || que->ptail == NULL)
	{
		assert(que->phead == NULL);
		assert(que->ptail == NULL);
		que->phead = que->ptail = newnode;
	}
	else
	{
		que->ptail->next = newnode;
		que->ptail = newnode;
	}
	que->size++;
}

void QueuePop(Queue* que)//��ͷ������
{
	assert(que);
	assert(!QueueEmpty(que));
	if (que->phead->next == NULL)
	{
		free(que->phead);
		que->phead = que->ptail = NULL;
	}
	else
	{
		QNode* cur = que->phead;
		que->phead = que->phead->next;
		free(cur);
	}
	que->size--;
}

QDataType QueueFront(Queue* que)//��ȡ����ͷ��Ԫ��
{
	assert(que);
	assert(!QueueEmpty(que));
	return que->phead->data;
}

QDataType QueueBack(Queue* que)//��ȡ���ж�βԪ��
{
	assert(que);
	assert(!QueueEmpty(que));
	return que->ptail->data;
}

int QueueSize(Queue* que)//��ȡ��������ЧԪ�ظ���
{
	assert(que);
	return que->size;
}

bool QueueEmpty(Queue* que)//�������Ƿ�Ϊ��
{
	assert(que);
	return que->size == 0;
}





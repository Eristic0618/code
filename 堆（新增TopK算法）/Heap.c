#include "Heap.h"

void HeapInit(Heap* hp)//��ʼ����
{
	assert(hp);
	hp->arr = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

void HeapDestory(Heap* hp)//���ٶ�
{
	assert(hp);
	free(hp->arr);
	hp->arr = NULL;
	hp->size = hp->capacity = 0;
}

void AdjustUp(HPDataType* arr, int child)//���ϵ�����С�ѣ�
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] < arr[parent])
		{
			HPDataType tmp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HPDataType* arr, int size, int parent)//���µ�����С�ѣ�
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] < arr[child])
		{
			child = child + 1;
		}
		if (arr[child] < arr[parent])
		{
			HPDataType tmp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HPDataType x)//��������
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(hp->arr, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		hp->arr = tmp;
		hp->capacity = newcapacity;
	}
	hp->arr[hp->size] = x;
	hp->size++;
	AdjustUp(hp->arr, hp->size - 1);
}

void HeapPop(Heap* hp)//ɾ�����ݣ��Ѷ�������β���ݽ�����βɾ���ٵ��ѣ�
{
	assert(hp);
	assert(!HeapEmpty(hp));
	HPDataType tmp = hp->arr[hp->size - 1];
	hp->arr[hp->size - 1] = hp->arr[0];
	hp->arr[0] = tmp;
	hp->size--;
	AdjustDown(hp->arr, hp->size, 0);
}

HPDataType HeapTop(Heap* hp)//��ȡ�Ѷ�����
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->arr[0];
}

int HeapSize(Heap* hp)//�ѵ���Ч���ݸ���
{
	assert(hp);
	return hp->size;
}

bool HeapEmpty(Heap* hp)//�ѵ��п�
{
	assert(hp);
	return hp->size == 0;
}
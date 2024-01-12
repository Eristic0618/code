#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* hp);//��ʼ����

void HeapDestory(Heap* hp);//���ٶ�

void AdjustUp(HPDataType* arr, int child);//���ϵ�����С�ѣ�

void AdjustDown(HPDataType* arr, int size, int parent);//���µ�����С�ѣ�

void HeapPush(Heap* hp, HPDataType x);//��������

void HeapPop(Heap* hp);//ɾ������

HPDataType HeapTop(Heap* hp);//��ȡ�Ѷ�����

int HeapSize(Heap* hp);//�ѵ���Ч���ݸ���

bool HeapEmpty(Heap* hp);//�ѵ��п�
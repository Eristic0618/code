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

void HeapInit(Heap* hp);//初始化堆

void HeapDestory(Heap* hp);//销毁堆

void AdjustUp(HPDataType* arr, int child);//向上调整（小堆）

void AdjustDown(HPDataType* arr, int size, int parent);//向下调整（小堆）

void HeapPush(Heap* hp, HPDataType x);//插入数据

void HeapPop(Heap* hp);//删除数据

HPDataType HeapTop(Heap* hp);//获取堆顶数据

int HeapSize(Heap* hp);//堆的有效数据个数

bool HeapEmpty(Heap* hp);//堆的判空
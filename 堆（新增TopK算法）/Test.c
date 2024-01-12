#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void CreateNData() //创建N个数据
{
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

void PrintTopK(int k) //打印前K个数据
{
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &kminheap[i]);
	}
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kminheap, k, i);
	}
	int val = 0;
	while (!feof(fout))
	{
		fscanf(fout, "%d", &val);
		if (kminheap[0] < val)
		{
			kminheap[0] = val;
			AdjustDown(kminheap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
	printf("\n");
	fclose(fout);
}

void TopK() //TopK算法
{
	CreateNData();
	PrintTopK(5);
}

void Heapsort(int* a, int size) //堆排序
{
	//向上调整建堆
	/*for (int i = 1; i < size; i++)
	{
		AdjustUp(a, i);
	}*/
	//向下调整建堆--O(N)
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}
	while (size > 1)
	{
		int tmp = a[0];
		a[0] = a[size - 1];
		a[size - 1] = tmp;
		size--;
		AdjustDown(a, size, 0);
	}
}

void TestHeapsort1()
{
	int a[] = { 65,100,70,32,50,60 };
	Heapsort(a, sizeof(a) / sizeof(int));
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		printf("%d ", a[i]);
	}
}

void HeapTest1()
{
	Heap hp;
	HeapInit(&hp);
	int a[] = { 65,100,70,32,50,60 };
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HeapPush(&hp, a[i]);
	}
	while (!HeapEmpty(&hp))
	{
		int top = HeapTop(&hp);
		printf("%d\n", top);
		HeapPop(&hp);
	}
	HeapDestory(&hp);
}

int main()
{
	TopK();
	return 0;
}
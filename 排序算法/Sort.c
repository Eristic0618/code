#include "Sort.h"
#include "Stack.h"

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* arr;
	int size;
	int capacity;
}Heap;

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n) //直接插入排序
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp > a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n) //希尔排序 O(N^1.3)
{
	//gap > 1 预排序
	//gap = 1 直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}

void SelectSort(int* a, int n) //选择排序
{
	int begin = 0, end = n - 1;
	int tmp = 0;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[max])
				max = i;
			if (a[i] < a[min])
				min = i; 
		}
		tmp = a[begin];
		a[begin] = a[min];
		a[min] = tmp;
		if (max == begin)
		{
			max = min;
		}
		tmp = a[end];
		a[end] = a[max];
		a[max] = tmp;
		begin++;
		end--;
	}
}

void AdjustDown(int* a, int n, int root)
{
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child = child + 1;
		}
		if (a[child] > a[root])
		{
			HPDataType tmp = a[child];
			a[child] = a[root];
			a[root] = tmp;
			root = child;
			child = root * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n) //堆排序
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	while (n > 1)
	{
		Swap(&a[0], &a[n - 1]);
		n--;
		AdjustDown(a, n, 0);
	}
}

void BubbleSort(int* a, int n) //冒泡排序
{
	for (int i = 0; i < n; i++)
	{
		bool flag = false;
		for (int j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				Swap(&a[j - 1], &a[j]);
				flag = true;
			}
		}
		if (flag == false)
			break;
	}
}

//递归实现快速排序
int PartSort1(int* a, int left, int right) //单轮排序hoare版本
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[key])
		{
			right--;
		}
		while (left < right && a[left] <= a[key])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
	return left;
}

int PartSort2(int* a, int left, int right) //单轮排序挖坑法
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int tmp = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= tmp)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= tmp)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = tmp;
	return left;
}

int PartSort3(int* a, int left, int right) //单轮排序前后指针法
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);
	int key = left;
	int prev = left;
	int cur = left + 1;
	while (cur < right + 1)
	{
		if (a[cur] < a[key])
		{
			prev++;
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[key], &a[prev]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int key = PartSort2(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}

void QuickSort2(int* a, int left, int right) //小区间优化版快排
{
	if (left >= right)
		return;
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
		return;
	}
	int key = PartSort2(a, left, right);
	QuickSort(a, left, key - 1);
	QuickSort(a, key + 1, right);
}

void QuickSortThreeWay(int* a, int left, int right)//三路划分版快排
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	int cur = begin + 1;
	int key = a[left];
	while (cur <= end)
	{
		if (a[cur] < key)
		{
			Swap(&a[cur], &a[begin]);
			cur++;
			begin++;
		}
		else if (a[cur] > key)
		{
			Swap(&a[cur], &a[end]);
			end--;
		}
		else
		{
			cur++;
		}
	}
	QuickSort(a, left, begin - 1);
	QuickSort(a, end + 1, right);
}


int GetMidIndex(int* a, int left, int right)//三数取中
{
	int mid = (left + right) / 2;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}
	else
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] < a[right])
			return right;
		else
			return left;
	}
}

//非递归实现快速排序(栈)
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int keyi = PartSort2(a, begin, end);
		if (keyi + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keyi + 1);
		}
		if (begin < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, begin);
		}
	}
}

//递归实现归并排序
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin == end)
		return;
	int midi = (begin + end) / 2;
	_MergeSort(a, begin, midi, tmp);
	_MergeSort(a, midi + 1, end, tmp);
	int begin1 = begin, end1 = midi;
	int begin2 = midi + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}


void MergeSort(int* a, int n)
{
	int* tmp = malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

//非递归实现归并排序
void MergeSortNonR(int* a, int n)
{
	int* tmp = malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = i;
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
}

void CountSort(int* a, int n) //计数排序
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* tmp = (int*)malloc(sizeof(int) * range);
	memset(tmp, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	int k = 0;
	for (int i = 0; i < range; i++)
	{
		while (tmp[i]--)
		{
			a[k++] = i + min;
		}
	}
}






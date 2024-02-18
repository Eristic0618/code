#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

void PrintArray(int* a, int n);

void InsertSort(int* a, int n);//插入排序

void ShellSort(int* a, int n); //希尔排序

void SelectSort(int* a, int n); //选择排序

void AdjustDown(int* a, int n, int root);//向下调整算法
void HeapSort(int* a, int n); //堆排序

void BubbleSort(int* a, int n); //冒泡排序

// 递归实现快速排序
int PartSort1(int* a, int left, int right); //快速排序hoare版本
int PartSort2(int* a, int left, int right); //快速排序挖坑法
int PartSort3(int* a, int left, int right); //快速排序前后指针法

void QuickSort(int* a, int left, int right);

void QuickSortThreeWay(int* a, int left, int right);//三路划分版快排

int GetMidIndex(int* a, int left, int right);//三数取中

//非递归实现快速排序
void QuickSortNonR(int* a, int left, int right);

//递归实现归并排序
void MergeSort(int* a, int n);

//非递归实现归并排序
void MergeSortNonR(int* a, int n);

void CountSort(int* a, int n); //计数排序
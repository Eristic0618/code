#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdbool.h>

void PrintArray(int* a, int n);

void InsertSort(int* a, int n);//��������

void ShellSort(int* a, int n); //ϣ������

void SelectSort(int* a, int n); //ѡ������

void AdjustDown(int* a, int n, int root);//���µ����㷨
void HeapSort(int* a, int n); //������

void BubbleSort(int* a, int n); //ð������

// �ݹ�ʵ�ֿ�������
int PartSort1(int* a, int left, int right); //��������hoare�汾
int PartSort2(int* a, int left, int right); //���������ڿӷ�
int PartSort3(int* a, int left, int right); //��������ǰ��ָ�뷨

void QuickSort(int* a, int left, int right);

void QuickSortThreeWay(int* a, int left, int right);//��·���ְ����

int GetMidIndex(int* a, int left, int right);//����ȡ��

//�ǵݹ�ʵ�ֿ�������
void QuickSortNonR(int* a, int left, int right);

//�ݹ�ʵ�ֹ鲢����
void MergeSort(int* a, int n);

//�ǵݹ�ʵ�ֹ鲢����
void MergeSortNonR(int* a, int n);

void CountSort(int* a, int n); //��������
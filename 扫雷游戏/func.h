#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define ROW 9  // ��Ϸ��������
#define LINE 9 // ��Ϸ��������

#define ROWS ROW + 2   // ʵ����������
#define LINES LINE + 2 // ʵ����������

#define MINES 10

void Initialize_Array(char arr[ROWS][LINES], int x, int y, char var);

void Print_Array(char arr1[ROWS][LINES], int x, int y);

void Set_mine(char arr2[ROWS][LINES], int x, int y);

void Identifying_mine(char arr4[ROWS][LINES], char arr5[ROWS][LINES], int x, int y);
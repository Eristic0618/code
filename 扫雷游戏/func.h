#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define ROW 9  // 游戏棋盘行数
#define LINE 9 // 游戏棋盘列数

#define ROWS ROW + 2   // 实际数组行数
#define LINES LINE + 2 // 实际数组列数

#define MINES 10

void Initialize_Array(char arr[ROWS][LINES], int x, int y, char var);

void Print_Array(char arr1[ROWS][LINES], int x, int y);

void Set_mine(char arr2[ROWS][LINES], int x, int y);

void Identifying_mine(char arr4[ROWS][LINES], char arr5[ROWS][LINES], int x, int y);
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <locale.h>

#define KEY_PRESS(VK) ((GetAsyncKeyState(VK) & 0x1) ? 1 : 0)

#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

//蛇的初始位置
#define POS_X 24
#define POS_Y 5

enum GAME_STATUS
{
	RUN,
	ESC,
	KILL_BY_WALL,
	KILL_BY_SELF,
};

enum DIRECTION
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

//蛇⾝节点
typedef struct SnakeNode
{
	short x;
	short y;
	struct SnakeNode* next;
}SnakeNode;

typedef struct Snake
{
	SnakeNode* pSnake;//指向蛇头
	SnakeNode* Food; 
	int SleepTime;
	int Score;
	int FoodScore;
	enum GAME_STATUS Status;
	enum DIRECTION Dir;
}Snake;

void GameStart(Snake* ps);

void GameRun(Snake* ps);

void GameEnd(Snake* ps);

void SetPos(short x, short y);//设置光标坐标

void WelcomeToGame();//欢迎界面

void CreateMap();//创建地图

void InitSnake(Snake* ps);//初始化蛇

void CreateFood(Snake* ps);//生成食物

void PrintHelpInfo();//打印教程

void SnakeMove(Snake* ps);//蛇身移动

void EatFood(Snake* ps, SnakeNode* next);//移动后正好吃到食物

void NotEatFood(Snake* ps, SnakeNode* next);//移动后没吃到食物

void KillByWall(Snake* ps);//检测是否撞墙

void KillBySelf(Snake* ps);//检测是否撞到自己


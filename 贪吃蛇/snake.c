#include "snake.h"

void SetPos(short x, short y)//设置光标坐标
{
	COORD pos = { x,y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}

void WelcomeToGame()//欢迎界面
{
	SetPos(45, 10);
	printf("欢迎来到贪吃蛇小游戏");
	SetPos(45, 15);
	system("pause");
	system("cls");
	SetPos(35, 10);
	printf("用 ↑.↓.←.→ 控制蛇的行动，F3为加速，F4为减速");
	SetPos(35, 11);
	printf("加速能得到更多的分数");
	SetPos(45, 15);
	system("pause");
	system("cls");
}

void CreateMap()//创建地图
{
	SetPos(0, 0);
	int i = 0;
	for (i = 0; i < 58; i += 2)
	{
		SetPos(i, 0);
		wprintf(L"%lc", L'□');
	}
	for (i = 0; i < 58; i += 2)
	{
		SetPos(i, 26);
		wprintf(L"%lc", L'□');
	}
	for (i = 1; i < 26; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", L'□');
	}
	for (i = 1; i < 26; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", L'□');
	}
}

void InitSnake(Snake* ps)//初始化蛇
{
	SnakeNode* cur = ps->pSnake = NULL;
	for (int i = 0; i < 5; i++)
	{
		cur = (SnakeNode*)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake:malloc fail");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + i * 2;
		cur->y = POS_Y;
		if (ps->pSnake == NULL)
			ps->pSnake = cur;
		else
		{
			cur->next = ps->pSnake;
			ps->pSnake = cur;
		}
	}

	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	ps->Food = NULL;
	ps->SleepTime = 200;
	ps->Score = 0;
	ps->FoodScore = 10;
	ps->Status = RUN;
	ps->Dir = RIGHT;
}


void CreateFood(Snake* ps)//生成食物
{
	int x = 0;
	int y = 0;
	SnakeNode* cur = ps->pSnake;
again:
	do 
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 == 1);
	
	while (cur)
	{
		if (cur->x == x || cur->y == y)
		{
			goto again;
			break;
		}
		cur = cur->next;
	}

	ps->Food = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (ps->Food == NULL)
	{
		perror("CreateFood:malloc fail");
		return;
	}

	ps->Food->x = x;
	ps->Food->y = y;
	SetPos(x, y);
	wprintf(L"%lc", FOOD);
}

void GameStart(Snake* ps)
{
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
	
	WelcomeToGame();

	CreateMap();

	InitSnake(ps);

	CreateFood(ps);
}

void PrintHelpInfo()//打印教程
{
	SetPos(60, 16);
	printf("请按空格键开始游戏");
	SetPos(60, 17);
	printf("不能撞到墙上或者撞到自己");
	SetPos(60, 18);
	printf("用 ↑.↓.←.→ 控制蛇的行动");
	SetPos(60, 19);
	printf("F3为加速，F4为减速");
	SetPos(60, 20);
	printf("ESC：退出游戏  space：暂停游戏");
}

void pause()//暂停游戏
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

void EatFood(Snake* ps, SnakeNode* next)//移动后正好吃到食物
{
	next->next = ps->pSnake;
	ps->pSnake = next;
	SetPos(next->x, next->y);
	wprintf(L"%lc", BODY);
	
	ps->Score += ps->FoodScore;
	free(ps->Food);
	ps->Food = NULL;
	CreateFood(ps);
}

void NotEatFood(Snake* ps, SnakeNode* next)//移动后没吃到食物
{
	next->next = ps->pSnake;
	ps->pSnake = next;
	SnakeNode* cur = ps->pSnake;
	while (cur->next->next)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;//亲测不置空会出现问题
}

void KillByWall(Snake* ps)//检测是否撞墙
{
	if (ps->pSnake->x == 0 ||
		ps->pSnake->x == 56 ||
		ps->pSnake->y == 0 ||
		ps->pSnake->y == 25)
	{
		ps->Status = KILL_BY_WALL;
	}
}

void KillBySelf(Snake* ps)//检测是否撞到自己
{
	SnakeNode* cur = ps->pSnake->next;
	while (cur)
	{
		if (ps->pSnake->x == cur->x && ps->pSnake->y == cur->y)
		{
			ps->Status = KILL_BY_SELF;
		}
		cur = cur->next;
	}
}

void SnakeMove(Snake* ps)//蛇身移动
{
	SnakeNode* next = (SnakeNode*)malloc(sizeof(SnakeNode));
	if (next == NULL)
	{
		perror("SnakeMove:malloc fail");
		return;
	}

	//移动后正好吃到食物
	switch (ps->Dir)
	{
	case UP:
		next->x = ps->pSnake->x;
		next->y = ps->pSnake->y - 1;
		break;
	case DOWN:
		next->x = ps->pSnake->x;
		next->y = ps->pSnake->y + 1;
		break;
	case LEFT:
		next->x = ps->pSnake->x - 2;
		next->y = ps->pSnake->y;
		break;
	case RIGHT:
		next->x = ps->pSnake->x + 2;
		next->y = ps->pSnake->y;
		break;
	}

	if (next->x == ps->Food->x && next->y == ps->Food->y)
		EatFood(ps, next);
	else
		NotEatFood(ps, next);

	KillByWall(ps);

	KillBySelf(ps);
}

void GameRun(Snake* ps)
{
	PrintHelpInfo();
	do
	{
		//打印信息
		SetPos(60, 10);
		printf("当前得分:%2d", ps->Score);
		SetPos(60, 11);
		printf("当前速度:%3d", (400 - ps->SleepTime) / 40);
		SetPos(60, 12);
		printf("每个食物得分:%2d", ps->FoodScore);

		//判断按键
		if (KEY_PRESS(VK_UP) && ps->Dir != DOWN)
		{
			ps->Dir = UP;
		}
		if (KEY_PRESS(VK_DOWN) && ps->Dir != UP)
		{
			ps->Dir = DOWN;
		}
		if (KEY_PRESS(VK_LEFT) && ps->Dir != RIGHT)
		{
			ps->Dir = LEFT;
		}
		if (KEY_PRESS(VK_RIGHT) && ps->Dir != LEFT)
		{
			ps->Dir = RIGHT;
		}
		if (KEY_PRESS(VK_ESCAPE))
		{
			ps->Status = ESC;
			break;
		}
		if (KEY_PRESS(VK_SPACE))
		{
			pause();
		}
		if (KEY_PRESS(VK_F3))
		{
			if (ps->SleepTime > 40)
			{
				ps->SleepTime -= 40;
				ps->FoodScore += 2;
			}
		}
		if (KEY_PRESS(VK_F4))
		{
			if (ps->FoodScore > 2)
			{
				ps->SleepTime += 40;
				ps->FoodScore -= 2;
			}
		}

		Sleep(ps->SleepTime);
		//蛇身移动
		SnakeMove(ps);

	} while (ps->Status == RUN);
}

void GameEnd(Snake* ps)
{
	SetPos(24, 12);

	switch (ps->Status)
	{
	case KILL_BY_SELF:
		printf("你撞到了自己");
		break;
	case KILL_BY_WALL:
		printf("你撞到墙了");
		break;
	case ESC:
		printf("游戏退出中...");
		break;
	}

	SnakeNode* cur = ps->pSnake;
	while (ps->pSnake)
	{
		ps->pSnake = ps->pSnake->next;
		free(cur);
		cur = ps->pSnake;
	}
}
#include "snake.h"

void Test()
{
	srand((unsigned int)time(NULL));
	char ch = 0;
	do
	{
		Snake snake;
		GameStart(&snake);
		GameRun(&snake);
		GameEnd(&snake);
		if (snake.Status == ESC)
			break;
		SetPos(24, 13);
		printf("再来一局吗?(Y/N):");
		scanf(" %c", &ch);
	} while (ch == 'Y' || ch == 'y');
	SetPos(0, 27);
}

int main()
{
	setlocale(LC_ALL, "chs");
	Test();
	return 0;
}
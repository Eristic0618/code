#include "Queue.h"

void TestQueue1()
{
	Queue que;
	QueueInit(&que);
	QueuePush(&que, 1);
	QueuePush(&que, 2);
	QueuePush(&que, 3);
	QueuePush(&que, 4);
	printf("Size:%d\n", QueueSize(&que));
	while (!QueueEmpty(&que))
	{
		printf("%d ", QueueFront(&que));
		QueuePop(&que);
	}
	QueueDestroy(&que);
}

int main()
{
	TestQueue1();
	return 0;
}
#include"test.h"
int main(){
	queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	Queueprint(&q);
	printf("%d\n",QueueFront(&q));
	printf("%d\n", QueueBack(&q));
	printf("%d\n", QueueSize(&q));
	QueuePop(&q);
	QueuePop(&q);
	Queueprint(&q);
	return 0;
}
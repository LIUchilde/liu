#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
#define queue_size 100
typedef int DataType;
typedef struct QueueNode{
	QueueNode*next;
	DataType data;
}Node;
typedef struct Queue{
	QueueNode* front;//队头
	QueueNode* rear;//队尾
}queue;
void QueueInit(queue*q){
	q->front = q->rear = NULL;
}
void QueueDestory(queue* q){
	while (q->front){
		q->rear = q->front->next;
		delete(q->front);
		q->front = q->rear;
	}
}
//创建新节点
QueueNode* BuyQueueNode(DataType val){
	Node* node = new Node;
	if (node == NULL){
		printf("申请空间失败");
		assert(node);
	}
	node->data = val;
	node->next = NULL;
	return node;
}
void QueuePush(queue* q, DataType val){
	assert(q);
	if (q->front == NULL){
		q->front = q->rear = BuyQueueNode(val);
		return;
	}
	q->rear->next = BuyQueueNode(val);
	q->rear = q->rear->next;
}
void QueuePop(queue* q){
	if (q->front == NULL){
		return;
	}
	else if (q->front == q->rear)
	{
		q->front = NULL;
	}
	Node* pDel = q->front;
	q->front = q->front->next;
	delete pDel;
}
DataType QueueFront(queue* q){
	assert(q);
	return q->front->data;
}
DataType QueueBack(queue* q){
	assert(q);
	return q->rear->data;
}
int QueueEmpty(queue* q){
	return q->front == NULL;
}
int QueueSize(queue* q){
	int count = 0;
	Node* pCur = q->front;
	assert(q);
	while (pCur){
		pCur = pCur->next;
		count++;
	}
	return count;
}
void Queueprint(queue* q){
	assert(q);
	Node* pCur = q->front;
	while (pCur){
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}
#pragma once
#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;
typedef int DataType;
typedef struct ListNode{
	ListNode* next;
	DataType data;
}Node;
void ListNodeInit(Node* head){
	 head = NULL;
}
void ListNodeDestory(Node *head){
	if (head == NULL){
		return;
	}
	while (head){
		Node* next = head->next;
		free(head);
		head = next;
	}
}
Node* ListNodepushFront(Node* head,DataType val){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = val;
	node->next = head;
	head = node;
	return node;
}
Node* ListNodepushBack(Node* head, DataType val){
	Node* node = (Node*)malloc(sizeof(Node));
	Node*cur = head;
	while (cur->next){
		cur = cur->next;
	}
	cur->next = node;
	node->data = val;
	node->next = NULL;
	return head;
}
//第i个位置之前插入元素
Node*ListNodeInsert(Node*head, int i, DataType val){
	if (head == NULL){
		return NULL;
	}
	Node*node = (Node*)malloc(sizeof(Node));
	Node*cur = head;
	for (int j = 1; j < i - 1; ++j){
		cur = cur->next;
	}
	node->next = cur->next;
	cur->next = node;
	node->data = val;
	return head;
}
Node*ListNodepopFront(Node*head){
	assert(head != NULL);
	Node*next = head->next;
	free(head);
	head = next;
	return head;
}
Node*ListNodepopBack(Node*head){
	assert(head != NULL);
	Node*cur = head;
	while (cur->next->next){
		cur = cur->next;
	}
	cur->next = NULL;
	return head;
}
//删除第i个元素
Node*ListNodeErase(Node*head, int i){
	Node* cur = head;
	int j = 1;
	while (cur->next && j < i - 1){
		cur = cur->next;
		j++;
	}
	Node*q = cur->next;
	cur->next = q->next;
	free(q);
	return head;
}
void ListNodeprint(Node* head){
	if (head == NULL){
		return;
	}
	Node* cur = head;
	while (cur != NULL){
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

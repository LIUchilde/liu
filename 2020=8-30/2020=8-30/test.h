#pragma once
#include<iostream>
using namespace std; 
#define stack_size 100
typedef int DataType;
typedef struct stack{
	DataType array[stack_size];
	int top;
}Stack;
void stackInit(Stack*s){
	s->top = 0;
}
void StackDestory(Stack* s){
	s->top = 0;
}
void StackPush(Stack* s, DataType val){
	s->array[s->top] = val;
	s->top++;
}
void StackPop(Stack* s){
	s->array[--s->top];
}
DataType StackTop(Stack* s){
	return s->array[s->top];
}
int StackEmpty(Stack* s){
	return s->top == 0;
}
int StackSize(Stack* s){
	return s->top;
}
int top(Stack* s){
	if (s->top == 0){
		return 0;
	}
	return s->array[s->top - 1];
}
void Stackprint(Stack* s){
	for (int i = 0; i < s->top; ++i){
		printf("%d ", s->array[i]);
	}
	printf("\n");
}
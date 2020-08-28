#pragma once
#include<iostream>
using namespace std;
#define Max_capacity 100
typedef struct seqList{
	int *array;
	size_t size;
	size_t capacity;
}seqList;
void seqListInit(seqList*seq){
	seq->array = (int*)malloc(sizeof(int) * Max_capacity);
	seq->capacity = Max_capacity;
	seq->size = 0;
}
void seqListDestory(seqList *seq){
	free(seq->array);
	seq->capacity = 0;
	seq->size = 0;
}
bool isfull(seqList*seq){
	return seq->size >= seq->capacity;
}
void seqListpushFront(seqList*seq, int val){
	if (isfull(seq)){
		printf("˳������������ɲ���");
	}
	for (int i = seq->size; i > 0; i--){
		seq->array[i] = seq->array[i - 1];
	}
	seq->array[0] = val;
	seq->size++;
}
void seqListpushBack(seqList *seq, int val){
	if (isfull(seq)){
		printf("˳������������ɲ���");
	}
	seq->array[seq->size++] = val;
}
bool empty(seqList *seq){
	return seq->size == 0;
}
void seqListpopFront(seqList *seq){
	if (empty(seq)){
		printf("˳���Ϊ�գ�����ɾ��");
	}
	for (int i = 0; i < seq->size; i++){
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
void seqLisepopBack(seqList *seq){
	if (empty(seq)){
		printf("˳���Ϊ�գ�����ɾ��");
	}
	seq->size--;
}
void seqListInsert(seqList *seq, int i, int val){
	int j;
	if (isfull(seq)){
		printf("˳������������ɲ���");
	}
	else if (i < 0 || i>seq->size){
		printf("�±겻�Ϸ������ɲ���");
	}
	else{
		for (j = seq->size; j > i; j--){
			seq->array[j] = seq->array[j - 1];
		}
		seq->array[i] = val;
		seq->size++;
	}
}
void seqListErase(seqList *seq, int index){
	if (empty(seq)){
		printf("˳���Ϊ�գ�����ɾ��");
	}
	if (index < 0 || index > seq->size){
		printf("�±겻�Ϸ����޷�ɾ��");
	}
	for (int i = index+1; i < seq->size; i++){
		seq->array[i-1] = seq->array[i];	
	}
	seq->size--;
}
void seqListPrint(seqList *seq){
	for (int i = 0; i < seq->size; i++){
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}


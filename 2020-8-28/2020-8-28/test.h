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
		printf("顺序表已满，不可插入");
	}
	for (int i = seq->size; i > 0; i--){
		seq->array[i] = seq->array[i - 1];
	}
	seq->array[0] = val;
	seq->size++;
}
void seqListpushBack(seqList *seq, int val){
	if (isfull(seq)){
		printf("顺序表已满，不可插入");
	}
	seq->array[seq->size++] = val;
}
bool empty(seqList *seq){
	return seq->size == 0;
}
void seqListpopFront(seqList *seq){
	if (empty(seq)){
		printf("顺序表为空，不可删除");
	}
	for (int i = 0; i < seq->size; i++){
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}
void seqLisepopBack(seqList *seq){
	if (empty(seq)){
		printf("顺序表为空，不可删除");
	}
	seq->size--;
}
void seqListInsert(seqList *seq, int i, int val){
	int j;
	if (isfull(seq)){
		printf("顺序表已满，不可插入");
	}
	else if (i < 0 || i>seq->size){
		printf("下标不合法，不可插入");
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
		printf("顺序表为空，不可删除");
	}
	if (index < 0 || index > seq->size){
		printf("下标不合法，无法删除");
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


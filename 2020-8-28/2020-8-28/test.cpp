#include<iostream>
using namespace std;
#include"test.h"
int main(){
	seqList seq;
	seqListInit(&seq);
	seqListpushFront(&seq, 1);
	seqListpushFront(&seq, 2);
	seqListpushFront(&seq, 3);
	seqListPrint(&seq);
	seqListpushBack(&seq, 5);
	seqListpushBack(&seq, 6);
	seqListpushBack(&seq, 7);
	seqListPrint(&seq);
	seqListInsert(&seq, 3, 4);
	seqListPrint(&seq);
	seqListpopFront(&seq);
	seqListPrint(&seq);
	seqLisepopBack(&seq);
	seqListPrint(&seq);
	seqListErase(&seq, 3);
	seqListPrint(&seq);
	return 0;
}
#include"test.h"
int main(){
	Node* head = NULL;
	ListNodeInit(head);
	head = ListNodepushFront(head, 1);
	head = ListNodepushFront(head, 2);
	head = ListNodepushFront(head, 3);
	ListNodeprint(head);
	head = ListNodepushBack(head, 5);
	head = ListNodepushBack(head, 6);
	head = ListNodepushBack(head, 7);
	ListNodeprint(head);
	head = ListNodeInsert(head, 4, 4);
	ListNodeprint(head);
	head = ListNodeErase(head, 4);
	ListNodeprint(head);
	return 0;
}
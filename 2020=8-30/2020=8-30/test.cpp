#include"test.h"
int main(){
	stack s;
	stackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	Stackprint(&s);
	printf("%d\n",top(&s));
	StackPop(&s);
	Stackprint(&s);
	printf("%d\n", top(&s));
	return 0;
}
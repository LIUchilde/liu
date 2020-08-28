#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main(){
	int array[10] = { 0 };
	int *ptr = NULL;
	ptr = (int*)malloc(10 * sizeof(int));
	if (ptr != NULL){
		for (int i = 0; i < 10; ++i){
			*(ptr + i) = 0;
		}
	}
	free(ptr);
	ptr = NULL;
	for (int i = 0; i < 10; ++i){
		printf("%d ", array[i]);
	}
	system("pause");
	return 0;
}
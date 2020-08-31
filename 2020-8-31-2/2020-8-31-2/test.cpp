#include<iostream>
using namespace std;
//直接插入排序
void insertsort(int a[], int size){
	for (int i = 0; i < size; ++i){
		int k = a[i];
		int j;
		for (j = i - 1; j >= 0 && k<a[j]; --j){
			a[j + 1] = a[j];
		}
		a[j + 1] = k;
	}
}
//希尔排序
void insertwithgap(int a[], int size, int gap){
	for (int i = 0; i < size; ++i){
		int k = a[i];
		int j;
		for (j = i - gap; k < a[j] && j >= 0; j -= gap){
			a[j + gap] = a[j];
		}
		a[j + gap] = k;
	}
}
void shellsort(int a[], int size){
	int gap = size;
	while (1){
		gap = gap / 3 + 1;
		insertwithgap(a, size, gap);
		if (gap == 1){
			break;
		}
	}
}
//直接选择
//void selectsort(int a[], int size){
//	for (int i = 0; i < size; ++i){
//		int min = 0;
//		for (int j = i+1; j < size; ++j){
//			if (a[j] < a[min]){
//				min = j;
//			}
//		}
//		int t = a[min];
//		a[min] = a[i];
//		a[i] = t;
//	}
//}
void selectsort(int a[], int size){
	for (int i = 0; i < size; ++i){
		int max = 0;
		for (int j = 1; j < size-i; ++j){
			if (a[j] > a[max]){
				max = j;
			}
		}
		int t = a[max];
		a[max] = a[size-i-1];
		a[size-i-1] = t;
	}
}
//打印
void printArray(int a[], int size){
	for (int i = 0; i < size; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main(){
	int a[] = { 1, 9, 2, 8, 3, 7, 4, 6, 5, 0 };
	int size = sizeof(a) / sizeof(a[0]);
	insertsort(a, size);
	printArray(a, size);
	shellsort(a, size);
	printArray(a, size);
	selectsort(a, size);
	printArray(a, size);
	return 0;
}
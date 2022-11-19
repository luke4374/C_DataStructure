#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

//Partition each time divide array to a list like :[...< pivot <...] 
int Partition(int *D, int low, int high){
	if(D == NULL) return -1;
	int pivot = D[low];
	printf("pivot = %d low = %d high = %d\n",pivot, low, high);
	while(low < high){
		printf("-------high--------\n");
		while(pivot <= D[high] && low < high) high--;
		Show_QSwitch(D, low, high);
		D[low] = D[high];
		printf("--------low-------\n");
		while(pivot >= D[low] && low < high) low++;
		Show_QSwitch(D, low, high);
		D[high] = D[low];
	}
	D[low] = pivot;
	Show_Qlist(D);
	return low;
}

int *Quick_Sort(int *arr, int low, int high){
	if(arr == NULL) return NULL;
	if(low < high){
		int pos = Partition(arr, low, high);	
		printf("pos = %d\n", pos);
		getchar();
		Quick_Sort(arr, low, pos-1);
		Quick_Sort(arr, pos+1, high);
	}	
	return arr;
}

int main(){
	array *arr = Init_Array();
	Show_Array(arr);
	int *D = Quick_Sort(arr->data, 0, MAX_LEN-1);
	Show_Qlist(D);
	Free_Array(arr);
	exit(0);
}

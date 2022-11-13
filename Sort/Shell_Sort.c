#include<stdio.h>
#include<stdlib.h>
#include"Array.h"

array *Shell_Sort(array *a){	
	if(a == NULL) return NULL;
	int len = a->length, tmp, k;
	for(int i = len/2; i >= 1; i = i/2){
		for(int j = i; j <= len-1; j++){
			//printf("a[%d] = %d ", j, a->data[j]);	
			//printf("a[%d] = %d\n",j-i, a->data[j-i]);	
			if(a->data[j] < a->data[j-i]){
				tmp = a->data[j];
				//Insert Sort
				for(k = j-i; k >= 0 && tmp < a->data[k]; k-=i){
					a->data[k+i] = a->data[k];	
				}
				a->data[k+i] = tmp;
			}
		}
		//Show_Array(a);
		//printf("----------------\n");
	}
	return a;
}

int main(){
	array *A = Init_Array();
	Show_Array(A);
	A = Shell_Sort(A);
	Show_Array(A);
	Free_Array(A);
	exit(0);
}

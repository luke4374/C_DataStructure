#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Array.h"

int Insert_Sort(array *tar){
	if(tar == NULL) return 0;
	int temp,i,j;
	for(i = 1; i < tar->length; i++){
		if(tar->data[i] < tar->data[i-1]){
			temp = tar->data[i];
			/*Compare from tail
			. . . x . . .
				  |
			  <----
			*/ 
			//j-- might come to -1, could cause invalid read
			for(j = i - 1; temp < tar->data[j]; --j){
				tar->data[j + 1] = tar->data[j];
			}
			tar->data[j + 1] = temp;	
		}
	}
	return 1;
}

int Binary_Insert(array *t){
	if(t == NULL) return 0;
	int low, high, mid, i, j;   
	for(i = 1; i < t->length; i++){
		int x = t->data[i];
		low = 0, high = i - 1;
		while(low <= high){	
			mid = (low + high) / 2;
			if(t->data[mid] > x) high = mid - 1;
			else low = mid + 1;
		}
		//printf("(%d)low = %d, high = %d, mid = %d\n",i, low, high, mid);
		for(j = i - 1; j >= high + 1; j--){
			t->data[j+1] = t->data[j];
		}
		t->data[high+1] = x;
		//Show_Array(t);
	}
	return 1;
}

void Duration(clock_t S, clock_t E){
	double duration;
	duration = ((double)E - S)/CLOCKS_PER_SEC; 
	printf("%ld %ld duration :%f\n", S, E, duration);
	return;
}

int main(){
	clock_t start, end; 
	array *A = Init_Array();
	Show_Array(A);
	start = clock();
	Insert_Sort(A);
	end = clock();
	Duration(start, end);
	Show_Array(A);
	Free_Array(A);
	
	//sleep(1);
	array *B = Init_Array();
	Show_Array(B);
	start = clock();
	Binary_Insert(B);
	end = clock();
	Duration(start,end);
	Show_Array(B);
	Free_Array(B);
	exit(0);
}

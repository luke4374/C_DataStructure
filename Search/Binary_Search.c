#include <stdio.h>
#include <stdlib.h>
#include "Linear_List.h"

int Binary_Search(List *List, int num){
	int low, mid, high;
	low = 0;
	high = List->length - 1;
	while(low <= high){
		mid = (low + high) / 2;
		printf("low = %d mid = %d high = %d \n",low, mid, high);
		if(List->seqList[mid] == num) return mid;
		if(List->seqList[mid] < num){
			low = mid + 1;	
		}else{
			high = mid -1;
		}
	}	
	return -1;
}

int main(){
	int key, check;
	List *L = Init_list();
	Show_Linear(L);
	scanf("%d",&key);
	check = Binary_Search(L, key);
	if(check == -1) printf("No such number\n");
	else printf("num %d is in %d\n", key, check);
	free_seqList(L);
	exit(0);
}

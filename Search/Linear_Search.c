#include <stdio.h>
#include <stdlib.h>
#include "Linear_List.h"

int Linear_Search(List *L, int target){
	if(L->seqList == NULL) return -1;
	for(int i = 0; i < MAX_LEN; i++){
		if(L->seqList[i] == target) return i;
	}
	return -2;
}

int main(){
	int key, check;
	List *list = Init_list();
	Show_Linear(list);
	scanf("%d",&key);
	check = Linear_Search(list, key);
	if(check >= 0){	
		printf("Num %d is at %d\n", key, check);	
	}else{
		printf("No Such Number\n");
	}
	free_seqList(list);
	exit(0);
}

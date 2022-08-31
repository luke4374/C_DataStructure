#include <time.h>
#define MAX_LEN 10

typedef struct seqList{
	int *seqList;
	int length;
}List;

List *Init_list(){
	srand(time(0));
	int num = rand() % 100;
	List *list = (List *)malloc(sizeof(List));
	list->seqList = (int *)malloc(sizeof(int) * MAX_LEN);
	list->length = MAX_LEN; 
	for(int i = 0; i < MAX_LEN; i++){
		list->seqList[i] = num + (i * 3);	
	} 
	return list;	
}

/*
Show Functions
*/
void Show_Linear(List *list){
	if(list == NULL) return ;
	for(int i = 0; i < MAX_LEN; i++){
		printf("%d[%d] ", i, list->seqList[i]);
	}
	printf("\n");
	return ;
}

//free list
void free_seqList(List *L){
	if(L == NULL) return;
	free(L->seqList);
	free(L);
	return;
}

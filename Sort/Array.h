#include <stdio.h>
#include <time.h>
#define MAX_LEN 10 

typedef struct array{
	int *data;
	int length;
}array;

array *Init_Array(){
	srand(time(0));
	int x = rand() % 100;
	array *ary = (array *)malloc(sizeof(array));
	ary->data = (int *)malloc(sizeof(int) * MAX_LEN);
	ary->length = MAX_LEN;
	for(int i = 0; i < MAX_LEN; i++){
		ary->data[i] = x + rand() % 100;
	} 
	return ary;
}

int Show_Array(array *a){
	if(a == NULL) return 0;
	for(int i = 0; i < MAX_LEN; i++){
		printf("[%d]%d ", i, a->data[i]);
	}
	printf("\n");
	return 1;
}

void Show_QSwitch(int *a, int low, int high){
	if(a == NULL) return;
	printf("Switch a[%d]=%d & a[%d]=%d\n", low, a[low], high, a[high]);
	return;
}

void Show_Qlist(int *a){
	if(a == NULL) return;
	for(int i = 0; i < MAX_LEN; i++){
		printf("(%d)%d ", i, a[i]);	
	}
	printf("\n");
	return;
}

void Free_Array(array *a){
	if(a == NULL) return ;
	free(a->data);
	free(a);
	return;
}

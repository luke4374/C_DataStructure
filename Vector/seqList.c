#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define OP_MAX 10
typedef struct {
	int *data;//dynamic
	int size,length;
}Seqlist;

void *init(int n){
	Seqlist *seq = (Seqlist *)malloc(sizeof(Seqlist));
	seq->data = (int *)malloc(sizeof(int) * n);	
	seq->size = n;
	seq->length = 0;
	return seq; 
}
int insert(Seqlist *L, int ind, int val){
	if(L == NULL) return 0;
	if(L->length == L->size) return 0;
	if(ind < 0 || ind > L->length) return 0;
	for(int i = L->length; i > ind; i--){
		L->data[i] = L->data[i - 1];
	}
	L->data[ind] = val;
	L->length += 1;
	return 1;
}

int delete(Seqlist *L, int ind){
	if(L ==NULL) return 0;
	if(ind < 0||ind > L->length - 1) return 0;
	for(int i = ind; i < L->length; i++){
		L->data[i] = L->data[i+1];
	}
	L->length--;
	return 1;
}

int show(Seqlist *L){
	if(L == NULL) return 0;
	printf("SeqList(%d):[ ",L->length);
	for(int i = 0; i < L->length;i++){
		printf("%d ",L->data[i]);
	}
	printf("]\n");
	return 1;
}

void Free(Seqlist *L){
	if(L == NULL) return;
	free(L->data);
	free(L);
	return;
}

int main(){
	srand(time(0));
	int op,ind,val;
	Seqlist *L = init(20);
	for(int i = 0; i < OP_MAX; i++){
		op = rand() % 2;
		ind = rand() % (L->length+3);//length+1始终先从零开始
		val = rand() % 100;
		switch(op){
			case 0:
				{
					printf("insert %d into %d return value = %d\n"
							,val,ind,insert(L,ind,val));
					//insert(L,ind,val);
				}break;
			case 1:
				{
					printf("delete at %d return value = %d\n"
							,ind,delete(L,ind));
					//delete(L,ind);
				}break;
		} 
		show(L);
	}	
	Free(L);

	exit(0);

}

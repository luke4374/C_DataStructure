#include <stdio.h>
#include <stdlib.h>
#include "Linear_List.h"
#define HASH_LEN 7

typedef struct Hash_Node{
	int num;
	struct Hash_Node *next;
}H_Node, H_Table;

int Add_Node(H_Node *n, int x){
	if(n->next == NULL){
		H_Node *hn = (H_Node *)malloc(sizeof(H_Node));
		hn->num = x;
		hn->next = NULL;
		n->next = hn;
		//printf("insert after %d(%p), %d\n", n->num, n->next, hn->num);
	}else{
		Add_Node(n->next, x);
	}	
	return 1;
} 

int Init_HT(H_Table *ht, int *l){
	if(l == NULL) return -1;
	int k;
	for(int i = 0; i < MAX_LEN; i++){
		ht[i].num = 0;
		ht[i].next = NULL;
	}	
	for(int i = 0; i < MAX_LEN; i++){
		k = l[i] % HASH_LEN; 
		Add_Node(&ht[k], l[i]);
	}	
	return 1;	
}

void Show_HT(H_Table *ht){
	if(ht == NULL) return;
	printf("Hash Table:\n");
	for(int i = 0; i < HASH_LEN; i++){
		H_Node *n = ht[i].next;
		printf("[%d] %d ", i, ht[i].num); 
		while(n != NULL){
			printf("-> %d ", n->num);
			n = n->next;
		}
		printf("\n");
	}
	return;
}

void Hash_Find(H_Table *ht, int num){
	if(ht == NULL) return;
	int key = num % HASH_LEN;
	H_Node *n = &ht[key];
	while(n != NULL){
		if(n->num == num) printf("number %d founded!\n", num);
		n = n->next;
	}
	return;
}

void Free_HN(H_Node *n){
	if(n == NULL) return;
	if(n->next != NULL) Free_HN(n->next);
	free(n);
	return;
}

void Free_HT(H_Table *ht){
	if(ht == NULL) return;
	for(int i = 0; i < HASH_LEN; i++){
		H_Node *n = &ht[i];
		Free_HN(n);	
	}
	free(ht);
	return;
}

int main(){
	List *L = Init_list(); 
	Show_Linear(L);
	H_Table ht[HASH_LEN]; 
	Init_HT(ht, L->seqList);	
	Show_HT(ht);	
	for(int i = 0; i < MAX_LEN; i++){
		Hash_Find(ht, L->seqList[i]); 
	}
	Free_HT(ht);
	free_seqList(L);
	exit(0);
}

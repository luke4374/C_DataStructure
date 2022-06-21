#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;

typedef struct LinkQueue{
	LinkNode *front, *rear;
}LinkQueue;

LinkQueue *init_LiQueue(){
	//Head Node
	LinkQueue *L = (LinkQueue *)malloc(sizeof(LinkQueue));
	L->front = L->rear = (LinkNode *)malloc(sizeof(LinkNode));
	L->front->next = NULL;
	return L;
}

int Is_Empty(LinkQueue *L){
	return L->front == L->rear;
}

int En_Queue(LinkQueue *L, int x){
	if(L==NULL) return 0;
	LinkNode *n = (LinkNode *)malloc(sizeof(LinkNode));
	n->data = x;
	n->next = NULL;
	L->rear->next = n;
	L->rear = n;
	return 1;	
}

int De_Queue(LinkQueue *L){
	if(L==NULL) return 0;
	if(Is_Empty(L)) return -1;
	LinkNode *n = L->front->next;
	L->front->next = n->next;
	if(L->rear == n){
		L->rear = L->front;
	}
	free(n);
	return 1;
}

void show(LinkQueue *L){
	if(L==NULL) return ;
	LinkNode *n = L->front->next;
	printf("LinkQueue: [");
	while(n){
		printf(" %d -> ", n->data);
		n = n->next;	
	}
	printf("NULL ] front->next = %p rear = %p\n", L->front->next, L->rear);

	return ;
}

int main(){
	srand(time(0));
	LinkQueue * L = init_LiQueue();
	for(int i = 0; i < 10; i++){
		int op = rand() % 2;
		int val = rand() % 100;
		switch(op){
			case 0:{
				printf("%d EnQueue return = %d\n",val, En_Queue(L, val));	
			}break;
			case 1:{
				printf("DeQueue return = %d\n", De_Queue(L));
			}break;	
		}	
		show(L);
	}	
	exit(0);
}

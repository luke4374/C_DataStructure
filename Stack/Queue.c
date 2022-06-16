#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 10

typedef struct queue{
	//int data[MAXSIZE];
	//Dynamic alocate
	int *data;
	int top, rear;
	int length;
}sqQueue;

sqQueue *init_Queue(int n){
	sqQueue *Q = (sqQueue *)malloc(sizeof(sqQueue));
	Q->data = (int *)malloc(sizeof(int) * n);
	Q->top = 0;
	Q->rear = 0;
	Q->length = n;
	return Q;
}

int front(sqQueue *Q){
	return Q->data[Q->top];
}

int is_Empty(sqQueue *Q){
	return Q->top == Q->rear;
}

int en_Queue(sqQueue *Q, int x){
	if(Q == NULL) return 0;
	if(Q->rear == Q->length) return 0;
	Q->data[Q->rear++] = x;
	return 1;
}

int de_Queue(sqQueue *Q){
	if(Q == NULL) return 0;
	if(is_Empty(Q)) return 0;
	Q->top++;
	return 1;
} 

void show_Queue(sqQueue *Q){
	int i = Q->rear;
	int j = Q->top;
	printf(" Queue(T->%d R->%d): [", Q->top, Q->rear);
	for(j; j < i; j++){
		printf(" %d",Q->data[j]);
	}
	printf(" ]\n");
}

void clear_Queue(sqQueue *Q){
	if(Q == NULL) return;
	free(Q->data);
	free(Q);
	return;
}

int main(){
	//initial random seeds
	srand(time(0));
	int De_num;
	sqQueue *q = init_Queue(MAXSIZE);
	for(int i = 0; i < MAXSIZE; i++){
		int val = rand() % 100, op = rand() % 2;	
		switch(op){
			case 0: {
				printf("%d Enqueue return %d\n", val, en_Queue(q, val));
			}break;
			case 1: {
				De_num = front(q);	
				printf("%d Dequeue return %d\n", De_num, de_Queue(q));
			}break;			
		}
		show_Queue(q);
	}	
	

	exit(0);
}

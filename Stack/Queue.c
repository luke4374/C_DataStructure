#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 10
#define OP 20
typedef struct queue{
	//int data[MAXSIZE];
	//Dynamic alocate
	int *data;
	int top, rear;
	int length;
	int count;//num in Queue
}sqQueue;

sqQueue *init_Queue(int n){
	sqQueue *Q = (sqQueue *)malloc(sizeof(sqQueue));
	Q->data = (int *)malloc(sizeof(int) * n);
	Q->top = Q->rear = 0;
	//diff
	Q->count = 0;
	Q->length = n;
	return Q;
}

int front(sqQueue *Q){
	return Q->data[Q->top];
}

int is_Empty(sqQueue *Q){
	//return Q->top == Q->rear;
	return Q->count == 0;
}

int en_Queue(sqQueue *Q, int x){
	if(Q == NULL) return 0;
	if(Q->count == Q->length) return 0;
	//SeqQueue
	Q->data[Q->rear++] = x;
	//Circular Queue	
	if(Q->rear == Q->length){
		Q->rear = (Q->rear) % MAXSIZE;
	}
	Q->count++;
	return 1;
}

int de_Queue(sqQueue *Q){
	if(Q == NULL) return 0;
	if(is_Empty(Q)) return 0;
	//Seq
	Q->top++;

	//Circular Queue
	if(Q->top == Q->length) {
		Q->top = (Q->top) % MAXSIZE;
	}
	Q->count--;
	return 1;
} 

void show_Queue(sqQueue *Q){
	int r = Q->rear;
	int t = Q->top;
	int length = (r + MAXSIZE - t) % MAXSIZE;
	int ind;
	printf(" Queue(T->%d R->%d): [", Q->top, Q->rear);
	for(int i = 0; i < length; i++){
		ind = ( t + i ) % MAXSIZE;	
		printf(" %d",Q->data[ind]);
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
	for(int i = 0; i < OP; i++){
		int val = rand() % 100, op = rand() % 4;	
		switch(op){
			case 0:
			case 1:
			case 2: {
				printf("%d Enqueue return %d\n", val, en_Queue(q, val));
			}break;
			case 3: {
				//GCC compile problem, system stack pushed from right -> left
				De_num = front(q);	
				printf("%d Dequeue return %d\n", De_num, de_Queue(q));
			}break;			
		}
		show_Queue(q);
	}	
	

	exit(0);
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Linknode{
	int data;
	struct Linknode *next;
}Linknode;

typedef struct LinkStack{
	struct Linknode *next;
}*LiStack;

LiStack init_LiStack(){
	LiStack L = (LiStack)malloc(sizeof(LiStack));
	L->next = NULL;
	return L;	
}

int Is_empty(LiStack L){
	return L->next == NULL;
}

int stack_Push(LiStack L, int x){
	if(L==NULL) return 0;
	Linknode *n = (Linknode *)malloc(sizeof(Linknode));
	n->data = x;
	n->next = L->next;
	L->next = n;
	return 1;
}

int stack_Pop(LiStack L){
	if(L==NULL) return 0;
	if(Is_empty(L)) return 0;
	Linknode *p = L->next;
	L->next = p->next;
	free(p);
	return 1;
}

void stack_show(LiStack L){
	Linknode *p = L->next;
	printf("LinkStack:[ ");
	while(L&&p){
		printf("%d -> ",p->data);
		p = p->next;	
	}
	printf("NULL ]\n");
	return;	
}

void Free_Stack(LiStack L){
	if(L == NULL) return ;
	while(!Is_empty(L)){
		stack_Pop(L);
	}
	free(L);
	return ;
}

/* NO HEAD NODE
LiStack insert(LiStack head, int x){
	LiStack L = (LiStack)malloc(sizeof(LiStack));	
	L->data = x;
	L->next = head;
	head = L;
	return head;
}
*/
int main(){
	srand(time(0));	
	LiStack L = init_LiStack();

	for(int i = 0; i < 10; i++){
		int op = rand() % 3;
		int val = rand() % 100;
		switch(op){
			case 0:
			case 1:{
				printf("Push %d into Stack, return %d\n",val 
						,stack_Push(L, val));	
				stack_show(L);
			}break;
			case 2:{
				printf("Pop! return %d\n",stack_Pop(L));	
			}break;
		}
	}

	Free_Stack(L);	
	exit(0);
}

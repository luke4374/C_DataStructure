#include<stdio.h>
#include<stdlib.h>

typedef struct Linknode{
	int data;
	struct Linknode *next;
}Linknode,*LiStack;

LiStack init_LiStack(){
	LiStack L = (LiStack)malloc(sizeof(LiStack));
	L->next = NULL;
	return L;	
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
	if(L->next == NULL) return 0;
	Linknode *p = L->next;
	L->next = p->next;
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
	int x;
	LiStack L = init_LiStack();
	scanf("%d",&x);
	while(x!=999){
		printf("Push %d into Stack, return%d\n",x,stack_Push(L, x));	
		stack_show(L);
		scanf("%d",&x);
	}
	scanf("%d",&x);
	while(x!=999){
		printf("Pop! return%d\n",stack_Pop(L));	
		stack_show(L);
		scanf("%d",&x);
	}
	exit(0);
}

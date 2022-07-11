#include <stdio.h>
#include <stdlib.h>
#define MAX_OP 10

typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}node, *Tree;

typedef struct Queue{
	Tree T_Queue;
	int top, rear;
	int num;
}Queue,*Que;

Tree Init_Tree(){
	Tree t = (Tree)malloc(sizeof(Tree));
	t->data = 1;
	t->lchild = NULL;
	t->rchild = NULL;
	return t;	
}

Que Init_Queue(){
	Que q = (Que)malloc(sizeof(Queue));
	q->T_Queue = (Tree)malloc(sizeof(node) * 10);
	q->top = q->rear = 0;
	q->num = 0;
	return q;
}

Tree En_Queue(Que q, Tree node){
	if(node == NULL) return NULL;
	q->T_Queue	

}

int Input_Tree(Tree t, Que q, int val){
	if(t == NULL) return -1;
	node *n = (node *)malloc(sizeof(node));
	n->data = val;
	n->lchild = NULL;
	n->rchild = NULL;
	Tree root = Insert_Queue(q, t);
#if 0
	//if( t->lchild != NULL && t->rchild != NULL) Input_Tree(t->lchild, val);
	//else Input_Tree(t->rchild, val);
	if(t->lchild == NULL) t->lchild = n;
	else if(t->rchild == NULL) t->rchild = n;
	else{
		if(t->lchild->lchild == NULL) Input_Tree(t->lchild, val);
		else Input_Tree(t->rchild, val);
	}
	printf("%d lchild = %p, rchild = %p\n", t->data, t->lchild, t->rchild);
#endif
	return 1;
}

void Show_Tree(Tree t){
	if(t == NULL) return ;
	if(t->lchild != NULL) Show_Tree(t->lchild);
	printf("%d ",t->data);
	if(t->rchild != NULL) Show_Tree(t->rchild);
	return ;
}

int main(){
	Tree T = Init_Tree();
	Que q = Init_Queue();
	int val;
	scanf("%d",&val);
	while(val != 999){
		Input_Tree(T, q, val);
		scanf("%d",&val);
	}
	Show_Tree(T);
	exit(0);
}

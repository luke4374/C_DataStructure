#include <stdio.h>
#include <stdlib.h>
#define MAX_OP 10

typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}node, *Tree;

typedef struct LinkNode{
	Tree add;
	struct LinkNode *next;
}Li_Node;

typedef struct Li_Queue{
	Li_Node *front, *rear;
	int num;
}*Li_Que;

Li_Que Init_Queue(){
	//no head node
	Li_Que q = (Li_Que)malloc(sizeof(Li_Que));
	q->front = NULL;
	q->rear = NULL;	
	q->num = 0;
	return q;
}

void Free_Queue(Li_Que q){
	if(q == NULL) return ;
	while(q->front != NULL){
		free(q->front);
		q++;
	}
	free(q);
	return ;
}

void Show_Queue(Li_Que q){
	if(q == NULL) return ;
	Li_Node *n = q->front;
	while(n){
		printf("%p -> ", n->add);
		n = n->next;	
	}
	printf(" NULL\n");
	return ;
}

int En_Queue(Li_Que q, Tree node){
	if(node == NULL && q == NULL) return -1;
	Li_Node *n = (Li_Node *)malloc(sizeof(Li_Node));
	n->add = node;
	n->next = NULL;	
	if(q->front == NULL && q->rear == NULL){
		q->front = q->rear = n; 
	}
	else{
		q->rear->next = n;	
		q->rear = n;
	}
	q->num++;
	Show_Queue(q);
	return 1;
}

int Is_Empty(Li_Que q){
	return (q->front == NULL && q->rear == NULL);
}

int De_Queue(Li_Que q){
	if(q == NULL) return -1;
	if(Is_Empty(q)) return -1;
	Li_Node *n = q->front;	
	q->front = n->next;
	if(q->rear = n) q->front = q->rear = NULL;
	free(n);
	return 1;		
}

Tree Get_Child(Li_Que q){
	if(q == NULL) return NULL;
	Li_Node *n = q->front;
	printf("Left = %p, Right = %p\n",n->add->lchild, n->add->rchild);
	if(n->add->lchild == NULL) return n->add;
	if(n->add->rchild == NULL) return n->add;
	else{
		printf("De_Queue = %d\n",De_Queue(q));
		return Get_Child(q);
	}
}

Tree Init_Tree(Li_Que q){
	Tree t = (Tree)malloc(sizeof(Tree));
	t->data = 1;
	t->lchild = NULL;
	t->rchild = NULL;
	En_Queue(q, t);
	return t;	
}

int Input_Tree(Tree t, Li_Que q, int val){
	if(t == NULL) return -1;
	node *n = (node *)malloc(sizeof(node));
	n->data = val;
	n->lchild = NULL;
	n->rchild = NULL;
	Tree child = Get_Child(q);
	if(child->lchild == NULL) child->lchild = n;	
	else child->rchild = n;	
	En_Queue(q, n);
	printf("%d GetChild = %p, lchild = %p, rchild = %p\n", 
			t->data, child, t->lchild, t->rchild);
#if 0
	//if( t->lchild != NULL && t->rchild != NULL) Input_Tree(t->lchild, val);
	//else Input_Tree(t->rchild, val);
	if(t->lchild == NULL) t->lchild = n;
	else if(t->rchild == NULL) t->rchild = n;
	else{
		if(t->lchild->lchild == NULL) Input_Tree(t->lchild, val);
		else Input_Tree(t->rchild, val);
	}
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
	Li_Que q = Init_Queue();
	Tree T = Init_Tree(q);
	int val;
	scanf("%d",&val);
	while(val != 999){
		Input_Tree(T, q, val);
		scanf("%d",&val);
	}
	Show_Tree(T);
	exit(0);
}

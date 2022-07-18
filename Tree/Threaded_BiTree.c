#include <stdio.h>
#include <stdlib.h>
#define MAX_OP 10


typedef struct ThreadNode{
	int data;
	struct ThreadNode *lchild, *rchild;
	int ltag,rtag;
}ThreadNode, *Tree;
/*
typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}node, *Tree;
*/
typedef struct LinkNode{
	Tree add;
	struct LinkNode *next;
}Li_Node;

typedef struct Li_Queue{
	Li_Node *front, *rear;
	int num;
}*Li_Que;

//constant Threadnode pointer
ThreadNode *pre;

Li_Que Init_Queue(){
	//no head node
	Li_Que q = (Li_Que)malloc(sizeof(*q));
	q->front = NULL;
	q->rear = NULL;	
	q->num = 0;
	return q;
}

int Is_Empty(Li_Que q){
	return q->front == NULL && q->rear == NULL;
}

void Show_Queue(Li_Que q){
	if(q == NULL || q->front == NULL) return ;
	Li_Node *n = q->front;
	while(n){
		printf("%d -> ", n->add->data);
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
	if(Is_Empty(q)){
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

int De_Queue(Li_Que q){
	if(q == NULL) return -1;
	if(Is_Empty(q)) return -1;
	Li_Node *n = q->front;	
	q->front = n->next;
	if(q->front == q->rear){
		q->front = q->rear = NULL;
	}
	free(n);
	q->num--;
	return 1;		
}

Tree *Get_Child(Li_Que q){
	if(q == NULL) return NULL;
	Li_Node *n = q->front;
	if(n->add->lchild == NULL) return &(n->add->lchild);
	if(n->add->rchild == NULL) return &(n->add->rchild);
	else{
		printf("De_Queue = %d\n",De_Queue(q));
		return Get_Child(q);
	}
}

void Free_Queue(Li_Que q){
	if(q == NULL) return ;
	while(!Is_Empty(q)){
		De_Queue(q);
	}
	free(q);
	return ;
}

Tree Init_Tree(Li_Que q){
	Tree t = (Tree)malloc(sizeof(*t));
	t->data = 1;
	t->lchild = NULL;
	t->rchild = NULL;
	t->ltag = t->rtag = 0;
	En_Queue(q, t);
	return t;	
}

int Input_Tree(Tree t, Li_Que q, int val){
	if(t == NULL) return -1;
	ThreadNode *n = (ThreadNode *)malloc(sizeof(ThreadNode));
	n->data = val;
	n->lchild = NULL;
	n->rchild = NULL;
	//node **
	Tree *child = Get_Child(q);
	*child = n;
	En_Queue(q, *child);
	return 1;
}

int Visit_node(Tree t){
	if(t->lchild == NULL){
		//pre-Thread
		t->lchild = pre;
		t->ltag = 1;
	}		
	if(pre != NULL && pre->rchild == NULL){
		//post-Thread
		pre->rchild = t;
		pre->rtag = 1;	
	}	
	pre = t;
	return 1;
}

void In_Thread(Tree t){
	if(t == NULL) return ;
	//In-order traversal
	In_Thread(t->lchild);
	Visit_node(t);
	In_Thread(t->rchild);
	return ;
}

int Create_InThread(Tree t){
	if(t == NULL) return -1;
	pre = NULL;
	In_Thread(t);
	if(pre->rchild == NULL){
		pre->rtag = 1;
	} 
	return 1;
}

void Show_Tree(Tree t){
	if(t == NULL) return ;
	//In-order traversal
	if(t->lchild != NULL && t->ltag != 1) Show_Tree(t->lchild);
	printf("LChild(%d) = %p, T(%p) = %d RChild(%d) = %p\n",
			t->ltag, t->lchild, t, t->data, t->rtag, t->rchild);
	if(t->rchild != NULL && t->rtag != 1) Show_Tree(t->rchild);
	return ;
}

void Free_Tree(Tree t){
	if(t == NULL) return ;
	if(t->ltag != 1) Free_Tree(t->lchild);
	if(t->rtag != 1) Free_Tree(t->rchild);
	free(t);
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
	Create_InThread(T);
	Show_Tree(T);
	//FREE MEMORY
	Free_Tree(T);
	Free_Queue(q);	
	exit(0);
}

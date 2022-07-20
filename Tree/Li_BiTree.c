#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_OP 10

typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}node;

typedef struct Tree{
	struct Node *node;
	int total;
}*Tree;

typedef struct LinkNode{
	struct Node *add;
	struct LinkNode *next;
}Li_Node;

typedef struct Li_Queue{
	Li_Node *front, *rear;
	int num;
}*Li_Que;

Li_Que Init_Queue(){
	//no head node
	Li_Que q = (Li_Que)malloc(sizeof(*q));
	q->front = NULL;
	q->rear = NULL;	
	q->num = 0;
	return q;
}

int Is_Empty(Li_Que q){
	return (q->front == NULL && q->rear == NULL);
}

void Show_Queue(Li_Que q){
	if(q == NULL || q->front == NULL) return ;
	Li_Node *n = q->front;
	printf("%s(%d) F_node = %p, L_child = %p, R_child = %p\n", 
		__func__,q->num, n->add, n->add->lchild, n->add->rchild);
	while(n){
		printf("%d -> ", n->add->data);
		n = n->next;	
	}
	printf(" NULL\n");
	return ;
}

int En_Queue(Li_Que q, node *node, int show){
	if(node == NULL || q == NULL) return -1;
	Li_Node *n = (Li_Node *)malloc(sizeof(Li_Node));
	n->add = node;
	n->next = NULL;	
	q->num++;
	if(Is_Empty(q)){
		q->front = q->rear = n; 
	}
	else{
		q->rear->next = n;	
		q->rear = n;
	}
	if(show == 1) Show_Queue(q);
	return 1;
}

int De_Queue(Li_Que q){
	if(q == NULL) return -1;
	if(Is_Empty(q)) return -1;
	if(q->front == q->rear){
		Li_Node *n = q->front;	
		q->front = q->rear = NULL;
		free(n);
	}else{
		Li_Node *n = q->front;	
		q->front = n->next;
		free(n);
		q->num--;
	}
	return 1;		
}

node **Get_Child(Li_Que q){
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

Tree Init_Tree(){
	Tree t = (Tree)malloc(sizeof(*t));
	t->node = NULL;
	t->total = 0;
	return t;	
}

int Input_Tree(Tree t, Li_Que q, int val){
	if(t == NULL) return -1;
	node *n = (node *)malloc(sizeof(node));
	n->data = val;
	n->lchild = NULL;
	n->rchild = NULL;
	if(t->node == NULL){
		t->node = n;
		En_Queue(q, n, 1);
		t->total++;
	}else{
		//node **
		node **child = Get_Child(q);
		*child = n;
		En_Queue(q, *child, 1);
		t->total++;
	}
	return 1;
}

void Show_Tree(node *n){
	if(n == NULL) return ;
	//In-order traversal
	if(n->lchild != NULL) Show_Tree(n->lchild);
	printf("%d ",n->data);
	if(n->rchild != NULL) Show_Tree(n->rchild);
	return ;
}

void Visit_node(Li_Que q, Tree t){
	if(q == NULL) return;
	En_Queue(q, t->node, 0);	
	Li_Node *n = q->front, *m = n;
	while(n){
		if(n->add->lchild != NULL) En_Queue(q, n->add->lchild, 0);
		if(n->add->rchild != NULL) En_Queue(q, n->add->rchild, 0);
		n = n->next;
	}
	printf("Level_Traversal: ");
	while(m){
		printf("%d ", m->add->data);
		m = m->next;	
	}
	printf("\n");
	return;
}

void Level_Traversal(Tree t){
	if(t == NULL) return;
	Li_Que q = (Li_Que)malloc(sizeof(*q));
	q->front = q->rear = NULL;
	Visit_node(q, t);
	Free_Queue(q);
	return ;
}

void Free_TNode(node *n){
	if(n == NULL) return ;
	if(n->lchild != NULL)Free_TNode(n->lchild);
	if(n->rchild != NULL)Free_TNode(n->rchild);
	free(n);
	return ;
}

void Free_Tree(Tree t){
	if(t == NULL) return;
	Free_TNode(t->node);
	free(t);
	return ;
}

int main(int argc, char *argv[]){
	Li_Que q = Init_Queue();
	Tree T = Init_Tree();
	int val;
	scanf("%d",&val);
	while(val != 999){
		Input_Tree(T, q, val);
		scanf("%d",&val);
	}
	printf("In-order traversal: ");
	Show_Tree(T->node);
	printf("\n");
	Level_Traversal(T);
	//FREE MEMORY
	Free_Tree(T);
	Free_Queue(q);	
	exit(0);
}

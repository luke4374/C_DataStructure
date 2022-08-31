#include<time.h>
#define MAX_SIZE 10
typedef struct T_Node{
	int data;
	struct T_Node *lchild, *rchild;
}Node;

typedef struct Tree{
	Node *node;
	int total;
}Tree;

typedef struct Queue{
	struct T_Node *que[MAX_SIZE];
	int top, rear;
	int total;
}Queue;

void Show_Queue(Queue *Q){
	if(Q == NULL) return ;
	int num = Q->top;
	for(int i = Q->top; i < Q->top + Q->total; i++){
		printf("(%d)%d ", i, Q->que[num++]->data);	
		if(num == MAX_SIZE) num = num % MAX_SIZE;
	}
	printf(" total:%d\n", Q->total);
	return;
}

int En_Queue(Node *T_node, Queue *Q){
	if(T_node == NULL || Q == NULL) return 0;
	if(Q->total == MAX_SIZE) return 0;
	Q->que[Q->rear++] = T_node;
	if(Q->rear == MAX_SIZE){
		Q->rear = Q->rear % MAX_SIZE;
	}
	Q->total++;	
	return 1;
}

Node *Find_front(Queue *Q){
	if(Q == NULL || Q->total == 0) return NULL;
	Node *tnode = Q->que[Q->top];
	return tnode;
}

void De_Queue(Queue *Q){
	if(Q == NULL || Q->total == 0) return ;	
	Q->top++;
	if(Q->top == MAX_SIZE) Q->top = Q->top % MAX_SIZE;	
	Q->total--;
	return;
}

void Free_Queue(Queue *Q){
	if(Q == NULL) return ;
	free(Q);
	return ;
}

void Insert_Node(Node *root, Node *n){
	if(n == NULL) return;
	if(root->data < n->data){
		if(root->rchild == NULL) root->rchild = n;
		else Insert_Node(root->rchild, n);	
	}else{
		if(root->lchild == NULL) root->lchild = n;
		else Insert_Node(root->lchild, n);
	}	
	return;
}

Tree *Init_Tree(){
	srand(time(0));
	int x = rand() % 100;
	Tree *T = (Tree *)malloc(sizeof(Tree));
	Queue *Q = (Queue *)malloc(sizeof(Queue));
	Node *root = (Node *)malloc(sizeof(Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	T->node = root;
	T->total++;
	Q->top = Q->rear = Q->total = 0;
	En_Queue(root, Q);	
	for(int i = 1; i < MAX_SIZE; i++){
		Node *T_node = (Node *)malloc(sizeof(Node));
		T_node->data = x + ( 4 * i );  
		T_node->lchild = T_node->rchild = NULL;
		Node *P_node = Find_front(Q);
		if(P_node->lchild == NULL) P_node->lchild = T_node;
		else{
			P_node->rchild = T_node;
			De_Queue(Q);
		}
		En_Queue(T_node, Q);	
		T->total++;
	}
	Free_Queue(Q);
	return T;
}

void Show_Tree(Node *n){
	if(n == NULL) return;
	if(n->lchild != NULL) Show_Tree(n->lchild);
	printf("%d ",n->data);
	if(n->rchild != NULL) Show_Tree(n->rchild);
	return ;
}

void Free_Node(Node *n){
	if(n == NULL) return;
	if(n->lchild != NULL) Free_Node(n->lchild);
	if(n->rchild != NULL) Free_Node(n->rchild);
	free(n);
	return ;
}

void Free_Tree(Tree *T){
	if(T == NULL) return ;
	Free_Node(T->node);
	free(T);
	return;
}


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

void Free_Node(Node *n);

void Insert_Node(Node *root, Node *n){
	if(n == NULL) return;
	if(root->data == n->data){
		Free_Node(n);
		return;
	}
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
	Tree *T = (Tree *)malloc(sizeof(Tree));
	Node *root = (Node *)malloc(sizeof(Node));
	root->data = rand() % 100;
	root->lchild = root->rchild = NULL;
	T->node = root;
	T->total++;
	printf("root(%d):%p\n", T->node->data, T->node);
	for(int i = 1; i < MAX_SIZE; i++){
		Node *T_node = (Node *)malloc(sizeof(Node));
		T_node->data = rand() % 100 + (rand() % 20);  
		T_node->lchild = T_node->rchild = NULL;
		Insert_Node(T->node, T_node);
		T->total++;
	}
	return T;
}

void Show_Tree(Node *n){
	if(n == NULL) return;
	if(n->lchild != NULL) Show_Tree(n->lchild);
	//printf("%d(%p) left:%p right:%p\n",n->data, n, n->lchild, n->rchild);
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


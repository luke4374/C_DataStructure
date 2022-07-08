#include <stdio.h>
#include <stdlib.h>
#define MAX_OP 10

typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}node, *Tree;

Tree Init_Tree(){
	Tree t = (Tree)malloc(sizeof(Tree));
	t->data = 1;
	t->lchild = NULL;
	t->rchild = NULL;
	return t;	
}

int Input_Tree(Tree t, int val){
	if(t == NULL) return -1;
	node *n = (node *)malloc(sizeof(node));
	n->data = val;
	n->lchild = NULL;
	n->rchild = NULL;
	if(t->lchild == NULL) t->lchild = n;
	t->rchild = n;
	if( t->lchild != NULL && t->rchild != NULL) Input_Tree(t->lchild, val);
	Input_Tree(t->rchild, val);
	return 1;
}

int main(){
	node *T = Init_Tree();
	exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#define MAX_OP 10

typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}node;

node *Init_Tree(node *n){
	if(n == NULL) return NULL;
	int i = 0;
	node *p = n;
	printf("n = %p, p = %p\n",n, p);
	while(i != 10){
		p->data = i++; 	
		p++;
	}
	printf("n = %p, p = %p\n",n, p);
	return n;
}


int main(){
	node Tree[20];
	node *T = Init_Tree(Tree);
	for(int i = 0; i < 10; i++,T++){
		printf("%d\n",T->data);
	}
	exit(0);
}

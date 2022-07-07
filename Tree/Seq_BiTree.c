#include <stdio.h>
#include <stdlib.h>
#define MAX_OP 10

typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}node;

node *Init_Tree(node *n){
	if(n == NULL) return NULL;
	int i = 1;
	node *p = n;
	p+=1;
	while(i != 11){
		p->data = i++; 	
		p++;
	}
	return &n[0];
}


int main(){
	node Tree[20];
	node *T = Init_Tree(Tree);
	int p = 3;
	printf("Tree[%d] = %d, left_child[%d] = %d, right_child[%d] = %d\n",p, 
		T[p].data, 2*p, T[2*p].data, 2*p+1, T[2*p+1].data);   
	for(int i = 0; i <= 10; i++){
		printf("%d %p\n",T[i].data, T[i]);
	}
	exit(0);
}

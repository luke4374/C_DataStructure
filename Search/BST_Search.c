#include<stdio.h>
#include<stdlib.h>
#include"Binary_Tree.h"

Node *BST(Node *N, int key){
	Node *node = N;
	while(node != NULL && node->data != key){	
		if(key < node->data){
			node = node->lchild;
		}else node = node->rchild;	
	}
	return node;
}



int main(){
	int key;
	Tree *T = Init_Tree();
	Show_Tree(T->node);
	printf("\n");
	scanf("%d", &key);
	Node *n = BST(T->node, key);
	if(n == NULL){
		printf("No Such Number\n");
	}else{
		printf("Number %d Finded\n", n->data);	
	}
	Free_Tree(T);
	exit(0);
}


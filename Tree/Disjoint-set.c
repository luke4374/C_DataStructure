#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10

typedef struct PTnode{
	char data;
	int parent;
}PTnode;

typedef struct{
	PTnode nodes[MAX_SIZE];
	int n;
}Set; 
/*
	  A		  E		   G
	 / \	  |		 / | \
	B   C	  F		H  I  J
   /
  D
*/
void Show_Set(Set *S);
int parent_setting[] = { -4, 0, 0, 1, -2, 4, -4, 6, 6, 6 };

Set *Init_Tree(){
	Set *S = (Set *)malloc(sizeof(Set));
	for(int i = 0; i < MAX_SIZE; i++){
		S->nodes[i].data = 65 + i;
		S->nodes[i].parent = parent_setting[i];	
		S->n++;
	}
	Show_Set(S);
	return S;
}

int Find_root(Set *s, int x){
	if(s == NULL) return -1;
	int ind = x;
	while(s->nodes[ind].parent >= 0){
		ind = s->nodes[ind].parent;	
	}
	return ind;
}

int union_Tree(Set *s, int r1, int r2){
	if(r1 == r2) return -1;
	int root1 = r1, root2 = r2;
	printf("union %d & %d :",r1, r2);
	if(r1 != -1 || r2 != -1){
		root1 = Find_root(s, r1);
		root2 = Find_root(s, r2);
	}
	//Tree with less nodes merge into large tree
	if(s->nodes[root1].parent < s->nodes[root2].parent){
		s->nodes[root1].parent += s->nodes[root2].parent;
		s->nodes[root2].parent = root1;	
	}else{
		s->nodes[root2].parent += s->nodes[root1].parent;
		s->nodes[root1].parent = root2;	
	}
	printf("root(%d).parent = %d, root(%d).parent = %d\n",root1, s->nodes[root1].parent, root2, s->nodes[root2].parent);
	return 1;
}

void Show_Set(Set *S){
	if(S == NULL) return ;	
	for(int i = 0; i < MAX_SIZE; i++){
		printf("(%d)%c %d ", i, S->nodes[i].data, S->nodes[i].parent);
	}
	printf("\n");
	return ;
}

void Free_Tree(Set *S){
	if(S == NULL) return ;
	free(S);
}

int main(){
	int n = 7,x;
	Set *S = Init_Tree();
	x = Find_root(S, n);
	printf("%c's Root is %c\n",S->nodes[n].data, 
			S->nodes[x].data);
	union_Tree(S, 2, 6);
	Show_Set(S);
	Free_Tree(S);
	return 0;
}


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define OP_MAX 10
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode;

typedef struct LinkList{
	LNode head;
	int length;
}LinkList;

LinkList * init_LinkList(){
	LinkList * L = (LinkList *)malloc(sizeof(LinkList));	
	L->head.next = NULL;//虚拟头节点，往后插入时只须移动index步
	L->length = 0;
	return L;

}
LNode * init_Node(int val){
	LNode *n = (LNode *)malloc(sizeof(LNode));
	n->data = val;
	n->next = NULL;
	return n;
}

int insert(LinkList *L, int ind, int val){
	if(L == NULL) return 0;
	if(ind < 0 || ind > L->length) return 0;
	LNode *p = &(L->head);
	while(ind--){
		p = p->next;
	}
	LNode *n = init_Node(val);	
	n->next = p->next;
	p->next = n;
	L->length++;
	return 1;

}

int clear_Node(LNode *LN){
	if(LN == NULL) return 0;
	free(LN);
	return 1;
}

int clear_LinkList(LinkList *L){
	LNode *p = L->head.next,*q;
	if( L == NULL ) return 0;
	while(p!=NULL){
		q = p->next;
		clear_Node(p);
		p = q;	
	}
	free(L);
	return 1;
}


int delete(LinkList *L, int ind){
	if(L == NULL) return 0;
	if(ind < 0 || ind >= L->length) return 0;
	LNode *p = &(L->head),*q;
	while(ind--){
		p = p->next;	
	}
	q = p->next->next;
	clear_Node(p->next);
	p->next = q;
	L->length--;
	return 1;	
}
void show_list(LinkList *l){
	//printf("%d\n",__LINE__);
	if(l == NULL) return;
	int pos = l->length;
	printf("LinkList(%d):[ ",l->length);
	LNode *p = &(l->head);
/*	for(LNode *p = l->head; p; p = p->next){
		printf("%d->",p->data);
	}
	printf("NULL\n");
*/
	while(pos--){
		printf("%d -> ",p->next->data);
		p = p->next;
	}
	printf("NULL ]\n");
	return;
}
int main(){
	srand(time(0));
	LinkList *L = init_LinkList();
	for(int i = 0; i < OP_MAX; i++){
	//	printf("%d\n",__LINE__);
		int op = rand() % 3;
		int ind = rand() % (L->length + 1);//范围0～length 否则会有非法值
		int val = rand() % 100;
	//	printf("%d %d %d\n",op, ind, __LINE__);
		switch(op){
			case 0:	
			case 1:{	
				printf("insert %d into %d = %d\n",
				  		val, ind, insert(L, ind, val));
			}break;
			case 2:{
				printf("delete at %d = %d\n", 
						ind, delete(L, ind));
			}break;
		}	
	//printf("%d\n",__LINE__);
	show_list(L);
	}
	clear_LinkList(L);
	exit(0);

}

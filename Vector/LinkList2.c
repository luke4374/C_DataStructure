#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int data;
	struct ListNode *prior,*next;
}LNode, *LinkList;

LinkList Head_insert(LinkList L){
	LNode *n;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x!=999){
		n = (LNode *)malloc(sizeof(LNode));
		n->data = x;
		n->prior = L;
		n->next = L->next;
		L->next = n;
		scanf("%d",&x);
	}
	return L;
}

void show_List(LinkList L){
	if(L == NULL) return ;
	LNode *p = L->next;
	for(;p; p = p->next){
		printf("%d -> ",p->data);
	}	
	printf("NULL\n");
	return ;
}

int Free_list(LinkList L){
	if(L == NULL) return 0;
	LNode *p = L->next,*q;
	for(p; p->next != NULL; ){
		q = p->next;
		free(p);
		p = q;
	}
	return 1;
}

LinkList Get_ele(LinkList L, int i){
	LNode *p = L->next;
	int x;
	for(x = 1; x < i; x++){
		if(p->next == NULL) return NULL;
		p=p->next;
	}
	return p;
}

int main(){
	int x;
	//LinkList l = ListNode * l
	LinkList l = Head_insert(l);
	show_List(l);
	scanf("%d",&x);
	LNode* n = Get_ele(l, x-1);
	printf("add = %p, value = %d\n",n ,n->data);
	Free_list(l);	
	return 0;
}

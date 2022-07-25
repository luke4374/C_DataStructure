#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int data;
	struct ListNode *prior,*next;
}LNode, *LinkList;

LinkList Head_insert(){
	LNode *n;
	int x;
	LinkList L = (LinkList)malloc(sizeof(LNode));
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
	while(p){
		printf("%d -> ",p->data);
		p = p->next;
	}	
	printf("NULL\n");
	return ;
}

int Free_list(LinkList L){
	if(L == NULL) return 0;
	LNode *p = L->next;
	while(p != NULL){
		L->next = p->next;
		free(p);
		p = L->next;
	}
	free(L);
	return 1;
}

int Get_ele(LinkList L, int i){
	LNode *p = L->next;
	int x;
	for(x = 0; x < i; x++){
		if(p->next == NULL) return -1;
		p = p->next;
	}
	printf("add = %p, value = %d\n",p ,p->data);
	return 1;
}

int main(){
	int x;
	//LinkList l = ListNode * l
	LinkList l = Head_insert();
	show_List(l);
	scanf("%d",&x);
	Get_ele(l, x-1);
	Free_list(l);	
	return 0;
}

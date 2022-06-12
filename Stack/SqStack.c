#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 10
typedef struct sqstack{
	int data[MAXLENGTH];
	int top;
}sqstack;

void init_stack(sqstack *s){
	s->top = -1;
}

int push(sqstack *s, int x){
	if(s->top == MAXLENGTH -1) return 0;
	s->data[++s->top] = x;
	return 1;
}

int pop(sqstack *s){
	int x;
	if(s->top == -1) return -1;
	x = s->data[s->top--];
	return x;
}

void show_stack(sqstack *s){
	if(s->top == -1) return;
	printf("sqstack(%d):\n",s->top);
	for(int i = s->top; i > -1; i--){
		printf("%d\n", s->data[i]);
	}
	return ;	
}

int free_stack(sqstack *s){
	if(s == NULL) return 0;
	free(s->data);

	return 1;
}

int main(){
	int x;
	sqstack *s = (sqstack *)malloc(sizeof(sqstack));
	init_stack(s);

	scanf("%d",&x);
	
	while(x != 999){
		printf("push %d into stack(%d) return %d\n",x, s->top, push(s, x));
		scanf("%d",&x);
	}
	show_stack(s);

	scanf("%d",&x);

	while(x != 999){
		
		printf("pop from stack(%d) %d pop out\n",s->top,	pop(s));
		show_stack(s);
		scanf("%d",&x);
	}	
	free_stack(s);
	return 0;
}

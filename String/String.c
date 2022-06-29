#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 20

typedef struct {
	char *data;
	int length;
}String;

String *init_String(int n){
	String *s = (String *)malloc(sizeof(String));
	s->data = (char *)malloc(sizeof(char) * n);
	s->length = 0;
	return s;
}

String * Input_Str(String *s){
	if(s == NULL) return NULL;
	fgets(s->data, MAX_LEN, stdin);
	//fgets will count \n as a charactor, gets won't
	//坑：String *p = s; p->data++ will cause s->data++
	char *p = s->data;
	while(*p != '\0'){
		//printf("1: p->data= %p, s->data = %p\n",&(p->data), &(s->data));
	//	fputs(p->data, stdout);	
		if(*p != '\n'){
			s->length++;
		}
		p++;
	}
	printf("write in: ");
	fputs(s->data, stdout);	
	return s;	
}

String *SubString(String *s, int pos, int len){
	if(s == NULL) return NULL;
	if(pos + len > s->length) return NULL;
	String *p = init_String(MAX_LEN);	
	printf("s->data[2] = %s\n",&(s->data[2]));
	for(int i = pos; i < (pos + len); i++){
		p->data[i - pos] = s->data[i];
		//printf("p->data = %s, s->data = %s\n",&(p->data[i - pos]), &(s->data[i]));
	}
	printf("p->data = %s\n",p->data);
	p->length = len;
	return p;	

}

int Show_Str(String *s){
	if(s == NULL) return -1;
	printf("length = %d\n",s->length);
	fputs(s->data, stdout);	
	return 1;
}

void Free_Str(String *s){
	if(s == NULL) return ;
	free(s->data);
	free(s);
	return ;
}

int Compare_Str(String *s, String *t){
	for(int i = 0; i < s->length && i < t->length; i++){
		if(s->data[i] != t->data[i])
			return s->data[i] - t->data[i];
	}
	return s->length - t->length;	

}

int Index(String *s, String *t){
	int i;
	while(i <= (s->length + t->length + 1)){

	}

}

int main(){
	String *s = init_String(MAX_LEN);
	printf("origin s = %p, &s->data = %p\n", s, &(s->data));
	printf("show array return %d\n",Show_Str(Input_Str(s))); 
	printf("show array return %d\n",Show_Str(SubString(s, 2, 3))); 
	Free_Str(s);
	//Compare String
	printf("-----------Compare String----------\nPlease input string s\n");
	String *str = init_String(MAX_LEN);
	str = Input_Str(str);
	printf("Please input string t\n");
	String *t = init_String(MAX_LEN);
	t = Input_Str(t);	
	printf("compare S with T return %d\n",Compare_Str(str, t));
	return 0;
}

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
	//printf("%p\n",s->data);
	//坑：String *p = s; p++ 连带着 s++
	char *p = s->data;
	printf("1:&s = %p, s->data = %p, &s->data = %p\n", s, s->data, &(s->data));
	while(*p != '\0'){
		//printf("*s = %d, s = %s\n",*(s->data),s->data);
	//	fputs(p->data, stdout);	
		if(*p != '\n'){
			s->length++;
		}
		p++;
	}
	
	//printf("%d\n",s->length);
	printf("2:&s = %p, s->data = %p p->data = %p &s->data = %p\n", s, s->data, p, &(s->data));
	fputs(s->data, stdout);	
	return s;	
}

String *SubString(String *s, int pos, int len){
	if(s == NULL) return NULL;
	if(pos + len > s->length) return NULL;
	String *p = init_String(MAX_LEN);	
	for(int i = len; i < s->length; i++){
		p->data[i - pos] = s->data[len];
	} 
	return p;	

}

void Show_Str(String *s){
	printf("length = %d\n",s->length);
	if(s == NULL) return ;
	fputs(s->data, stdout);	
	return ;
}

int main(){
	String *s = init_String(MAX_LEN);
	printf("origin s = %p, &s->data = %p\n", s, &(s->data));
	s = Input_Str(s);
	Show_Str(s);
	String *p = SubString(s, 2, 3); 
	Show_Str(p);
	return 0;
}

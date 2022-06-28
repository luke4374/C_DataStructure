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

int Input_Str(String *s){
	if(s == NULL) return 0;
	fgets(s->data, MAX_LEN, stdin);
	//fgets will count \n as a charactor, gets won't
	//printf("%p\n",s->data);
	String *p = s;
	while(*(p->data) != '\0'){
		//printf("*s = %d, s = %s\n",*(s->data),s->data);
		fputs(p->data, stdout);	
		if(*(p->data) != '\n'){
			s->length++;
		}
		p->data++;
	}
	//printf("%d\n",s->length);
	return 1;	
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
	printf("%p\n",s);
	if(s == NULL) return ;
	fputs(s->data, stdout);	
	return ;
}

int main(){
	String *s = init_String(MAX_LEN);
	Input_Str(s);
	Show_Str(s);
	String *p = SubString(s, 2, 3); 
	Show_Str(p);
	return 0;
}

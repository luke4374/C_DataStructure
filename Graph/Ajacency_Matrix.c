#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_Vex 10

typedef struct{
	char Vertex[MAX_Vex];
//	int Edge[MAX_Vex][MAX_Vex];
	int Edge[MAX_Vex*(MAX_Vex -1) / 2];
	int Vnum,Enum;
}*MGraph;

MGraph Init_Graph(int Vertex_num){
	MGraph graph = (MGraph)malloc(sizeof(*graph));
	graph->Vnum = Vertex_num;
	graph->Enum = 0;
	for(int i = 0; i < Vertex_num; i++){
		graph->Vertex[i] = 65 + i; 	
/*
		for(int j = 0; j < Vertex_num; j++){
			graph->Edge[i][j] = 0;
		}	
*/
	}
	memset(graph->Edge, 0,sizeof(graph->Edge));
	return graph;
}

void Show_Matrix(MGraph G, int Vertex_num){
	if(G == NULL) return;
	int x = 0;
	while(x < Vertex_num){
		if(x == 0) printf("G->V: ");
		printf("%c ",G->Vertex[x]);
		if(x == Vertex_num - 1) printf("\n");
		x++;
	}
	for(int i = 0; i < Vertex_num; i++){
		for(int j = 0; j < Vertex_num; j++){
			if(i >= j){
				//Starts at 0 
				printf("(%2d)%d ", i * (i + 1) / 2 + j, 
								G->Edge[i * (i + 1) / 2 + j]);
			}else if(i < j){	
				printf("(%2d)%d ", j * (j + 1) / 2 + i, 
								G->Edge[j * (j + 1) / 2 + i]);
			}
		}
		printf("\n");
	}

	return;
}

void Insert_Edge(MGraph G){
	if(G == NULL) return;
	int i,j,x;
	printf("Input Vertex I & J\n");
	scanf("%d %d",&i, &j);
	if(i >= j){
		x = i * (i - 1) / 2 + j - 1; 
	}else{
		x = j * (j - 1) / 2 + i - 1;
	}
	G->Edge[x] = 1;
	G->Enum++;
	printf("Edge(%d):[ ",G->Enum);
	for(int m = 0; m < 10; m++){
		printf("%d ",G->Edge[m]);
	}
	printf("]\n");
	return ;	
}

void Free_Graph(MGraph G){
	if(G == NULL) return ;
	free(G);
	return ;
}

int main(){
	int Vertex_num = 5;
	MGraph G = Init_Graph(Vertex_num);
	Show_Matrix(G, Vertex_num);
	Insert_Edge(G);
	Show_Matrix(G, Vertex_num);
	Free_Graph(G);
	exit(0);
}

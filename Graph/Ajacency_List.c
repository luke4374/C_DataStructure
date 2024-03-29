#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 10 

//Edge Node
typedef struct Edge_Node{
	int Vex_num;//point to which Vertex
	struct Edge_Node *next; 
}Edge_Node;

//Ajacency List
typedef struct Adj_Node{
	char Vertex;
	struct Edge_Node *first;	
}Adj_List[MAX_SIZE];

//Ajacency List Graph
typedef struct {
	int Vex_num, Edge_num;
	Adj_List Graph;
}ALGraph;

ALGraph *Init_Graph(int total_vex){
	ALGraph *G = (ALGraph *)malloc(sizeof(ALGraph));
	G->Vex_num = total_vex; 
	G->Edge_num = 0;
	for(int i = 0; i < total_vex; i++){
		G->Graph[i].Vertex = 65 + i;
		G->Graph[i].first = NULL;
	} 
	return G;
}

void Show_Graph(ALGraph *G){
	if(G == NULL) return;
	int num = G->Vex_num;
	for(int i = 0; i < num; i++){
		Edge_Node *E = G->Graph[i].first;
		printf("[ %c(%d) ]:",G->Graph[i].Vertex, i);
		while(E != NULL){
				printf(" -> %d", E->Vex_num); 
				E = E->next;
		}
		printf(" -> NULL\n");	
	}
	return;
}

int Insert_Edge(ALGraph *G, int out, int in){
	if(G == NULL) return -1;
	if(out == in) return -1;
	Edge_Node *e = (Edge_Node *)malloc(sizeof(Edge_Node));
	e->Vex_num = in;
	e->next = G->Graph[out].first;
	G->Graph[out].first = e;
	return 1;	
}

void Free_Graph(ALGraph *G){
	if(G == NULL) return ;
	for(int i = 0; i < G->Vex_num; i++){
		Edge_Node *first = G->Graph[i].first;
		while(first != NULL){	
			G->Graph[i].first = first->next;	
			free(first);
			first = G->Graph[i].first;
		}
	}
	free(G);
	return ;
}

int main(){
	srand(time(0));
	ALGraph *G = Init_Graph(MAX_SIZE);
	for(int i = 0; i < MAX_SIZE; i++){
		int out = rand() % 10;
		int in = rand() % 10;
		printf("Input Edge %d -> %d, return %d\n",
				out, in, Insert_Edge(G, out, in));	
	}
	Show_Graph(G);
	Free_Graph(G);
	exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a structure for edge
struct Edge{
    int src,dest;
};
struct Graph{
    int V,E;
    struct Edge *edge;
};
struct Graph *createGraph(int V,int E){
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
    graph->V =V;
    graph->E =E;
    graph->edge = (struct Edge *)malloc(graph->E *sizeof(struct Edge));
    return graph;


}
int find_parents(int parent[],int i){
    if(parent[i]==-1){
        return i;
    }
    return find_parents(parent,parent[i]);
}
void MakeUnion(int parent[],int x,int y){
    int x_set = find_parents(parent,x);
    int y_set = find_parents(parent,y);
    parent[x_set]=y_set;
}
int isCycle(struct Graph *graph){
    int *parent = (int*) malloc( graph->V * sizeof(int) );
    memset(parent,-1,sizeof(int)*graph->V);
    for(int i=0;i<graph->E;i++){
        int x =find_parents(parent,graph->edge[i].src);
        int y =find_parents(parent,graph->edge[i].dest);
        if(x==y){
            return 1;
        }
        MakeUnion(parent,x,y);
    }
    return 0;
}

int main(){
    int V=4,E=4;
    struct Graph *graph = createGraph(V,E);
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
 
    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
 
    // add edge 0-2
    graph->edge[2].src = 3;
    graph->edge[2].dest = 2;
    graph->edge[3].src =3;
    graph->edge[3].dest=0;
    
 
    if (isCycle(graph))
        printf( "graph contains cycle" );
    else
        printf( "graph doesn't contain cycle" );
     
    return 0;

    




}
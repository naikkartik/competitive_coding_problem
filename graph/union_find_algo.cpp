#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>>graph;
    int V,E;
public:
    Graph(int v,int e){
        V =v;
        E =e;
    }

    void addEdge(int u,int v){
        graph[u].push_back(v);
    }
    //find parents 
    int find_parent(int parent[],int node){
        if(parent[node]==-1) return node;
        return find_parent(parent,parent[node]);
    }
    void makeUnion(int parent[],int x,int y){
        int x_set =find_parent(parent,x);
        int y_set =find_parent(parent,y);
        parent[y_set]=x_set;
    }
    int isCycle(){
        int parent[V];
        for(int i=0;i<V;i++){
            parent[i]=-1;
        }
        for(auto it:graph){
            int x_ =it.first;
            int x =find_parent(parent,x_);
            for(auto node:it.second){
                int y = find_parent(parent,node);
                if(x==y){
                    return 1;
                }
                makeUnion(parent,x,y);
            }
        }
        return 0;
    }
    
};

int main(){
    int V=4;
    int E=3;
    Graph g(V,E);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    
    cout<<g.isCycle();
}
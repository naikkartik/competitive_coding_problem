#include <bits/stdc++.h>
using namespace std; 

template <typename T>
class Graph{
    map<T,list<T>>graph;
public:
    //constructor 
    Graph(){}

    void addEdge(T u,T v,bool bidir=true){
        graph[u].push_back(v);
        if(bidir){
            graph[v].push_back(u);
        }
    }
    void dfsHelper(T src,map<T,bool>&visited){
        visited[src] =true;
        for(auto node:graph[src]){
            if(!visited[node]){
                dfsHelper(node,visited);
            }
        }
    }
    void dfs(T src){
        map<T,bool>visited;
        int components =1;
        dfsHelper(src,visited);
        for(auto it:graph){
            T node =it.first;
            if(!visited[node]){
                dfsHelper(node,visited);
                components++;
            }
        }
        cout<<"The number of components of "<<components<<endl;
    }
};

int main(){
    Graph <string>g;
    g.addEdge("Amritsar","Mumbai");
    g.addEdge("Mumbai","Delhi");
    g.addEdge("Delhi","Rayagada");
    g.addEdge("Hubli","Kolkata");
    g.addEdge("Andaman","Nicobor");
    g.dfs("Amritsar");
}
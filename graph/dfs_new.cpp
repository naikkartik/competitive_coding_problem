#include <bits/stdc++.h>
using namespace std; 

class Graph{
    map<int,list<int>>graph;
public:
    //constructor 
    Graph(){}
    void addEdge(int u,int v,bool bidir=true){
        graph[u].push_back(v);
        if(bidir){
            graph[v].push_back(u);
        }

    }
    void dfsHelper(int node,map<int,bool>&visited){
        visited[node] =true;
        cout<<node<<" ,";
        for(auto neighbor:graph[node]){
            if(!visited[neighbor]){
                dfsHelper(neighbor,visited);
            }
        }
    }
    void dfs(int src){
        map<int,bool>visited;
        dfsHelper(src,visited);
    }
};

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.dfs(0);
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
    map<T,list<T>>Adjlist;
public:
    Graph(){}

    void addEdge(int u,int v,bool bidir=true){
        Adjlist[u].push_back(v);
        if(bidir){
            Adjlist[v].push_back(u);
        }
    }
    void print(){
        for(auto it:Adjlist){
            cout<<it.first<<"->";
            for(auto node:it.second){
                cout<<node<<"->";
            }
            cout<<endl;
        }
    }
    void dfsHelper(T node,map<T,bool>&visited){
        visited[node]=true;
        cout<<node<<" ";
        for(auto neighbor:Adjlist[node]){
            if(!visited[neighbor]){
                dfsHelper(neighbor,visited);
            }
        }
    }
    void dfs(T src){
        map<T,bool>visited;
        dfsHelper(src,visited);
    }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.dfs(0);
    return 0;
}
#include <bits/stdc++.h>
using namespace std; 

class Graph{
    map<int,list<int>>graph;
public:
    void addEdge(int u,int v,bool bidir=true){
        graph[u].push_back(v);
        if(bidir){
            graph[v].push_back(u);
        }
    }
    void shorest_path(int src){
        queue<int>q;
        map<int,int>dist;
        map<int,int>parent;
        for(auto node:graph){
            dist[node.first] =INT_MAX;
        }
        q.push(src);
        parent[src] =src;
        dist[src] =0;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            for(int neighbor:graph[node]){
                if(dist[neighbor]==INT_MAX){
                    dist[neighbor] =dist[node]+1;
                    parent[neighbor] =node;
                    q.push(neighbor);
                }
            }
        }
        for(auto node:graph){
            cout<<src<<" "<<dist[node.first]<<endl;
        }
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
    g.shorest_path(0);
}
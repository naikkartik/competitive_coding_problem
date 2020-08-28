#include <bits/stdc++.h>
using namespace std; 

class Graph{
    map<int,list<int>>graph;
public:
    Graph(){}

    void addEdge(int u,int v,bool bidir=true){
        graph[u].push_back(v);
        if(bidir){
            graph[v].push_back(u);
        }
    }
    void bfs(int src){
        //declare a queue
        queue<int>q;
        map<int,int>parent;
        map<int,int>dist;
        q.push(src);
        //initialize all distance to INT_MAX;
        for(auto node:graph){
            dist[node.first] =INT_MAX;
        }
        dist[src] =0;
        parent[src] =src;
        while(!q.empty()){
            int front =q.front();
            q.pop();
            cout<<front<<" ";
            for(int neighbor:graph[front]){
                //check if they are visited or not 
                if(dist[neighbor]==INT_MAX){
                    dist[neighbor] =1+dist[front];
                    parent[neighbor] =front;
                    q.push(neighbor);
                }
            }
        }
        cout<<endl;
        for(auto node:graph){
            cout<<dist[node.first]<<endl;
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
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.bfs(0);
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//define a class for graph 
class Graph{
    map<int ,list<int>>graph;
public:
    Graph(){

    }
    void addEdge(int u,int v){
        //as the qustions say a undirectinal graph
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void bfs(int src,int n){
        queue<int>q;
        map<int,int>distance;
        q.push(src);
        for(auto it:graph){
            int node = it.first;
            distance[node] = -1;
        }
        distance[src] =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto neighbor:graph[node]){
                if(distance[neighbor]==-1){
                    q.push(neighbor);
                    distance[neighbor] =distance[node]+6;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(distance.find(i)==distance.end()){
                cout<<-1<<" ";
            }
            else{
                if(i!=src){
                    cout<<distance[i]<<" ";
                }
            }
        }
        cout<<endl;
        
    }
};
int main(){
    int q;
    cin>>q;
    while(q--){
        int m,n;
        cin>>n>>m;
        int u,v;
        Graph g;
        while(m--){
            cin>>u>>v;
            g.addEdge(u,v);
        }
        int src;
        cin>>src;
        g.bfs(src,n);
    }
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V =v;
        //do dynamic memory allocation 
        l = new list<int>[V];
    }
    void addEdge(int u,int v,bool bidir =true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    bool isBipartite(int s){
        queue<int>q;
        q.push(s);
        int *color = new int[V];
        //set all the color to -1 
        for(int i=0;i<V;i++){
            color[i] =-1;
        }
        color[s] =0;
        
        while(!q.empty()){
            int front =q.front();
            q.pop();
            //look at it neighbors 
            for(auto node:l[front]){
                if(color[node]==-1){
                    color[node] = 1-color[front];
                    q.push(node);
                }
                else if(color[node]==color[front]){
                    return false;
                }
            }

        }
        return true;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(2,0);
    g.addEdge(1,3);
    g.addEdge(2,3);
    
    
    if(g.isBipartite(0)){
        cout<<"Yes it is";
    }
    else{
        cout<<"No it is not";
    }
}

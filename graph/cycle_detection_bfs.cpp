#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph{
    map<T,list<T>>adjList;
public:
    Graph(){}

    void addEdge(int u,int v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
        
    }
    bool bfsIscycle(T src){
        //make a array of visited
        map<T,bool>visited;
        map<T,T>parent;
        visited[src]=true;
        parent[src]=src;
        queue<T>q;
        q.push(src);
        while(!q.empty()){
            T node =q.front();
            q.pop();
            for(T neighbor:adjList[node]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]=true;
                    parent[neighbor]=node;
                }
                if(visited[neighbor] and parent[node]!=neighbor){
                    return true; //cycle exists
                }
            }
        }
        return false;
    }
    //dfs to cycle detection 
    bool helper_dfs(T node,map<T,bool>&visited,T parent){
        visited[node]=true;
        for(auto neighbor:adjList[node]){
           if(!visited[neighbor]){
                bool ans = helper_dfs(neighbor,visited,T node);
                if(ans) return true;
           }
           else if(neighbor!=parent){
               return true;
           }
        }
        return false;

    }
    bool cycle_detection_dfs(){
        map<T,bool>visited;
        for(auto it:adjList){
            T node =it.first;
            T parent = node;
            if(!visited[node]){
                bool ans = helper_dfs(node,visited);
                if(ans) return true;
            }
        }
        return false;
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
    cout<<g.bfsIscycle(0);
    return 0;
}

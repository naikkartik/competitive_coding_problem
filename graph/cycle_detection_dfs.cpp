#include <bits/stdc++.h>
using namespace std; 

class Graph{
    map<int,list<int>>adjList;
public:
    Graph(){

    }
    void addEdge(int u,int v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    bool dfsHelper(int node,map<int,bool>&visited,int parent){
        visited[parent];
        for(int neighbor:adjList[node]){
            if(visited[neighbor] and parent!=neighbor){
                return true;
            }
            else if(!visited[neighbor]){
                bool ans =dfsHelper(neighbor,visited,node);
                if(ans){
                    return true;
                }
            }
        }
    }
    bool cycle_detection_dfs(){
        map<int,bool>visited;
        for(auto it:graph){
            int node =it.first;
            int parent = parent;
            if(!visited[node]){
                bool ans = dfsHelper(node,visited,parent);
                if(ans){
                    return true;
                }
            }
        }
    }

};
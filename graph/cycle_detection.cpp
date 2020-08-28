#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph(){

    }
    void addEdge(T u, T v,bool dir=true){
        adjList[u].push_back(v);
        if(dir){
            adjList[v].push_back(u);
        }
    }
    bool bfs_cycle_detection(T src){
        queue <T> q;
        map<T,int>visited;
        map<T,T>parent;
        //store the distance to INT_MAX initially
        q.push(src);
        visited[src] =true;
        parent[src] =src;
        while(q.empty()!=true){
            T node = q.front();
            q.pop();
            for(auto neighbor:adjList[node]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    parent[neighbor] = node;
                }
                if(visited[neighbor] and neighbor==parent[node]){
                    return true;
                }
            }
        }
        return false;
        
    }
    bool cycle_dfsHelper(T node,map<T,bool>&visited,T parent){
        visited[node] =true;
        for(auto neighbor:adjList[node]){
            if(!visited[neighbor]){
                bool ans = cycle_dfsHelper(neighbor,visited,node);
                if(ans) return true;
            }
            else if(neighbor!=parent){
                return true;
            }
        }
        return false;
    }
    bool cycle_dection_dfs(){
        map<T,bool>visited;
        
        for(auto it:adjList){
            T node =it.first;
            T parent = node;
            if(!visited[node]){
                bool ans =cycle_dfsHelper(node,visited,parent);
                if(ans) return true;
            }
        }
        return false;
    }
};
int main(){
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,4);
    
    if(g.cycle_dection_dfs()){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is not present"<<endl;
    }
}


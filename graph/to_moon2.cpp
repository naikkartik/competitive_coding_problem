#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>>graph;
    int n;
public:
    Graph(int v){
        n =v;
    }
    void addEdge(int u,int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    void dfs_Helper(int node,map<int,bool>&visited,int &country_size){
        visited[node] =true;
        country_size++;
        for(auto neighbor:graph[node]){
            if(!visited[neighbor]){
                dfs_Helper(neighbor,visited,country_size);
            }
        }
    }
    void dfs_Moon(){
        //make a visited map 
        map<int,bool>visited;
        int total_count = n*(n-1)/2;
        for(auto i:graph){
            int node = i.first;
            if(!visited[node]){
                int country_size =0;
                dfs_Helper(node,visited,country_size);
                total_count -= country_size*(country_size-1)/2;
            }
        }
        cout<<total_count<<endl;
    }
};
int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.dfs_Moon();
}
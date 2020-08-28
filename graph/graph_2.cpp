#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map <T,list<T>>adjList;
public:
    Graph(){}
    void addEdge(T u,T v,bool bidir =true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void printaddList(){
        for(auto row:adjList){
            T key = row.first;
            cout<<key<<"->";
            for(auto value:row.second){
                cout<<value<<",";
            }
            cout<<endl;
        }
    }
    void dfs_helper(T src,map<T,bool> &visited){
        visited[src] =true;
        cout<<src<<" ";
        for(auto neighbor:adjList[src]){
            if(!visited[neighbor]){
                dfs_helper(neighbor,visited);
            }
        }
    }
    void dfs(T src){
        map<T,bool>visited;
        dfs_helper(src,visited);
        cout<<endl;
        int component =1;
        for(auto it:adjList){
            T city = it.first;
            if(!visited[city]){
                dfs_helper(city,visited);
                component++;
            }
        }
        cout<<endl;
        cout<<component<<endl;
    }
};
int main(){
    Graph <string>g;
    g.addEdge("Amritsar","Jaipur");
    g.addEdge("Amritsar","Delhi");
    g.addEdge("Delhi","Jaipur");
    g.addEdge("Mumbai","Jaipur");
    g.addEdge("Mumbai","Bhopal");
    g.addEdge("Delhi","Bhopal");
    g.addEdge("Mumbai","Bangalore");
    g.addEdge("Agra","Delhi");
    g.addEdge("Andaman","Nicobar");
    g.dfs("Andaman");

}
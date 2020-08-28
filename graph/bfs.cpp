#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    //declare a map
    map<T,list<T>>adjList;
public:
    //empty constructor 
    Graph(){
        //do nothing here 
    }
    //functiont to add a edge
    void addEdge(int u,int v,bool bidir =true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    //function to print the graph
    void print(){
        for(auto i:adjList){
            cout<<i.first<<"->";
            for(auto vertex:i.second){
                cout<<vertex<"->";
            }
            cout<<endl;
        }
    }
    //bfs or breadth first search 
    void bfs(T src){
        queue <T>q;
        map<int,int>dist;
        map<int,int>parent;
        //make all the parents to INT_MAX
        for(auto element:adjList){
            dist[element.first]=INT_MAX;
        }
        //push the source element
        q.push(src);
        dist[src]=0;
        parent[src] =src;
        while(!q.empty()){
            T node =q.front();
            cout<<node<<"->";
            q.pop();
            for(auto neighbor:adjList[node]){
                if(dist[neighbor]==INT_MAX){
                    q.push(neighbor);
                    dist[neighbor]=dist[node]+1;
                    parent[neighbor] = node;
                }
            }
        }
        //print all the distance
        for(auto element:adjList){
            T node =element.first;
            cout<<"Distance of "<<node<<" from src is "<<dist[node]<<endl;
        }
    }
    
};
int main(){
    Graph <int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.bfs(0);
}

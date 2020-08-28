#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int v){
        V =v;
        l = new list<int>[V];

    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfsHelper(int node,bool visited[],int &country_size){
        visited[node] =true;
        country_size++;
        //check for the neighbor 
        for(auto neighbor:l[node]){
            if(visited[neighbor]==false){
                dfsHelper(neighbor,visited,country_size);
            }
        }
    }
    void dfsMoon(){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] =false;
        }
        //total combination of astronauts 
        int total_count = V*(V-1)/2;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                int country_size =0;
                dfsHelper(i,visited,country_size);
                total_count -= (country_size*(country_size-1)/2);
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
    g.dfsMoon();
}

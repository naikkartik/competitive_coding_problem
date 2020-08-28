#include <bits/stdc++.h>
using namespace std;

class Graph{
    map<int,list<int>>l;
public:
    Graph(){

    }
    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    void printGraph(){
        for(auto it:l){
            cout<<it.first<<" -> ";
        
            for(auto node:it.second){
                cout<<node<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(1,4);
    g.addEdge(0,4);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.printGraph();
}
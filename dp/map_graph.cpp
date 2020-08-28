#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//class for the graph 
template <typename T>
class Graph{
    map<T,list<T>>adjList;
public:
    //a void constructor 
    Graph(){}
    void addEdge(int u,int v,int bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }

    }
    void printList(){
        //iterate over all the element 
        for(auto it:adjList){
            T vertex = it.first;
            cout<<vertex<<"->";
            for(auto ver:it.second){
                cout<<ver<<"->";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph<int>g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.printList();
}
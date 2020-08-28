#include <iostream>
#include <list>
using namespace std;

//define the class for graph 
class Graph{
    int V;
    list <int> *l;
public:
    Graph(int v){
        V =v;
        l = new list<int>[V];
    }
    void addEdge(int u,int v,bool bidir =true){
        l[u].push_back(v);
        if(bidir){
            l[v].push_back(u);
        }
    }
    void printGraph(){
        for(int i=0;i<V;i++){
            cout<<i<<" -> ";
            for(auto node:l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.printGraph();
}
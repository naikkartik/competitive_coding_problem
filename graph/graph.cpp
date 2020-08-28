#include <iostream>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *l;   //pointer to a list 
public:
    //make a constructor 
    Graph(int v){
        V =v;
        l = new list<int>[V];  //creating a dynamic list of V size
    }
    //function to add edge
    void addEdge(int a,int b,bool bidir =true){
        l[a].push_back(b);
        if(bidir){
            l[b].push_back(a);
        }
    }
    void printList(){
        for(int i=0;i<V;i++){
            for(auto vertex:l[i]){
                cout<<vertex<<"->";
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
    g.printList();
}
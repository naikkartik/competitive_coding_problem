#include <bits/stdc++.h>
using namespace std; 
class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);

    void addEdge(int u,int v);

    void DFS(int v);

};
Graph::Graph(int V){
    V = V;
    adj =new list<int>[V];

}
void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}
void Graph::DFSUtil(int v,bool visited[]){
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            DFSUtil(*i,visited);
        }
    }
}
void Graph::DFS(int v){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    DFSUtil(v,visited);
}
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Depth First Traversal"
    " (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}

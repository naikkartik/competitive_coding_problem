#include <bits/stdc++.h>
using namespace std; 

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int u,int v);

    void BFS(int s);
};

Graph::Graph(int v){
    V = v;
    adj = new list<int>[V];
}
Graph::addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
Graph::BFS(int s){
    bool *visited = new int[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    queue<int>q;
    q.push(s);
    visited[s] =true;
    while(!q.empty()){
        s = q.front();
        cout<<s<<" ";
        q.pop();
        for(auto x adj[s]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
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
    cout << "Following is Breadth First Traversal "
    << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}
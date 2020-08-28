#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;
template <typename T>
class Graph{
    map<T,list<T> > adjList;
public:
    Graph(){

    }
    void addEdge(T u, T v,bool dir=true){
        adjList[u].push_back(v);
        if(dir){
            adjList[v].push_back(u);
        }
    }
    void printGraph(){
        for(auto it:adjList){
            cout<<it.first<<" -> ";
            for(auto it2:it.second){
                cout<<it2<<",";
            }
            cout<<endl;
        }
    }
    void bfs(T src){
        queue <T> q;
        map <T,bool> visited;
        q.push(src);
        visited[src] =true;
        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto neighbor:adjList[node]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] =true;
                }
            }
        }
        cout<<endl;
    }
    void bfs2(T src){
        queue <T> q;
        map<T,int>distance;
        map<T,T>parent;
        //store the distance to INT_MAX initially
        for(auto i:adjList){
            distance[i.first] = -1;
        }
        q.push(src);
        distance[src] = 0;
        parent[src] =src;
        while(q.empty()!=true){
            T node = q.front();
            q.pop();
            cout<<node<<" ";
            for(auto neighbor:adjList[node]){
                if(distance[neighbor]==-1){
                    q.push(neighbor);
                    distance[neighbor] = distance[node]+1;
                    parent[neighbor] = node;
                }
            }
        }
        cout<<endl;
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
    g.bfs("Mumbai");
}
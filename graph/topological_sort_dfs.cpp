#include <bits/stdc++.h>
using namespace std; 
template <typename T>
class Graph{
    map<T,list<T>>graph;
public:
    Graph(){}

    void addEdge(T u,T v,bool bidir =true){
        graph[u].push_back(v);
        if(bidir){
            graph[v].push_back(u);
        }
    }
    void dfs_helper(T node,map<T,bool>&visited,list<T>&ordering){
        visited[node] =true;
        for(T neighbor:graph[node]){
            if(!visited[neighbor]){
                dfs_helper(neighbor,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void topological_sort_dfs(){
        map<T,bool>visited;
        list<T>ordering;
        for(auto it:graph){
            T node = it.first;
            if(!visited[node]){
                dfs_helper(node,visited,ordering);
            }
        }
        for(auto node:ordering){
            cout<<node<<" ,";
        }
        cout<<endl;
    }

    void topological_sort_bfs(){
        queue<T>q;
        map<T,bool>visited;
        map<T,int>indegree;
        //initialise the the indegree
        for(auto it:graph){
            indegree[it.first] =0;
        }
        for(auto it:graph){
            T node = it.first;
            for(auto neighbor:graph[node]){
                indegree[neighbor]+=1;
            }
        }
        for(auto it:graph){
            T node = it.first;
            if(indegree[node]==0){
                q.push(node);
            }
        }
        while(!q.empty()){
            T node =q.front();
            cout<<node<<" ,";
            q.pop();
            for(auto neighbor:graph[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph <string> g;
    g.addEdge("English","Programming Logic",false);
    g.addEdge("Maths","Programming Logic",false);
    g.addEdge("Programming Logic","HTML",false);
    g.addEdge("Programming Logic","Java",false);
    g.addEdge("Programming Logic","Python",false);
    g.addEdge("Programming Logic","JS",false);
    g.addEdge("Python","Web Dev",false);
    g.addEdge("HTML","CSS",false);
    g.addEdge("CSS","JS",false);
    g.addEdge("JS","Web Dev",false);
    g.addEdge("Java","Web Dev",false);
    g.addEdge("Python","Web Dev",false);
    g.topological_sort_dfs();
    g.topological_sort_bfs();
}
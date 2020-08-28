#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map <T,list<T>>adjList;
public:
    Graph(){}
    void addEdge(T u,T v,bool bidir =true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void printaddList(){
        for(auto row:adjList){
            T key = row.first;
            cout<<key<<"->";
            for(auto value:row.second){
                cout<<value<<",";
            }
            cout<<endl;
        }
    }
    void dfs_helper(T node,map<T,bool>&visited,list<T>&ordering){
        visited[node] =true;
        for(auto neighbor:adjList[node]){
            if(!visited[neighbor]){
                dfs_helper(neighbor,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void topological_sort(){
        map <T,bool>visited;
        list<T> ordering;
        for(auto i:adjList){
            T node =i.first;
            if(!visited[node]){
                dfs_helper(node,visited,ordering);
            }
        }
        for(auto node:ordering){
            cout<<node<<" , ";
        }
        cout<<endl;
    }
    void topological_sort_bfs(){
        queue<T> q;
        map<T,bool>visited;
        map<T,int>indegree;
        //initialize the degree 
        for (auto i:adjList){
            T node = i.first;
            visited[node] =false;
            indegree[node] =0;
        }
        for(auto i:adjList){
            T u =i.first;
            for(T v:adjList[u]){
                indegree[v]++;

            }
        }
        //push the element with zero degree first 
        for(auto it:adjList){
            T node = it.first;
            if(indegree[node]==0){
                q.push(node);
            }
        }
        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto neighbor:adjList[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
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
    g.topological_sort_bfs();
}
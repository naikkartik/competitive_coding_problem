#include <bits/stdc++.h>
using namespace std; 

class Graph{
    map<int,list<int>>graph;
public:
    void addEdge(int u,int v,bool bidir=true){
        graph[u].push_back(v);
        if(bidir){
            graph[v].push_back(u);
        }
    }
    void printList(){
        for(auto it:graph){
            cout<<it.first<<" -> ";
            for(auto node:it.second){
                cout<<node<<" ,";
            }
            cout<<endl;
        }
    }
    void bfs(int src ,int target){
        queue<int>q;
        map<int,bool>visited;
        map<int,int>parent;
        visited[src] =true;
        parent[src] =src;
        q.push(src);
        while(!q.empty()){
            int node =q.front();
            q.pop();
            for(auto neighbor:graph[node]){
                if(!visited[neighbor]){
                    visited[neighbor] =true;
                    parent[neighbor] =node;
                    q.push(neighbor);
                }
            }
        }
        int parent_target = parent[target];
        int count =1;
        while(parent_target!=src){
            count+=1;
            if(parent_target<1 or parent_target>100){
                count =-1;
                break;
            }
            parent_target = parent[parent_target];
            //this nothing but back propagation
        }
        cout<<count<<endl;
    }
};

int main(){
    int T;
    cin>>T;
    while(T--){
        map<int,int>raise;
        for(int i=0;i<=100;i++){
            raise[i] =0;
        }
        int N;
        cin>>N;
        int lad_str,lad_end;
        while(N--){
            cin>>lad_str>>lad_end;
            raise[lad_str] = lad_end-lad_str;
        }
        int M;
        cin>>M;
        int snk_str,snk_end;
        while(M--){
            cin>>snk_str>>snk_end;
            raise[snk_str] =snk_end-snk_str;
        }
        //making the graph
        Graph g;
        for(int i=1;i<=100;i++){
            for(int j=1;j<=6;j++){
                int u =i;
                int v = i+j+raise[i+j];
                g.addEdge(u,v);
            }
        }
        g.bfs(1,100);
    }
}
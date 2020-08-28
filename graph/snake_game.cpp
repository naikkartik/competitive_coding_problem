#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph{
    map<int,list<int>>graph;
public:
    void addEdge(int u,int v){
        graph[u].push_back(v);
        //it is not a bidirectional graph;
    }
    void printaddList(){
        for(auto row:graph){
            int key = row.first;
            cout<<key<<"->";
            for(auto value:row.second){
                cout<<value<<",";
            }
            cout<<endl;
        }
    }
    void bfs(int src,int target){
        queue<int>q;
        q.push(src);
        map<int,bool>visited;
        map<int,int>parent;
        parent[src] =src;
        visited[src] =src;
        while(!q.empty()){
            int node =q.front();
            
            q.pop();
            for(auto neighbor:graph[node]){
                if(!visited[neighbor]){
                    visited[neighbor]=true;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }
        int par_target =parent[target];
        int count =1;
        
        while(par_target!=src){
            count++;
            if(par_target<1 or par_target>100){
                count =-1;
                break;
            }
            par_target = parent[par_target];
            
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
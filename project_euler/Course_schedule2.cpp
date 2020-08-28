#include <bits/stdc++.h>
using namespace std;
void dfs(int start,list<int>childrens,int visited[],vector<int>&result){
    if(visited[start]==1){
            return;
    }
    visited[start]=1;
    for(auto it:childrens){
        dfs(it,childrens,visited,result);
    }
}
int main(){
    map<int,list<int>>graph;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int children,parent;
        cin>>children>>parent;
        graph[parent].push_back(children);
    }

    for(auto it:graph){
        int start = it.first;
        list<int>childrens = it.second;
        int visited[n];
        memset(visited,0,sizeof(visited));
        vector<int>result;
        dfs(start,childrens,visited,result);
        int track = 1;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                track = 0;
                break;
            }
        }
        if(track==1){
            for(int i=0;i<result.size();i++){
                cout<<result[i]<<" ";
            }
            cout<<endl;
            break;
        }
        else{
            result.clear();
            memset(visited,0,sizeof(visited));
        }
        
    }
}
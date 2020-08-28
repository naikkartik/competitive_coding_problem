#include <bits/stdc++.h>
using namespace std; 

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        //do a bfs
        queue<pair<int,int>>q;
        q.push(make_pair(0,0));
        map<pair<int,int>,bool>visited;
        visited[make_pair(0,0)]=true;
        while(!q.empty()){
            pair<int,int>node =q.front();
            q.pop();
            int i=node.first;
            int j=node.second;
            cout<<arr[node.first][node.second]<<" ";
            //push the neighbor 1 if it is valid and not visited
            if(i<n and j+1<n and !visited[make_pair(i,j+1)]){
                visited[make_pair(i,j+1)]=true;
                q.push(make_pair(i,j+1));
            }
            if(i+1<n and j<n and !visited[make_pair(i+1,j)]){
                visited[make_pair(i+1,j)]=true;
                q.push(make_pair(i+1,j));
            }
        }
        cout<<endl;
    }
}
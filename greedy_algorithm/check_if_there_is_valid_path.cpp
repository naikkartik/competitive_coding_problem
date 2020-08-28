#include <bits/stdc++.h>
using namespace std; 
vector<vector<pair<int,int>>>prev_curI;
for(int i=0;i<=6;i++){
    vector<pair<int,int>>temp;
    for(int j=0;j<=6;j++){
        temp.push_back(make_pair(0,0));
    }
    prev_curI.push_back(temp);
}
prev_curI[1][1] =make_pair(0,1);
prev_curI[1][2] =make_pair(0,0);
prev_curI[1][3] =make_pair(1,1);
prev_curI[1][4] =make_pair(-1,1);
prev_curI[1][5] =make_pair(-1,1);
prev_curI[1][6] =make_pair(-1,-1);
prev_curI[2][1] =make_pair(0,0);
prev_curI[2][2]=make_pair(1,0);
prev_curI[2][3]=make_pair(-1,-1);
prev_curI[2][4]=make_pair(-1,1);
prev_curI[2][5]=make_pair(1,-1);
prev_curI[2][6]=make_pair(1,1);
prev_curI[3][1]=make_pair(0,-1);
prev_curI[3][2]=make_pair(1,0);
prev_curI[3][3]=make_pair(0,0);
prev_curI[3][4]=make_pair(1,-1);
prev_curI[3][5]=make_pair(1,-1);
prev_curI[3][6]=make_pair(1,1);
prev_curI[4][1]=make_pair(0,1);
prev_curI[4][2]=make_pair(1,0);
prev_curI[4][3]=make_pair(1,1);
prev_curI[4][4]=make_pair(0,0);
prev_curI[4][5]=make_pair(1,-1);
prev_curI[4][6]=make_pair(1,1);
prev_curI[5][1]=make_pair(-1,0);
prev_curI[5][2]=make_pair(-1,0);
prev_curI[5][3]=make_pair(-1,-1);
prev_curI[5][4]=make_pair(-1,1);
prev_curI[5][5]=make_pair(0,0);
prev_curI[5][6]=make_pair(-1,-1);
prev_curI[6][1]=make_pair(0,1);
prev_curI[6][2]=make_pair(-1,0);
prev_curI[6][3]=make_pair(1,1);
prev_curI[6][4]=make_pair(-1,1);
prev_curI[6][5]=make_pair(-1,1);
prev_curI[6][6]=make_pair(0,0);

bool hasValidPath(int i,int j,int m,int n,vector<vector<int>>grid,map<pair<int,int>,bool>&visited,int prev){
    //base case 
    if(i==m-1 and j==n-1){
        return true;
    }
    pair<int,int>tmp =make_pair(i,j);
    if(visited.find(tmp)!=visited.end()){
        return false;
    }
    visited[tmp] =true;
    if(i>=m or j>=n){
        return false;
    }
    if(i<0 or j<0) return false;
    
    if(prev==1 and grid[i][j]==1){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==1 and grid[i][j]==2){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==1 and grid[i][j]==3){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==1 and grid[i][j]==4){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==1 and grid[i][j]==5){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==1 and grid[i][j]==6){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }

    //2
    if(prev==2 and grid[i][j]==1){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==2 and grid[i][j]==2){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==2 and grid[i][j]==3){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==2 and grid[i][j]==4){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==2 and grid[i][j]==5){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==2 and grid[i][j]==6){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }

    //3
    if(prev==3 and grid[i][j]==1){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==3 and grid[i][j]==2){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==3 and grid[i][j]==3){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==3 and grid[i][j]==4){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==3 and grid[i][j]==5){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev== and grid[i][j]==6){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }

    //4
    if(prev==4 and grid[i][j]==1){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==4 and grid[i][j]==2){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==4 and grid[i][j]==3){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==4 and grid[i][j]==4){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==4 and grid[i][j]==5){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==4 and grid[i][j]==6){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    //5
    if(prev==5 and grid[i][j]==1){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==5 and grid[i][j]==2){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==5 and grid[i][j]==3){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==5 and grid[i][j]==4){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==5 and grid[i][j]==5){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==5 and grid[i][j]==6){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }

    //6
    if(prev==6 and grid[i][j]==1){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==6 and grid[i][j]==2){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==6 and grid[i][j]==3){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==6 and grid[i][j]==4){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==6 and grid[i][j]==5){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
    if(prev==6 and grid[i][j]==6){
        int a =prev;
        int b =grid[i][j];
        int cur_i = i+prev_curI[a][b].first;
        int cur_j = j+prev_curI[a][b].second;
        return hasValidPath(cur_i,cur_j,m,n,grid,visited,b);
    }
}

int main(){
    vector<vector<int>>grid;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            int value;
            cin>>value;
            temp.push_back(value);
        }
        grid.push_back(temp);
    }
    map<pair<int,int>,bool>visited;
    int i,j,prev;
    if(grid[0][0]==1){
        prev =1;
        i = 0;
        j =1;
    }
    else{
        prev =2;
        i =1;
        j =0;
    }
    bool check = hasValidPath(i,j,m,n,grid,visited,prev);
    if(check){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define R 5
#define C 5

bool isValid(int i,int j){
    return (i>=0 and j>=0 and i<R and j<C);
}
int max_coin_collection(int i,int j,int dir,char arr[R][C],map<pair<pair<int,int>,int>,int>&dp){
    if(isValid(i,j)==false or arr[i][j]=='#'){
        return 0;
    }
    pair<pair<int,int>,int >tmp = make_pair(make_pair(i,j),dir);
    if(dp.find(tmp)!=dp.end()){
        return dp[tmp];
    }
    int result =(arr[i][j]=='C'?1:0);
    if(dir==1){
        return result+max(max_coin_collection(i+1,j,0,arr,dp),
                          max_coin_collection(i,j+1,1,arr,dp));
    }
    return result+max(max_coin_collection(i+1,j,1,arr,dp),
                      max_coin_collection(i,j-1,0,arr,dp));
}

int main(){
    map<pair<pair<int,int>,int>,int>dp;
    char arr[R][C] ={
        {'E', 'C', 'C', 'C','C'},
        {'C', '#', 'C', '#','E'},
        {'#', 'C', 'C', '#','C'},
        {'C', 'E', 'E', 'C','E'},
        {'C', 'E', '#', 'C','E'}
    };
    cout<<max_coin_collection(0,0,1,arr,dp)<<endl;
}

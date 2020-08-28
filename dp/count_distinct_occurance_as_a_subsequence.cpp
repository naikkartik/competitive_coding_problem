#include <bits/stdc++.h>
using namespace std; 

int distinct_count(string S,string T,int i,int j,int m,int n,int dp[][1000]){
    //base case 
    if(i>=m){
        return 1;
    }
    if(j>=n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //recursive case 
    if(S[j]==T[i]){
        int a = distinct_count(S,T,i+1,j+1,m,n,dp);
        int b =distinct_count(S,T,i,j+1,m,n,dp);
        return dp[i][j] =(a+b);
    }
    return dp[i][j] =distinct_count(S,T,i,j+1,m,n,dp);
}
int dp_solution_bottom_up(string S,string T){
    int m = T.size();
    int n = S.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0] =0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i] =1;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            //check for equality
            if(T[i-1]!=S[j-1]){
                dp[i][j] = dp[i][j-1];
            }
            else{
                dp[i][j] =dp[i-1][j-1]+dp[i][j-1];
            }
        }
    }
    return dp[m][n];
}
int main(){
    string S,T;
    cin>>S>>T;
    int dp[T.length()+1][1000];
    memset(dp,-1,sizeof(dp));
    int count = distinct_count(S,T,0,0,T.length(),S.length(),dp);
    int count2 =dp_solution_bottom_up(S,T);
    cout<<count<<endl;
    cout<<count2<<endl;
    return 0;
}
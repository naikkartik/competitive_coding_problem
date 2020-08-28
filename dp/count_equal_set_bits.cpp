#include <bits/stdc++.h>
using namespace std; 


int countTotal(int n,int curr,int dp[][1000]){
    if(n==1){
        return 1;
    }
    if(dp[curr][n]! ezawse  q`=-1){
        return dp[curr][n];
    }
    if(curr==0){
        return dp[curr][n] =countTotal(n-1,0,dp)+countTotal(n-1,1,dp);
    }
    return dp[curr][n] =countTotal(n-1,0,dp);
}
int main(){
    int n;
    cin>>n;
    int dp[2][1000];
    memset(dp,-1,sizeof(dp));
    int ans =countTotal(n,0,dp)+countTotal(n,1,dp);
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int eggDrop(int n,int k){
    if(k==0 || k==1){
        return k;
    }
    if(n==1) return k;
    int ans =INT_MAX;
    for(int x=1;x<=k;x++){
        int res = max(eggDrop(n-1,x-1),eggDrop(n,k-x));
        ans =min(res,ans);
    }
    return ans+1;
}
int dp_solution_top_down(int n,int k,map<pair<int,int>,int>&dp){
    if(k==0 || k==1){
        return k;
    }
    if(n==1) return k;
    if(dp.find(make_pair(n,k))!=dp.end()){
        return dp[make_pair(n,k)];
    }
    int ans =INT_MAX;
    for(int x=1;x<=k;x++){
        int res =max(dp_solution_top_down(n-1,x-1,dp),dp_solution_top_down(n,k-x,dp));
        ans =min(ans,res);
    }
    return dp[make_pair(n,k)]=(ans+1);
}
int dp_solution_bottom_up(int n,int k){
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(int i=0;i<=k;i++){
        dp[1][i]=i;
        
    }
    for(int i=2;i<=n;i++){
        for(int  j=2;j<=k;j++){
            int ans = INT_MAX;
            for(int x=1;x<=j;x++){
                int res = max(dp[i-1][x-1],dp[i][j-x]);
                ans =min(res,ans);
            }
            dp[i][j] =ans+1;
        }
    }
    return dp[n][k];
}
int main(){
    int n = 2, k = 36;
    map<pair<int,int>,int>dp;
    
    cout<<dp_solution_top_down(n,k,dp)<<endl;
    cout<<dp_solution_bottom_up(n,k)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std; 
#define mod 1000000007;

long long countArrayFill(int i,int n,int k,int x,int cur,map<pair<int,int>,int>&dp){
    if(i==n and cur==x){
        return 1;
    }
    if(i>=n or (i==n and cur!=x)){
        return 0;
    }
    pair<int,int>tmp =make_pair(i,cur);
    if(dp.find(tmp)!=dp.end()){
        return dp[tmp];
    }
    long long ans =0;
    for(int j=1;j<=k;j++){
        if(j!=cur){
            ans+=(countArrayFill(i+1,n,k,x,j,dp))%mod;
        }
    }
    return dp[tmp] = ans;
}
int main(){
    int n,k,x;
    cin>>n>>k>>x;
    map<pair<int,int>,int>dp;
    int ans =countArrayFill(1,n,k,x,1,dp);
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int cut_the_road(int n,map<int,int>&dp){
    if(n==1 or n==0){
        return 0;
    }
    if(dp.find(n)!=dp.end()){
        return dp[n];
    }
    int ans =INT_MIN;
    for(int i=1;i<n;i++){
        ans =max(ans,max(i*(n-i),cut_the_road(n-i,dp)));
    }
    return dp[n] = ans;
}
int cut_the_road_btm_up(int n){
    int dp[n+1];
    dp[0]=dp[1] =0;
    for(int i=2;i<)
}
int main(){
    int n;
    cin>>n;
    map<int,int>dp;
    cout<<cut_the_road(n,dp)<<endl;
}
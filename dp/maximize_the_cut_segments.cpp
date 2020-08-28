#include <bits/stdc++.h>
using namespace std; 
int solution(int n,int x,int y,int z,map<int,int>&dp){
    if(n>=0 and n<x and n<y and n<z){
        return 0;
    }
    if(n<0) return INT_MIN;
    if(dp.find(n)!=dp.end()){
        return dp[n];
    }
    int ans1= solution(n-x,x,y,z,dp)+1;
    int ans2=solution(n-y,x,y,z,dp)+1;
    int ans3=solution(n-z,x,y,z,dp)+1;
    return dp[n] = max(ans1,max(ans2,ans3));
}
int main(){
    int n,x,y,z;
    cin>>n;
    cin>>x>>y>>z;
    map<int,int>dp;
    int ans = solution(n,x,y,z,dp);
    cout<<ans<<endl;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long fill_tile(long long n,long long m,map<long long,long long>&dp){
    if(n<0){
        return 0;
    }
    if(n>=0 and n<m){
        return 1;
    }
    long long hor,ver;
    if(dp.find(n-1)!=dp.end()){
        hor = dp[n-1];
    }
    else{
        hor =fill_tile(n-1,m,dp);
    }
    if(dp.find(n-m)!=dp.end()){
        ver = dp[n-m];
    }
    else{
        ver = fill_tile(n-m,m,dp);
    }
    long long ans = (hor+ver)%1000000007;
    return dp[n]=ans;
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        map<long long,long long>dp;
        cout<<fill_tile(n,m,dp)<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std; 
#define max 1000
int find_ncr(int n,int r,int p,map<pair<int,int>,int>&dp){
    if(r==0){
        return 1;
    }
    if(n==r){
        return 1;
    }
    pair<int,int>tmp =make_pair(n,r);
    if(dp.find(tmp)!=dp.end()){
        return dp[tmp];
    }
    return dp[tmp] =(find_ncr(n-1,r-1,p,dp)%p+find_ncr(n-1,r,p,dp)%p)%p;
}
int main(){
    int n =1;
    int r =2;
    int p =13;
    map<pair<int,int>,int>dp;
    cout<<find_ncr(n,r,p,dp)<<endl;
}
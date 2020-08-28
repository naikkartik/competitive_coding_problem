#include <bits/stdc++.h>
using namespace std; 

int count_d(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return (n-1)*(count_d(n-1)+count_d(n-2));
}
int dp_solution(int n,int dp[]){
    //base case 
    if(n==0) return 1;
    if(n==1)return 0;
    if(n==2) return 1;
    //check for preexitance 
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] =(n-1)*(dp_solution(n-1,dp)+dp_solution(n-2,dp));
}

int main(){
    int n;
    int dp[n];
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<dp_solution(n,dp)<<endl;
    return 0;
}
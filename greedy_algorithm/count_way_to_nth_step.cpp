#include <bits/stdc++.h>
using namespace std;
int count_step(int n,int dp[]){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans =count_step(n-1,dp)+count_step(n-2,dp);
    return dp[n]=ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int dp[1000];
        memset(dp,-1,sizeof(dp));
        int ans = count_step(n,dp);
        cout<<ans<<endl;
    }
    return 0;
}
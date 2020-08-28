#include <bits/stdc++.h>
using namespace std; 
int maximum_profit(int arr[],int n,int k,int dp[][50]){
    if(k<=0 or n<=0){
        return 0;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    int ans1 = 0;;
    for(int i=0;i<n;i++){
        ans1 =max(arr[n]-arr[i]+maximum_profit(arr,i-1,k-1,dp),ans1);
    }
    int ans2 = maximum_profit(arr,n-1,k,dp);
    int ans =max(ans1,ans2);
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int dp[500][50];
        memset(dp,-1,sizeof(dp));
        int ans =maximum_profit(arr,n-1,k,dp);
        cout<<ans<<endl;
    }
}

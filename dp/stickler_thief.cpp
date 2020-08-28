#include <bits/stdc++.h>
using namespace std;
int max_profit(int arr[],int n,int dp[10005]){
    if(n<=0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans1 =max_profit(arr,n-2,dp)+arr[n-1];
    int ans2 =max_profit(arr,n-1,dp);
    return dp[n] = max(ans1,ans2);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int dp[10005];
        memset(dp,-1,sizeof(dp));
        int ans = max_profit(arr,n,dp);
        cout<<ans<<endl;
    }
}
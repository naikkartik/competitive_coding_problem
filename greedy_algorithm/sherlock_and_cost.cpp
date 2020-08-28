#include <bits/stdc++.h>
using namespace std;
int find_max_diff(int n,int arr[],int cur,int dp[][500]){
    if(n<=0){
        return 0;
    }
    if(dp[n][cur]!=-1){
        return dp[n][cur];
    }
    int ans1 = abs(cur-arr[n-1])+find_max_diff(n-1,arr,arr[n-1],dp);
    int ans2 = abs(cur-1)+find_max_diff(n-1,arr,1,dp);
    return dp[n][cur] =max(ans1,ans2);
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
        if(n==1){
            cout<<arr[n-1]<<endl;
        }
        else{
            int dp[1000][500];
            memset(dp,-1,sizeof(dp));
            int a = find_max_diff(n-1,arr,arr[n-1],dp);
            int b = find_max_diff(n-1,arr,1,dp);
            cout<<max(a,b)<<endl;
        }
    }
}
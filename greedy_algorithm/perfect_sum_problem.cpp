#include <bits/stdc++.h>
using namespace std; 
int find_way(int arr[],int n,int K,int dp[][500]){
    if(K==0){
        return 1;
    }
    if(K<0 or n<0){
        return 0;
    }
    if(dp[K][n]!=-1){
        return dp[K][n];
    }
    int ans1 = find_way(arr,n-1,K-arr[n],dp);
    int ans2 =find_way(arr,n-1,K,dp);
    return dp[K][n]=ans1+ans2;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int K,n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cin>>K;
        int dp[1000][500];
        memset(dp,-1,sizeof(dp));
        int ans = find_way(arr,n-1,K,dp);
        cout<<ans<<endl;
    }
}
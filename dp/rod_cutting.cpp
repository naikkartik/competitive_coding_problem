#include <bits/stdc++.h>
using namespace std;

int rod_cutting_recurse(int n,int arr[],int k,int dp[]){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans =INT_MIN;
    for(int i=0;i<k;i++){
        if(n-i-1>=0){
            int res =rod_cutting_recurse(n-i-1,arr,k,dp)+arr[i];
            ans =max(ans,res);
        }
    }
    return dp[n]=ans;
}
int rod_cutting_bottom_up(int n,int arr[],int k){
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i] =INT_MIN;
        for(int j=0;j<k;j++){
            if(i-j-1>=0){
                dp[i] =max(dp[i-j-1]+arr[j],dp[i]);
            }
        }
    }
    return dp[n];
}
int main(){
    int dp[100];
    for(int i=0;i<100;i++){
        dp[i] =-1;
    }
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n=8;
    int k=8;
    cout<<rod_cutting_recurse(n,arr,k,dp)<<endl;
}
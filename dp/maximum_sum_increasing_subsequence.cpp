#include <bits/stdc++.h>
using namespace std;
int max_sum_inc_ss(int arr[],int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] =arr[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] and dp[i]<dp[j]+arr[i]){
                dp[i] =dp[j]+arr[i];
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]>ans) ans=dp[i];
    }
    return ans;
}
int main(){
    int arr[]={1, 101, 2, 3, 100, 4, 5};
    int n=7;
    cout<<max_sum_inc_ss(arr,n)<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int solution(int arr[],int n,map<int,int>&dp){
    if(n<=0){
        return 0;
    }
    if(dp.find(n)!=dp.end()){
        return dp[n];
    }
    int ans1 = solution(arr,n-2,dp)+arr[n-1];
    int ans2 = solution(arr,n-1,dp);
    return dp[n]=max(ans1,ans2);
}
 int main(){
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     map<int,int>dp;
     int ans = solution(arr,n,dp);
     cout<<ans<<endl;
 }
 
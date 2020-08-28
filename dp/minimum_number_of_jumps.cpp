#include <bits/stdc++.h>
using namespace std; 
int find_min_number_of_jump(int cur,int n,int arr[],map<int,int>&dp){
    if(cur==n){
        return 0;
    }
    if(cur>n){
        return INT_MAX;
    }
    int tmp =cur;
    if(dp.find(tmp)!=dp.end()){
        return dp[tmp];
    }
    int ans =INT_MAX;
    for(int i=1;i<=arr[cur-1];i++){
        if(cur+i<=n){
            int temp = find_min_number_of_jump(cur+i,n,arr,dp)+1;
            ans =min(temp,ans);
        }
    }
    return dp[tmp] = ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        map<int,int>dp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans = find_min_number_of_jump(1,n,arr,dp);
        cout<<ans<<endl;
    }
}

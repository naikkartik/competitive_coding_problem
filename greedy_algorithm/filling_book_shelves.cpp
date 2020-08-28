#include <bits/stdc++.h>
using namespace std;
int max_height(vector<pair<int,int>>arr,int n,int max_width,int cur_height,int real_width,int dp[][1005]){
    if(n>=arr.size()){
        return cur_height;
    }
    if(max_width<0){
        return INT_MAX;
    }
    if(dp[n][max_width]!=-1){
        return dp[n][max_width];
    }
    int a = max_height(arr,n+1,max_width-arr[n].first,max(cur_height,arr[n].second),real_width,dp);
    int b =max_height(arr,n+1,real_width-arr[n].first,arr[n].second,real_width,dp)+cur_height;
    return dp[n][max_width] = min(a,b);
}

int main(){
    vector<pair<int,int>>arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int p,q;
        cin>>p>>q;
        arr.push_back(make_pair(p,q));
    }
    int max_width;
    cin>>max_width;
    int dp[2000][1005];
    memset(dp,-1,sizeof(dp));
    int ans = max_height(arr,1,max_width-arr[0].first,arr[0].second,max_width,dp);
    cout<<ans<<endl;
}
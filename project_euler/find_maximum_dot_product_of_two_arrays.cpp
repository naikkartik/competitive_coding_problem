#include <bits/stdc++.h>
using namespace std;

int solution(int arr1[],int arr2[],int m,int n,map<pair<int,int>,int>&dp){
    if(n==0 or m==0){
        return 0;
    }
    pair<int,int>tmp = make_pair(m,n);
    if(dp.find(tmp)!=dp.end()){
        return dp[tmp];
    }
    int ans1 = solution(arr1,arr2,m-1,n,dp);
    int ans2 = solution(arr1,arr2,m-1,n-1,dp)+arr1[m-1]*arr2[n-1];
    return dp[tmp]=max(ans1,ans2);
}
int solution2(int arr1[],int arr2[],int m,int n){
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j-1]+arr1[i-1]*arr2[j-1];
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }
    return dp[m][n];
}
int main(){
    int m,n;
    cin>>m>>n;
    int arr1[m];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    int arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    map<pair<int,int>,int>dp;
    int ans =solution(arr1,arr2,m,n,dp);
    cout<<ans<<endl;
    cout<<solution2(arr1,arr2,m,n)<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int total_score(int i,int j,int arr[],int dp[][500]){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans1 = arr[i]+min(
        total_score(i+2,j,arr,dp),
        total_score(i+1,j-1,arr,dp)
    );
    int ans2 =arr[j]+min(
        total_score(i+1,j-1,arr,dp),
        total_score(i,j-2,arr,dp)
    );
    return dp[i][j] = max(ans1,ans2);

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int dp[500][500];
    memset(dp,-1,sizeof(dp));
    int ans = total_score(0,n-1,arr,dp);
    if(ans>(sum-ans)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}
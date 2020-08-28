#include <bits/stdc++.h>
using namespace std;
int solution(int arr[],int n,int dp[]){
    dp[0] = arr[0];
    for(int i=1;i<n;i++){
        dp[i]+=(arr[i]+dp[i-1]);
    }

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n];
    int ans = solution(arr,n,dp);


}
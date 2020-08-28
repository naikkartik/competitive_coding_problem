#include <bits/stdc++.h>
using namespace std; 
int solution(int arr[],int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]= arr[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            //check for increasing subsequence
            if(arr[i]>arr[j] and dp[i]<dp[j]+arr[i]){
                dp[i]=dp[j]+arr[i];
                
            }
        }
    }
    int ans=dp[0];
    for(int i=1;i<n;i++){
        ans = max(dp[i],ans);
    }
    return ans;
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
        int ans = solution(arr,n);
        cout<<ans<<endl;
    }
}
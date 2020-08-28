#include <bits/stdc++.h>
using namespace std;
int solution(int arr[],int n){
    int dp[n];
    int smallest = arr[0];
    dp[0] = arr[0];
    for(int i =1;i<n;i++){
        if(smallest>arr[i]){
            smallest = arr[i];
        }
        dp[i] = smallest;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,arr[i]-dp[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = solution(arr,n);
    cout<<ans<<endl;
}

#include <bits/stdc++.h>
using namespace std;
int solution(int arr[],int n){
    int dp[n];
    char sign[n];
    for(int i=0;i<n;i++){
        dp[i] =1;
        sign[i]='=';
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            char cur_sign,prev_sign;
            if(arr[i]>arr[j]) cur_sign='>';
            else if(arr[i]<arr[j]) cur_sign='<';
            else cur_sign ='=';
            prev_sign=sign[j];
            if(prev_sign!=cur_sign and dp[i]<dp[j]+1 and cur_sign!='='){
                dp[i] = dp[j]+1;
                sign[i]=cur_sign;
            }
        }
        
    }
    int ans =INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
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
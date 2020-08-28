#include <bits/stdc++.h>
using namespace std; 

int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int dp[m][n];
    for(int i=0;i<n;i++){
        dp[0][i] =arr[0][i];
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            int a,b,c;
            a=b=c=INT_MAX;
            if(j-1>=0){
                a =dp[i-1][j-1];
            }
            b=dp[i-1][j];
            if(j+1<n){
                c =dp[i-1][j+1];
            }
            dp[i][j] = arr[i][j]+min(a,min(b,c));
        }
    }
    int ans = dp[m-1][0];
    for(int i=1;i<n;i++){
        ans = min(ans,dp[m-1][i]);
    }
    cout<<ans<<endl;
}
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
    dp[0][0] =arr[0][0];
    int a,b;
    for(int i=0;i<m;i++){
        dp[i][0]=dp[i-1][0]+arr[i][0];
    }
    for(int j=0;j<n;j++){
        dp[0][j]=dp[0][j-1]+arr[0][j];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]= min(arr[i][j-1],
                          min(arr[i-1][j],
                          arr[i-1][j-1]))+arr[i][j];
        }
    }
    
    cin>>a>>b;
    cout<<dp[a][b]<<endl;
}
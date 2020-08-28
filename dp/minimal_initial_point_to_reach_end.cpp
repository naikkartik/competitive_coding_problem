#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000]
int minimal_point(int arr[1000][1000],int m,int n){
    int dp[m][n];
    if(arr[m-1][n-1]>0){
        dp[m-1][n-1] =1;
    }
    else{
        dp[m-1][n-1] = 1+abs(arr[m-1][n-1]);
    }
    for(int i=m-2;i>=0;i--){
        dp[i][m-1] = max(dp[i+1][m-1]-arr[i][m-1],1);
    }
    for(int =n-2;i>=0;i--){
        dp[n-1][i] = max(dp[n-1][i+1]-arr[n-1][i],1);
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            int cur_point = min(dp[i+1][j],dp[i][j+1]);
            dp[i][j]= max(cur_point-arr[i][j],1);
        }
    }
    return dp[0][0];
}
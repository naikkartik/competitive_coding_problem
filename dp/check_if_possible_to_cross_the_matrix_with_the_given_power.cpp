#include <bits/stdc++.h>
using namespace std;

int possible(int arr[3][4],int m,int n,int K){
    int dp[m][n];
    //initialize the first columns and all rows
    dp[0][0] = K-arr[0][0];
    for(int i=1;i<m;i++){
        dp[i][0] =dp[i-1][0]-arr[i][0];
    }
    int power =0;
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]-arr[0][i];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]))-arr[i][j];
        }
    }
    if(dp[m-1][n-1]>=0){
        return K-dp[m-1][n-1];
    }
    return -1;
}

int main(){
    int m=3;
    int n=4;
    int K=9;
    int mat[3][4] = {
        {2, 3, 4, 1 },
        {6, 5, 5, 3 },
        {5, 2, 3, 4 }
    };
    int k = possible(mat,m,n,K);
    cout<<k<<endl;
}
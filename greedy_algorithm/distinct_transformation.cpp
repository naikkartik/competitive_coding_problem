#include <bits/stdc++.h>
using namespace std; 
int count_distinct(string A,string B,int m,int n,int dp[][200]){
    if(n==0){
        return 1;
    }
    if(m==0){
        return 0;

    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(A[m-1]==B[n-1]){
        return count_distinct(A,B,m-1,n-1,dp)+count_distinct(A,B,m-1,n,dp);
    }
    return count_distinct(A,B,m-1,n,dp);
}
//top down method for this 
int count_distinct_top_down(string A,string B){
    int m=A.length();
    int n=B.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0] =1;
    }
    for(int i=1;i<=n;i++){
        dp[0][i] =0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j] =dp[i-1][j-1]+dp[i-1][j];
            }
            else{
                dp[i][j] =dp[i-1][j];
            }
        }
    }
    return dp[m][n];

}
int main(){
    int T;
    cin>>T;
    while(T--){
        string A,B;
        cin>>A>>B;
        int dp[1100][200];
        memset(dp,-1,sizeof(dp));
        int ans =count_distinct(A,B,A.length(),B.length(),dp);
        cout<<ans<<endl;
        int ans2 =count_distinct_top_down(A,B);
        cout<<ans2<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std; 

int total_possible_path(int m,int n){
    int dp[m][n];
    //initialize all rows and columns with 1
    for(int i=0;i<m;i++){
        dp[i][0] =1;
    }
    for(int i=0;i<n;i++){
        dp[0][i] =1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] =dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
int number_of_recursive(int m,int n){
    if(m==1 or n==1){
        return 1;
    }
    return number_of_recursive(m-1,n)+number_of_recursive(m,n-1);
}
int main(){
    int m,n;
    cin>>m>>n;
    int ans = total_possible_path(m,n);
    int ans2 =number_of_recursive(m,n);
    cout<<ans<<endl;
    cout<<ans2<<endl;
}
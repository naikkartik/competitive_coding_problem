#include <bits/stdc++.h>
using namespace std;
int solution(string X,string Y){
    int m = X.length();
    int n = Y.length();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0] =0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j =1;j<=n;j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}
int main(){
    string X;
    string Y;
    cin>>X;
    cin>>Y;
    int ans =solution(X,Y);
    cout<<ans<<endl;
}

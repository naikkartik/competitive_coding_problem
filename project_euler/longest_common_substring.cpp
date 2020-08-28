#include <bits/stdc++.h>
using namespace std;
int solution(string str){
    string rev = str;
    reverse(rev.begin(),rev.end());
    int n = str.length();
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
        dp[i][0]=0;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str[i-1]==rev[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans,dp[i][j]);
            }
            else{
                dp[i][j]= 0;
            }
        }       
    }
    return ans;
}
int main(){
    string str;
    cin>>str;
    int ans = solution(str);
    cout<<ans<<endl;
}
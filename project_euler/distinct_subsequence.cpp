#include <bits/stdc++.h>
using namespace std;
int solution(string S,string T,int m,int n){
    if(n==0){
        return 1;
    }
    if(m==0){
        return 0;
    }
    if(S[m-1]==T[n-1]){
        int ans1 = solution(S,T,m-1,n-1);
        int ans2 = solution(S,T,m-1,n);
        return (ans1+ans2);
    }
    return solution(S,T,m-1,n);
}
int solution2(string S,string T,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0] =1;
    }
    for(int i=0;i<=n;i++){
        dp[0][i] =0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(S[i-1]==T[j-1]){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=m;i++){
        ans+=dp[i][n];
    }
    return ans;
}
int main(){
    string S,T;
    cin>>S;
    cin>>T;
    int ans = solution2(S,T,S.length(),T.length());
    cout<<ans<<endl;
}
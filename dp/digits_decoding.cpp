#include <bits/stdc++.h>
using namespace std; 

int count_decoding(char *digits,int n,int dp[]){
    if(n==0 or n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int count =0;
    if(digits[n-1]>'0'){
        count+=count_decoding(digits,n-1,dp);
    }
    if(digits[n-2]=='1' || digits[n-2]=='2' and digits[n-1]<'7'){
        count+=count_decoding(digits,n-2,dp);
    }
    return dp[n] =count;
}
int dp_btm_up(int n,char *digits){
    int dp[n+1];
    dp[0] =1;
    dp[1] =1;
    for(int i=2;i<=n;i++){
        int count =0;
        if(digits[i-1]>'0'){
            count +=dp[i-1];
        }
        
        if(digits[i-2]=='1' or digits[i-2]=='2' and digits[i-1]<'7'){
            count+=dp[i-2];
        }
        dp[i] =count;
    }
    return dp[n];
}
int main()
{
    char digits[] = "12345678921533433432102029202920202";
    int n = strlen(digits);
    int dp[1000];
    memset(dp,-1,sizeof(dp));
    cout << "Count is " << count_decoding(digits, n,dp)<<endl;
    cout<<dp_btm_up(n,digits)<<endl;
    return 0;
}
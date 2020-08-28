#include <bits/stdc++.h>
using namespace std; 

int countGroups(int position,int previous_sum,int length,char *digits,int dp[][200]){
    if(position==length){
        return 1;
    }
    if(dp[position][previous_sum]!=-1){
        return dp[position][previous_sum];
    }
    int sum =0;
    int res =0;

    for(int i=position;i<length;i++){
        sum+= (digits[i]-'0');
        if(sum>=previous_sum){
            res+=countGroups(i+1,sum,length,digits,dp);
        }
    }
    return dp[position][previous_sum] = res;
}

int main()
{
    char num[] = "1234";
    int dp[1000][200];
    memset(dp,-1,sizeof(dp));
    int len = strlen(num);
    cout << countGroups(0, 0, len, num,dp);
    return 0;
}
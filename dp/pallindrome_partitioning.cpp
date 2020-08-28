#include <bits/stdc++.h>
using namespace std; 
bool check_palindrome(string str,int i,int j){
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int palindrome_partition(string str,int i,int j,int dp[][1000]){
    if(i==j){
        return 0;
    }
    if(check_palindrome(str,i,j)) return 0;
    //check for pallindrome
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=(j-i);
    for(int k=i+1;k<j;k++){
        int ans_temp = palindrome_partition(str,i,k,dp)+palindrome_partition(str,k+1,j,dp)+1;
        ans = min(ans,ans_temp);
    }
    return dp[i][j] = ans;

}

int main(){
    string str;
    cin>>str;
    int i=0;
    int j =str.length()-1;
    int dp[1000][1000];
    memset(dp,-1,sizeof(dp));
    int ans = palindrome_partition(str,i,j,dp);
    cout<<ans<<endl;
}
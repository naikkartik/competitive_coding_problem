#include <bits/stdc++.h>
using namespace std;

int count_total(int i,int j,string str){
    if(i==j){
        return 1;
    }
    if(i>j){
        return 0;
    }
    if(str[i]==str[j]){
        return 1+count_total(i+1,j,str)+count_total(i,j-1,str);
    }
    return (count_total(i+1,j,str)+count_total(i,j-1,str)-count_total(i+1,j-1,str));
}
int dp_solution_top_down(int i,int j,string str,int dp[][1000]){
    if(i==j){
        return 1;
    }
    if(i>j){
        return 0;
    }
    //check for already calculated value 
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    //else calculate the ans for current i and j 
    if(str[i]==str[j]){
        return dp[i][j] =1+ dp_solution_top_down(i+1,j,str,dp)+dp_solution_top_down(i,j-1,str,dp);
    }
    return dp[i][j] = dp_solution_top_down(i+1,j,str,dp)+dp_solution_top_down(i,j-1,str,dp)-dp_solution_top_down(i+1,j-1,str,dp);
    
}
int dp_solution_btm_up(string str){
    int n =str.length();
    int cps[n+1][n+1];
    //fill the complete array with 0
    memset(cps,0,sizeof(cps));
    //fill the i==j as 1 
    for(int i=0;i<n;i++){
        cps[i][i] =1;
    }
    //fill diogonally 
    for(int L=2;L<=n;L++){
        for(int i=0;i<n;i++){
            int k =L+i-1;
            if(str[i]==str[k]){
                cps[i][k] = cps[i+1][k]+cps[i][k-1]+1;
            }
            else{
                cps[i][k] =cps[i+1][k]+cps[i][k-1]-cps[i+1][k-1];
            }
        }
    }
    return cps[0][n-1];
}
int main(){
    string str ="aaaa";
    int dp[1000][1000];
    memset(dp,-1,sizeof(dp));
    int ans =dp_solution_top_down(0,str.length()-1,str,dp);
    int ans2 =dp_solution_btm_up(str);
    cout<<ans2<<endl;
    cout<<ans<<endl;
}
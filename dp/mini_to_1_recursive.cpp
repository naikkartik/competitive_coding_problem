#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int min_step_1(int n,int dp[]){
    //base case 
    if(n==1){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int de_by1,de_by2,de_by3;
    de_by1 = de_by2=de_by3=INT_MAX;
    de_by1 = min_step_1(n-1,dp);
    if(n%2==0){
        de_by2= min_step_1(n/2,dp);
    }
    if(n%3==0){
        de_by3 = min_step_1(n/3,dp);
    }
    int ans = min(min(de_by1,de_by2),de_by3)+1;
    dp[n]=ans;
    return ans;
}
int main(){
    int n;
    cin>>n;
    int dp[100]={0};
    cout<<min_step_1(n,dp)<<endl;

}




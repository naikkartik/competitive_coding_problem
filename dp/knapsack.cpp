#include <bits/stdc++.h>
using namespace std;
int knapsack(int W,int wt[],int val[],int n,int dp[]){
    if(n==0 or W==0) return 0;
    if(dp[W]!=0){
        return dp[W];
    }
    if(wt[n-1]>W){
        return knapsack(W,wt,val,n-1,dp);
    }
    int x = knapsack(W-wt[n-1],wt,val,n-1,dp)+val[n-1];
    int y=knapsack(W,wt,val,n-1,dp);
    return dp[W]=max(x,y);
}
int dp_solution(int W,int wt[],int val[],int n){
    int i,w;
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int w<=W;w++){
            if(i==0 or w==0){
                dp[i][w] =0;
            }
            
        }
    }
}
int main(){
    int val[] ={60,100,120};
    int wt[] ={10,20,30};
    int W =50;
    int n=3;
    int dp[W]={0};
    cout<<knapsack(W,wt,val,n,dp)<<endl;
}
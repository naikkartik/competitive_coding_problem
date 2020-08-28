#include <bits/stdc++.h>
using namespace std;
int num_way_to_make_change(int n,int m,int S[]){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(n>0 and m<0) return 0;
    int count = num_way_to_make_change(n,m-1,S)+num_way_to_make_change(n-S[m],m,S);
    return count;
}
int dp_solution(int n,int m,int S[]){
    int dp[n+1][m];
    int x,y;
    for(int i=0;i<m;i++){
        dp[0][i] =1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            //using the current coin
            if(i-S[j]>=0){
                x = dp[i-S[j]][j];
            }
            else{
                x=0;
            }
            //without using the dp
            if(j>=1){
                y =dp[i][j-1];
            }
            else{
                y=0;
            }
            dp[i][j] = x+y;
        }
    }
    return dp[n][m-1];

}
int main(){
    int S[]={1, 2, 3};
    int m=3;
    int n =6;
    cout<<dp_solution(n,m,S)<<endl;
}
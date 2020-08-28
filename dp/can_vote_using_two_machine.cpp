#include <bits/stdc++.h>
using namespace std;

bool can_vote(int a[],int n,int x){
    //find the sum of the array 
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum<=x){
        return true;
    }
    int dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(a[i]<=j){
                dp[i][j] =max(dp[i-1][j],a[i]+dp[i-1][j-a[i]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    if(sum-dp[n][x]<=x){
        return true;
    }
    return false;
}

int main(){
    
    int n = 3, x = 4;
    int a[] = {2, 4, 12};
    can_vote(a, n, x)? cout << "YES\n" :
    cout << "NO\n";
    return 0;    

}
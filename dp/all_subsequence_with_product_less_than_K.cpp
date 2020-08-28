#include <bits/stdc++.h>
using namespace std; 
#include <bits/stdc++.h>
using namespace std; 

int total_count(int arr[],int n,int K){
    int dp[K+1][n+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=K;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] =dp[i][j-1];
            if(arr[j-1]<=i and arr[j-1]>0){
                dp[i][j]+=dp[i/arr[j-1]][j-1]+1;
            }
        }
    }
    return dp[K][n];
}
int main(){
    int arr[] ={1,2,3,4};
    int K =10;
    map<int,int>dp;
    int ans = total_count(arr,4,K);
    cout<<ans<<endl;
    return 0;
}


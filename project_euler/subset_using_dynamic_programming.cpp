#include <bits/stdc++.h>
using namespace std;
void printDistcur_sum(int arr[],int n){
    int cur_cur_sum = 0;
    for(int i=0;i<n;i++){
        cur_cur_sum+=arr[i];
    }
    int dp[n+1][cur_cur_sum+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        dp[i][arr[i-1]] = true;
        for(int j=0;j<=cur_sum;j++){
            if(dp[i-1][j]==true){
                dp[i][j]=true;
                dp[i][j+arr[i-1]]=true;
            }
        }
    }
    for(int i = 0;i<=cur_sum;i++){
        if(dp[n][i]==true){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printDistcur_sum(arr, n);
    return 0;
}

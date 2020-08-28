#include <bits/stdc++.h>
using namespace std; 

int dp_solution(int arr[],int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] =1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((arr[i]>arr[j]) and dp[i]<dp[j]+1){
                dp[i] =dp[j]+1;
            }
        }
    }
    return n-dp[n-1];
}

int main(){
    int arr[] = { 1, 2, 3, 5, 7, 11 };
    int n =6;
    cout<<dp_solution(arr,n)<<endl;
}
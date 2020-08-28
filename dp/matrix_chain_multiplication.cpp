#include <bits/stdc++.h>
using namespace std; 
int matrix_chain_multiplication(vector<int>&A){
    int dp[200][200];
    memset(dp,0,sizeof(dp));
    int n =A.size()-1;
    for(int i=1;i<n;i++){
        int r =0,c=i;
        while(c<n){
            int val =INT_MAX;
            for(int pivot =r;pivot<c;pivot++){
                val = min(val,dp[r][pivot]+dp[pivot+1][c]+A[r]*A[pivot+1]*A[c+1]);
            }
            dp[r][c] =val;
            c++,r++;
        }
    }
    return dp[0][n-1];
}
int matrix_chain_recursive(int arr[],int i,int j,int dp[][200]){
    //base case 
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int k;
    int min_ans =INT_MAX;
    int count;
    for(k=i;k<j;k++){
        count = matrix_chain_recursive(arr,i,k,dp)+matrix_chain_recursive(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
        min_ans = min(min_ans,count);
    }
    return dp[i][j]=min_ans;
}
int main(){
    int arr[] ={10, 20, 30, 40, 30,56,66,44,66,77,88,90};
    int n =sizeof(arr)/sizeof(arr[0]);
    vector<int>A;
    for(int i=0;i<n;i++){
        A.push_back(arr[i]);
    }
    int dp[200][200];
    memset(dp,-1,sizeof(dp));
    int ans =matrix_chain_multiplication(A);
    int ans2 =matrix_chain_recursive(arr,1,n-1,dp);
    cout<<ans2<<endl;
    cout<<ans<<endl;
    
}
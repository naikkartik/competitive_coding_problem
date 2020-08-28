#include <bits/stdc++.h>
using namespace std;
void solution(int cur_sum,int arr[],int n,map<int,int>&sum_dp){
    if(n==0){
        sum_dp[cur_sum] =1;
        return;
    }
    //including the current element 
    solution(cur_sum+arr[n-1],arr,n-1,sum_dp);
    //do not include the current element 
    solution(cur_sum,arr,n-1,sum_dp);

}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>sum_dp;
    solution(0,arr,n,sum_dp);
    for(auto it:sum_dp){
        cout<<it.first<<" ";
    }
    cout<<endl;
}

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

bool isPossible(int sum,int index,int K,int n,int arr[]){
    //base case 
    if(index+1==n){
        if(sum==K){
            return true;
        }
        return false;
    }
    bool negate = isPossible(sum-arr[index],index+1,K,n,arr);
    bool addIndex =isPossible(sum+index+1,index+1,K,n,arr);
    bool subIndex =isPossible(sum-index-1,index+1,K,n,arr);
    bool no_use =isPossible(sum,index+1,K,n,arr);
    if(negate or addIndex or subIndex or no_use){
        return true;
    }
    return false;
}
bool dp_solution(int sum,int index,int K,int n,int arr[],int dp[][MAX]){
    if(index+1==n){
        if(sum==K){
            return true;
        }
        return false;
    }
    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }
    bool negate = isPossible(sum-arr[index],index+1,K,n,arr);
    bool addIndex =isPossible(sum+index+1,index+1,K,n,arr);
    bool subIndex =isPossible(sum-index-1,index+1,K,n,arr);
    bool no_use =isPossible(sum,index+1,K,n,arr);
    if(negate or addIndex or subIndex or no_use){
        return dp[index][sum]=true;
    }
    return dp[index][sum]=false;
    
}
int main(){
    int N =3;
    int K=5;
    int arr[]={ 1, 2, 3, 4 };
    int sum =arr[0];
    int n = sizeof(arr)/sizeof(arr[0]);
    int dp[n][MAX];
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<n;i++){
        sum+=arr[i];
    }
    if(dp_solution(sum,0,K,n,arr,dp)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}

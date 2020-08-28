#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

bool isPossible(int index,int sum,int n,int m,int arr[]){
    //base case 
    if(index==n){
        if(sum%m==0){
            return true;
        }
        return false;
    }
    bool placeAdd = isPossible(index+1,sum+arr[index],n,m,arr);
    bool placeMinus=isPossible(index+1,sum-arr[index],n,m,arr);
    if(placeAdd or placeMinus){
        return true;
    }
    return false;
}
bool dp_solution(int index,int sum,int n,int m,int arr[],int dp[][MAX]){
    //base case
    if(index==n){
        if(sum%m==0){
            return 1;
        }
        return false;
    }
    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }
    bool placeAdd = dp_solution(index+1,sum+arr[index],n,m,arr,dp);
    bool placeMinus=dp_solution(index+1,sum-arr[index],n,m,arr,dp);
    if(placeAdd or placeMinus){
        return dp[index][sum]=true;
    }
    return dp[index][sum]=false;
}
//optimized dp solution 
bool dp_solution_modulo(int index,int modulo,int n,int m,int arr[],int dp[][MAX]){
    modulo = ((modulo % m) + m) % m;
    if(index==n){
        if(modulo==0){
            return true;
        }
        return false;
    }
    if(dp[index][modulo]!=-1){
        return dp[index][modulo];
    }
    bool placeAdd =dp_solution_modulo(index+1,modulo+arr[index],n,m,arr,dp);
    bool placeMinus=dp_solution_modulo(index+1,modulo-arr[index],n,m,arr,dp);
    if(placeAdd or placeMinus){
        return dp[index][modulo]=true;
    }
    return dp[index][modulo]=false;
}
int main(){
    int arr[] = { 1, 2, 3, 4, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int M = 4;
    int dp[n + 1][MAX];
    memset(dp, -1, sizeof(dp));
    bool res;
    res = dp_solution_modulo(0, 0, n, M, arr,dp);
    cout << (res ? "True" : "False") << endl;
    return 0;
}
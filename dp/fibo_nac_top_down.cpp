#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fib_dp(int n,int arr[]){
    if(n==0 or n==1){
        return n;
    }
    if(arr[n]!=0){
        return arr[n];
    }
    int ans =fib_dp(n-1,arr)+fib_dp(n-2,arr);
    arr[n]=ans;
    return ans;
}
int fib_BU(int n){
    int arr[100] ={0};
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}
int main(){
    int n;
    cin>>n;
    int arr[100]={0};
    cout<<fib_BU(n)<<endl;
    return 0;
}
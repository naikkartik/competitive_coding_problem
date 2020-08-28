#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int count_coin(int n,int m,int coins[],int current_coin){
    
}
int minimum_coin(int n,int m,int coins[],long long dp[]){
	//base case
	if(n==0){
		return 1;
	}
	int count =0;
	for(int i=0;i<m;i++){
		if((n-coins[i])>=0 and n!=coins[i]){
			int coin =count_coin(n-coins[i],m,coins,coins[i]);
			count+=coin;
		}
	}
	return count;
}
int main() {
	int n,m;
	cin>>n>>m;
	int arr[m];
	for(int i=0;i<m;i++){
		cin>>arr[i];
	}
	long long dp[1000]={0};
	cout<<minimum_coin(n,m,arr,dp)<<endl;

	return 0;
}
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool check_pallindrome(int start,int end,string str,map<pair<int,int>,bool>&dp){
	//base case
	if(start>end){
		return true;
	}
    if(dp.find(make_pair(start,end))!=dp.end()){
        return dp[make_pair(start,end)];
    }
	if(str[start]!=str[end]) return false;
	return dp[make_pair(start,end)]=check_pallindrome(start+1,end-1,str,dp);
}
int main () {
	int t;
	cin>>t;
	string str;
	cin>>str;
	int q;
	cin>>q;
    map<pair<int,int>,bool>dp;
	while(q--){
		int start,end;
		cin>>start>>end;

		if(check_pallindrome(start-1,end-1,str,dp)){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
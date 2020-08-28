#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<pair<int,int>,long long>dp;
        //initialize the dp
        dp[make_pair(1,0)]=1;
        dp[make_pair(1,1)]=1;
        for(int i=2;i<=n;i++){
            dp[make_pair(i,0)] = dp[make_pair(i-1,0)]+dp[make_pair(i-1,1)];
            dp[make_pair(i,1)] = dp[make_pair(i-1,0)];
        }
        cout<<(dp[make_pair(n,1)]+dp[make_pair(n,0)])<<endl;
    }
    return 0;
}
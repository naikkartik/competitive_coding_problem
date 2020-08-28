#include <bits/stdc++.h>
using namespace std;

int find_minimum_partition(int sum1,int sum2,int n,int arr[],map<pair<pair<int,int>,int>,int>&dp){
    if(n==0){
        return abs(sum1-sum2);
    }
    pair<pair<int,int>,int>tmp = make_pair(make_pair(sum1,sum2),n);
    if(dp.find(tmp)!=dp.end()){
        return dp[tmp];
    }
    int a = find_minimum_partition(sum1+arr[n-1],sum2,n-1,arr,dp);
    int b =find_minimum_partition(sum1,sum2+arr[n-1],n-1,arr,dp);
    return dp[tmp] = min(a,b);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        map<pair<pair<int,int>,int>,int>dp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans = find_minimum_partition(0,0,n,arr,dp);
        cout<<ans<<endl;
    }
}
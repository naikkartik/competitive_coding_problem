#include <bits/stdc++.h>
using namespace std; 
#define ll long long 

ll n,m,a[5005],b[5005],dp[5005][5005];

ll f(ll i,ll j){
    if(i==n){
        return 0;
    }
    if(j==m){
        return INT_MAX;
    }
    ll op1 =abs(a[i]-b[j])+f(i+1,j+1);
    ll op2 =f(i,j+1);
    return min(op1,op2);
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];

    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    ll ans =f(0,0);
    cout<<ans<<endl;
}
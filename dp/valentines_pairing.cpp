#include <bits/stdc++.h>
using namespace std; 

int pair_dp(int i,int j,int m,int n,int choco[],int candy[]){
    if(i==m){
        return 0;
    }
    if(j==n){
        return INT_MAX;
    }
    int op1 = abs(choco[i]-candy[j]) +pair_dp(i+1,j+1,m,n,choco,candy);
    int op2 =pair_dp(i,j+1,m,n,choco,candy);
    return min(op1,op2);
}

int main(){
    int m,n;
    cin>>m>>n;
    int choco[m];
    for(int i=0;i<m;i++){
        cin>>choco[i];
    }
    int candy[n];
    for(int j=0;j<n;j++){
        cin>>candy[j];
    }
    int ans = pair_dp(0,0,m,n,choco,candy);
    cout<<ans<<endl;
    return 0;
}

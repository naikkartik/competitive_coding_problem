#include <bits/stdc++.h>
using namespace std; 

int main(){
    int T;
    cin>>T;
    while(T--){
        int R,C;
        cin>>R>>C;
        int arr[R][C];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin>>arr[i][j];
            }
        }
        int dp[R][C];
        dp[0][0] =arr[0][0];
        for(int i=1;i<R;i++){
            dp[i][0]=dp[i-1][0]+arr[i][0];
        }
        for(int i=1;i<C;i++){
            dp[0][i]=dp[0][i-1]+arr[0][i];
        }
        for(int i=1;i<R;i++){
            for(int j=1;j<C;j++){
                if(abs(dp[i-1][j]+arr[i][j])<abs(dp[i][j-1]+arr[i][j])){
                    dp[i][j] =arr[i][j]+dp[i-1][j];
                }
                else{
                    dp[i][j] =arr[i][j]+dp[i][j-1];
                }
            }
        }
        int ans = dp[R-1][C-1];
        if(ans<0){
            cout<<(1-ans)<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[5][5] = {{ 0, 0, 0, -1, 0},
                    {-1, 0, 0, -1, -1},
                    { 0, 0, 0, -1, 0},
                    {-1, 0, -1, 0, 0},
                    { 0, 0, -1, 0, 0}};
        int m = 5;
        int n = 5;
        int dp[m][n];
        //initializing the rows 
        for(int i=0;i<m;i++){
            if(arr[i][0]==-1){
                for(int j=i;j<m;j++){
                    dp[j][0]=0;
                }
                break;
            }
            else{
                dp[i][0] =1;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[0][i]==-1){
                for(int j=i;j<n;j++){
                    dp[0][j]=0;
                }
                break;
            }
            else{
                dp[0][i] =1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(arr[i][j]==0 and (dp[i][j-1]==1 or dp[i-1][j])){
                    dp[i][j] =1;
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        cout<<dp[m-1][n-1]<<endl;
}
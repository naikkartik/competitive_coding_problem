#include <bits/stdc++.h>
using namespace std;

int coin_game_winner(int n,int x,int y){
    int dp[n+1];
    dp[0] =0;
    for(int i=1;i<=n;i++){
        int x_possible = 1;
        int y_possible =1;
        int possible_1 =1;
        if(i-x>=0){
            x_possible =dp[i-x];
        }
        if(i-y>=0){
            y_possible=dp[i-y];
        }
        if(i-1>=0){
            possible_1 =dp[i-1];
        }
        if(y_possible==0 or x_possible==0 or possible_1==0){
            dp[i] =1;
        }
        else{
            dp[i] =0;
        }
    }
    return dp[n];
}
bool findWinner(int x,int y,int n){
    int dp[n+1];
    dp[0] =0;
    dp[1] =1;
    for(int i=2;i<=n;i++){
        if(i-1>=0 and !dp[i-1]){
            dp[i] =true;
        }
        else if(i-x>=0 and !dp[i-x]){
            dp[i] =true;
        }
        else if(i-y>=0 and !dp[i-y]){
            dp[i] =true;
        }
        else{
            dp[i] =0;
        }
    }
    return dp[n];
}
int main(){
    int n =2;
    int x =3;
    int y =4;
    if(findWinner(n,x,y)){
        cout<<"A"<<endl;
    }
    else{
        cout<<"B"<<endl;
    }
    return 0;
}
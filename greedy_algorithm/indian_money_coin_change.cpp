#include <bits/stdc++.h>
using namespace std; 

int make_change(int *coins,int money,int n){
    int count =0;
    while(money>0){
        int idx =upper_bound(coins,coins+n,money)-1-coins;
        money-=coins[idx];
        count++;
        
    }
    return count;
}

int main(){
    int coins[] ={1,2,5,10,20,50,100,200,500,2000};
    int money;
    cin>>money;
    cout<<make_change(coins,money,10)<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int find_longest_sequence(int arr[],int n){
    map<int,int>dp;
    int count[n];
    for(int i=0;i<n;i++){
        count[i] =1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int diff = arr[i]-arr[j];
            if(dp.find(diff)==dp.end()){
                count[i]=max(count[i],2);
            }
            else{
                if(dp[diff]==arr[j]){
                    count[i]=max(count[i],count[j]+1);

                }
            }
            dp[diff]=arr[i];
        }
    }
    int high =count[0];
    for(int i=1;i<n;i++){
        high =max(high,count[i]);
    }
    return high;
}

int main(){
    int arr[] ={2, 4, 6, 8, 10};
    int ans =find_longest_sequence(arr,5);
    cout<<ans<<endl;
}

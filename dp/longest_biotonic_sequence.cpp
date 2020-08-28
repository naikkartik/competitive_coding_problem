#include <bits/stdc++.h>
using namespace std;

int biotonic_sequence(int arr[],int n){
    //increasing sequence
    int dp_inc[n];
    for(int i=0;i<n;i++){
        dp_inc[i] =1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] and dp_inc[i]<dp_inc[j]+1){
                dp_inc[i] =dp_inc[j]+1;
            }
        }
    }
    int dp_dec[n];
    for(int i=0;i<n;i++){
        dp_dec[i] =1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j] and dp_dec[i]<dp_dec[j]+1){
                dp_dec[i] =dp_dec[j]+1;
            }
        }
    }
    int ans =0;
    for(int i=0;i<n;i++){
        if(ans<dp_dec[i]+dp_inc[i]-1){
            ans=dp_dec[i]+dp_inc[i]-1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {80, 60, 30, 40, 20, 10};
    int n =6;
    cout<<biotonic_sequence(arr,n)<<endl;
    return 0;
}

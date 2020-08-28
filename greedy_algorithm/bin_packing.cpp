#include <bits/stdc++.h>
using namespace std; 

int min_bins(int arr[],int n,int bin_size){
    vector<int>bins;
    bins.push_back(bin_size-arr[0]);
    for(int i=1;i<n;i++){
        int cur_value = arr[i];
        int possible =-1;
        for(int j=0;j<bins.size();j++){
            if(bins[j]>=cur_value){
                bins[j]-=cur_value;
                possible=1;
                break;
            }
        }
        if(possible==-1){
            bins.push_back(bin_size-cur_value);
        }

    }
    return bins.size();
}

int main(){
    int n,bin_size;
    cin>>n>>bin_size;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans =min_bins(arr,n,bin_size);
    cout<<ans<<endl;
}
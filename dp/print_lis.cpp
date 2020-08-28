#include <bits/stdc++.h>
using namespace std ;

void printLIS(vector<int> &arr){
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

void constructLIS(int arr[],int n){
    vector<vector<int>>L(n);
    L[0].push_back(arr[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((arr[i]>arr[j]) and L[i].size()<L[j].size()+1){
                L[i] =L[j];
            }
            
        }
        L[i].push_back(arr[i]);
    }
    vector<int>max_result = L[0];
    for(auto x:L){
        if(x.size()>max_result.size()){
            max_result =x;
        }
    }
    printLIS(max_result);
}

int main()
{
    int arr[] = { 3, 2, 6, 4, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // construct and print LIS of arr
    constructLIS(arr, n);
    return 0;
}

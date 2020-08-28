#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lis(int arr[],int n){
    int *lis =(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        lis[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] and lis[i]<lis[j]+1){
                lis[i] = lis[j]+1;
            }
        }
    }
    int max =0;
    for(int i=0;i<n;i++){
        if(max<lis[i]) max = lis[i];
    }
    return max;
}
vector<int> construction_of_lis(int arr[],int n){
    vector<vector<int>>result;
    for(int i=0;i<n;i++){
        vector<int>temp;
        temp.push_back(arr[i]);
        result.push_back(temp);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] and result[i].size()<result[j].size()+1){
                vector<int>temp =result[j];
                temp.push_back(arr[i]);
                result[i] =temp;
            }
        }
    }
    int max_index =0;
    for(int i=1;i<result.size();i++){
        if(result[i].size()>result[max_index].size()){
            max_index =i;
        }
    }
    
    return result[max_index];
}
int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60,80 };
    int n =sizeof(arr)/sizeof(arr[0]);
    vector<int> result =construction_of_lis(arr,n);
    int max_length = lis(arr,n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    cout<<max_length<<endl;
}
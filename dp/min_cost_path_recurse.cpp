#include <bits/stdc++.h>
using namespace std;
int find_min_path(vector<vector<int>>arr,int m,int n){
    if(m<0 or n<0) return INT_MAX;
    if(m==0 and n==0){
        return arr[m][n];
    }
    return arr[m][n]+min(
        find_min_path(arr,m-1,n),
        min(
            find_min_path(arr,m,n-1),
            find_min_path(arr,m-1,n-1)
        )
    );
}

int main(){
    vector<vector<int>>arr;
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            int value;
            cin>>value;
            temp.push_back(value);
        }
        arr.push_back(temp);
    }
    cout<<find_min_path(arr,m-1,n-1)<<endl;
}
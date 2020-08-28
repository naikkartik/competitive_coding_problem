#include <bits/stdc++.h>
using namespace std;
int find_min_path(int **arr,int m,int n,int a,int b){
    //first do a recursive solutions ,then go for iteratives
    int cost = arr[0][0];
    int i=0;
    int j=0;
    while(i<a and j<b){
        //find min_cost
        if(arr[i][j+1]<arr[i+1][j] and arr[i][j+1]<arr[i+1][j+1]){
            cost+=arr[i][j+1];
            j++;
        }
        else if(arr[i+1][j]<arr[i][j+1] and arr[i+1][j]<arr[i+1][j+1]){
            cost+=arr[i+1][j];
            i++;
        }
        else{
            cost+=arr[i+1][j+1];
            i++;
            j++;
        }
        
    }
    return cost;
}
int main(){
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int a,b;
    cin>>a>>b;
    cout<<find_min_path(arr,m,n,a,b)<<endl;
}
#include <bits/stdc++.h>
using namespace std; 

bool arithmeticThree(int arr[],int n){
    for(int j=1;j<n-1;j++){
        int i=j-1;
        int k =j+1;
        while(i>=0 and k<n-1){
            if(arr[i]+arr[k]==2*arr[j]){
                return true;
            }
            if(arr[i]+arr[k]<2*arr[j]){
                k++;
            }
            else{
                i--;
            }
        }
    }
    return false;
}
int main(){
    int arr[] ={}
}
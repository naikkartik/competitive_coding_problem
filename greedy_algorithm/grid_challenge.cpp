#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            sort(arr[i].begin(),arr[i].end());
        }
        int k=0;
        int check =-1;
        for(int i=0;i<arr[0].length();i++){
            for(int j=1;j<n;j++){
                if(arr[j][i]<arr[j-1][i]){
                    check=1;
                    cout<<"NO"<<endl;
                    break;
                }
                
            }
            if(check==1){
                    break;
                }
        }
        if(check==-1){
            cout<<"YES"<<endl;
        }
    }
}
#include <bits/stdc++.h>
using namespace std; 

int winner_find(int arr[],int n,int k){
    //base condition 
    if(n<=k){
        return n;
    }
    int i =0;
    int j=1;
    int winner =arr[i]>arr[j]?i:j;
    int winner_count =1;
    int prev_winner =-1;
    int l =2;
    while(winner_count<=k){
        //find the new winner and update the counter
        if(arr[l]<arr[winner]){
            winner_count+=1;
        }
        else{
            winner =l;
            winner_count =1;
        }
        l =(l+1)%n;
    }
    return arr[winner];
}
int gfg_solution(int a[],int n,int k){
    if(k>=n-1){
        return n;
    }
    int best =0;
    int times =0;
    for(int i=0;i<n;i++){
        if(a[i]>best){
            best =a[i];
            if(i){
                times =1;
            }
        }
        else{
            times+=1;
        }
        if(times>=k){
            return best;
        }

    }
    return best;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int winner =winner_find(arr,n,k);
    cout<<winner<<endl;
    return 0;
}
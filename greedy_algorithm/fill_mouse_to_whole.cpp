#include <bits/stdc++.h>
using namespace std;
int min_time_to_fill(int mouse[],int holes[],int n){
    //sort both the array 
    sort(mouse,mouse+n);
    sort(holes,holes+n);
    int max_time =-1;
    for(int i=0;i<n;i++){
        max_time =max(max_time,abs(mouse[i]-holes[i]));
    }
    return max_time;
}
int main(){
    int n;
    cin>>n;
    int mouse[n],holes[n];
    for(int i=0;i<n;i++){
        cin>>mouse[i];
    }
    for(int i=0;i<n;i++){
        cin>>holes[i];
    }
    int ans = min_time_to_fill(mouse,holes,n);
    cout<<ans<<endl;
}

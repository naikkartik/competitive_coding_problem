#include <bits/stdc++.h>
using namespace std;
int solution(int n,int arr[],int target){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=arr[i];
    }
    for(int i=0;i<n-2;i++){
        int lo = i+1;
        int hi = n-1;
        while(lo<hi){
            int sum =arr[lo]+arr[hi]+arr[i];
            if(ans>abs(sum-target)){
                ans = sum;
                if(ans==target){
                    return ans;
                }
            } 
            if(target<sum){
                hi--;

            }
            else{
                lo++;
            }
        }
    }
    return ans;
}
int main(){
    int n;
    int target;
    cin>>target;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = solution(n,arr,target);
    cout<<ans<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int maxWeightRec(int wt[],int val[],int K,map<pair<int, int>,int>&mp,int last,int diff){
    if(last<=-1){
        if(diff==0){
            return 0;
        }
        return INT_MIN;
    }
    pair<int,int>tmp =make_pair(last,diff);
    if(mp.find(tmp)!=mp.end()){
        return mp[tmp];
    }
    int include_current = wt[last]+maxWeightRec(wt,val,K,mp,last-1,diff+wt[last]-K*val[last]);
    int donot_include_current =maxWeightRec(wt,val,K,mp,last-1,diff);
    return mp[tmp]=max(include_current,donot_include_current);
}
int maxWeight(int wt[],int val[],int K,int N){
    map<pair<int, int>, int> mp;
    return maxWeightRec(wt,val,K,mp,N-1,0);
}
int main(){
    int wt[] ={4,8,9};
    int val[]={2,4,6};
    int N = sizeof(wt)/sizeof(int);
    int K =2;
    cout<<maxWeight(wt,val,K,N)<<endl;
}

